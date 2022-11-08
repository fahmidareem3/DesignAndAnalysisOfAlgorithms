#include <bits/stdc++.h>
using namespace std;
int mcm(int arr[], int i, int j)
{
    if (i == j)
        return 0;
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = (arr[i - 1] * arr[k] * arr[j]) + mcm(arr, i, k) + mcm(arr, k + 1, j);
        if (steps < mini)
        {
            mini = steps;
        }
    }
    return mini;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }
    cout << mcm(arr, 1, n - 1);
}