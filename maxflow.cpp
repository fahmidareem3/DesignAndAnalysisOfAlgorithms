#include <bits/stdc++.h>
using namespace std;

long long int capacity[501][501];
vector<vector<long long int>> adj(501);
long long int INF = 1000000007;
long long int n, m;

long long int bfs(long long int s, long long int t, vector<long long int> &parent)
{
    fill(parent.begin(), parent.end(), -1);

    parent[s] = -2;

    queue<pair<long long int, long long int>> q;
    q.push({s, INF});

    while (!q.empty())
    {
        long long int cur = q.front().first;
        long long int flow = q.front().second;
        q.pop();

        for (long long int next : adj[cur])
        {
            // cout<<cur<<" "<<next<<" "<<capacity[cur][next]<<endl;
            if (parent[next] == -1 && capacity[cur][next] > 0)
            {
                parent[next] = cur;
                long long int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                {
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

long long int maxFlow(long long int s, long long int t)
{
    long long int flow = 0;
    vector<long long int> parent(n + 1);
    long long int new_flow;

    while (new_flow = bfs(s, t, parent))
    {
        flow += new_flow;
        int cur = t;

        while (cur != s)
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long int a, b, c, i, j;
    cin >> n >> m;

    memset(capacity, 0, sizeof(capacity));

    for (i = 0; i < m; i = i + 1)
    {
        cin >> a >> b >> c;
        capacity[a][b] = c;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << maxFlow(1, n) << endl;
}
