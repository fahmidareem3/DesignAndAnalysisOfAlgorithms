#include <bits/stdc++.h>
using namespace std;
void printpath(vector<vector<int>> dp, int n, int W, int w[], int v[])
{
    vector<int> temp;
    int i = n, j = W;
    while (i > 0 && j > 0)
    {
        if (dp[i - 1][j] == dp[i][j])
        {
            i--;
        }
        else
        {
            temp.push_back(w[i - 1]);
            j = j - w[i - 1];
            i--;
        }
    }
    reverse(temp.begin(), temp.end());
    for (auto it : temp)
    {
        cout << it << " ";
    }
    cout << "\n";
}
int knapsack(int v[], int w[], int W, int n, vector<vector<int>> &dp)
{
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= W; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (w[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
            }
        }
    }
    printpath(dp, n, W, w, v);
    return dp[n][W];
}

int main()
{
    int n;
    cin >> n;
    int v[n], w[n];
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v[i] = a;
    }
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        w[i] = b;
    }
    int W;
    cin >> W;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    cout << knapsack(v, w, W, n, dp);
}