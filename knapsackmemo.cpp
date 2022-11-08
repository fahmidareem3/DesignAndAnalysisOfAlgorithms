#include <bits/stdc++.h>
using namespace std;
int knapsack(int v[], int w[], int W, int n, vector<vector<int>> &dp)
{
    if (n < 0)
        return 0;
    if (dp[n][W] != -1)
        return dp[n][W];
    else if (w[n] > W)
    {
        dp[n][W] = knapsack(v, w, W, n - 1, dp);
        return dp[n][W];
    }
    else
    {
        dp[n][W] = max(knapsack(v, w, W, n - 1, dp), v[n] + knapsack(v, w, W - w[n], n - 1, dp));
        return dp[n][W];
    }
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