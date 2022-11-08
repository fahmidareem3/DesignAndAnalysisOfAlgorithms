#include <bits/stdc++.h>
using namespace std;
int mcm(int arr[], int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = (arr[i - 1] * arr[k] * arr[j]) + mcm(arr, i, k, dp) + mcm(arr, k + 1, j, dp);
        if (steps < mini)
        {
            mini = steps;
        }
    }
    return dp[i][j] = mini;
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
    cout << mcm(arr, 1, n - 1, dp);
}