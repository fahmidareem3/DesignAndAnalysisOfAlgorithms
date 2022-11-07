#include <bits/stdc++.h>
using namespace std;
int lis(int arr[], int n, int idx, int prev, vector<vector<int>> &dp)
{
    if (idx == n)
        return 0;
    if (dp[idx][prev + 1] != -1)
        return dp[idx][prev + 1];
    dp[idx][prev + 1] = 0 + lis(arr, n, idx + 1, prev, dp);
    // prev == -1 meaning taking the first element
    if (prev == -1 || arr[idx] > arr[prev])
    {
        dp[idx][prev + 1] = max(dp[idx][prev + 1], 1 + lis(arr, n, idx + 1, idx, dp));
    }
    return dp[idx][prev + 1];
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }
    cout << lis(arr, n, 0, -1, dp);
}