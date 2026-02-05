#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n;

bool visited[105]={false};

int graph[105][105]={0};

int u,v,c;

int dfs(int src)
{
    int cmp = 0;
    if (!visited[src])
    {
        visited[src] = true;
        for (int i=1 ;i<=n ; i++)
        {
            if (graph[src][i] && !visited[i])
            {
                cmp = max (cmp , graph[src][i] + dfs(i));
            }
        }
        return cmp;
    }
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n ;
    for (int i=1 ;i<n ; i++)
    {
        cin >> u >> v >> c ;
        u++,v++;
        graph[u][v] = graph[v][u] = c;

    }
    cout << dfs(1) << endl;

    return 0;
}
