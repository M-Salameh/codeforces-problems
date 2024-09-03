#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int NN = 200200;
const int inf = 1e10;
vector<int> adj[NN];
int parent[NN];
int dist[NN];
int tc = 1;
int n;
int a,b;

void dfs(int node , int fa , int& temp)
{
    dist[node] = dist[fa] + 1;
    parent[node] = fa;
    temp = max(temp , dist[node]);
    for (auto i : adj[node])
    {
        if (i == fa) continue;
        dfs(i,node,temp);
    }
}

void solve()
{
    dist[0] = -1;
    int temp = -inf;
    dfs(a,0 , temp);
    int half = 0 , y=b;

    while(true)
    {
        if (half < dist[y])
        {
            half++ , y=parent[y];
            continue;
        }
        break;
    }

    temp = -inf;
    dfs(y,0 , temp);

    int ans = 2*(n-1) + half - temp;

    cout << ans << endl;
}


signed main()
{

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        for (int i=0 ; i<=n ; i++)
        {
            adj[i].clear();
            dist[i] = 0;
            parent[i] = 0;
        }
        cin >> a >> b;
        for (int i=1 ; i<n ; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            swap(u,v);
            adj[u].push_back(v);
        }
        solve();
    }
    return 0;
}
