#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2)
{
    int m = s1.length(), n = s2.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;

    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;
    int i, j;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    stack<char> st;
    i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            st.push(s1[i - 1]);
            i--;
            j--;
        }

        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
            j--;
    }

    while (st.empty() == false)
    {
        cout << st.top();
        st.pop();
    }
    cout << "\n";
    return dp[m][n];
}

int main()
{

    string s1;
    string s2;
    cin >> s1;
    cin >> s2;

    cout << lcs(s1, s2);
}