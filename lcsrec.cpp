#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int n, int m)
{
    // empty string
    if (m == 0 || n == 0)
        return 0;
    if (s1[n - 1] == s2[m - 1])
        return 1 + lcs(s1, s2, n - 1, m - 1);
    else
    {
        return max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
    }
}

int main()
{

    string s1 = "AXYZ", s2 = "BAZ";

    int n = 4, m = 3;

    cout << lcs(s1, s2, n, m);
}