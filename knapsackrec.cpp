#include <bits/stdc++.h>
using namespace std;
int knapsack(int v[], int w[], int W, int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (w[n - 1] > W)
    {
        return knapsack(v, w, W, n - 1);
    }
    else
    {
        return max(knapsack(v, w, W, n - 1), v[n - 1] + knapsack(v, w, W - w[n - 1], n - 1));
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
    cout << knapsack(v, w, W, n);
}