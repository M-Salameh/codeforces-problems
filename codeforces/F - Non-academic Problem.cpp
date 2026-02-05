#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int inf = 2e18+8;
const int NN = 1e5+5;
int n , tc=1;
int m , timer;

vector <int> adj[NN];
bool visited[NN];
int in[NN] , low[NN];
vector<pair<int,int>> bridges;
int sizee[NN];

void dfs(int node = 1, int parent = 0)
{
    visited[node] = true;
    in[node] = low[node] = ++timer;
    sizee[node] = 1;

    bool parent_skipped = false;

    for (int& child : adj[node])
    {
        if (child == parent and not parent_skipped)
        {
            parent_skipped = true;
            continue;
        }
        if (visited[child])
        {
            low[node] = min(low[node], in[child]);
        }
        else
        {
            dfs(child, node);
            sizee[node] += sizee[child];
            low[node] = min(low[node], low[child]);
            if (low[child] > in[node])
            {
                bridges.push_back({node , child});
            }
        }
    }
}

void find_bridges()
{
    bridges.clear();
    for (int i=1 ; i<=n  ; i++) in[i] = low[i] = -1;

    for (int i = 1 ; i <= n; i++)
    {
        if (not visited[i]) dfs(i);
    }
}


void solve()
{
    timer = 0;
    find_bridges();

    int ans = ((n-1)*n)/2;

    for (auto& [from , to] : bridges)
    {
        int temp = (n-sizee[to])*(n-sizee[to]-1);
        temp += (sizee[to]*(sizee[to]-1));
        temp /= 2;

        ans = min (ans , temp);
    }

    cout << ans << endl;

}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        for (int i=0 ; i<=n ; i++)
        {
            adj[i].clear();
            visited[i] = false;
        }

        for (int i=1 ; i<=m  ; i++)
        {
            int u , v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve();
    }

    return 0;
}
