#include <bits/stdc++.h>
using namespace std;
int lis(int arr[], int n, int idx, int prev)
{
    if (idx == n)
        return 0;
    int len = 0 + lis(arr, n, idx + 1, prev);
    // prev == -1 meaning taking the first element
    if (prev == -1 || arr[idx] > arr[prev])
    {
        len = max(len, 1 + lis(arr, n, idx + 1, idx));
    }
    return len;
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
    cout << lis(arr, n, 0, -1);
}