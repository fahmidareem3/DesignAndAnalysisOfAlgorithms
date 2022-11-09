#include <bits/stdc++.h>
using namespace std;
int mcm(int a[], int n)
{
    int dp[n][n];
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = (a[i - 1] * a[k] * a[j]) + dp[i][k] + dp[k + 1][j];
                if (steps < mini)
                {
                    mini = steps;
                }
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n - 1];
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }
    cout << mcm(arr, n);
}