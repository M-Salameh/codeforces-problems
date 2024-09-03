//https://codeforces.com/gym/105020/problem/L
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int NN = 1e5 + 5;
const int inf = 1e10;
vector<int> adj[NN];
int parent[NN],val[NN];
bool color[NN];
map<int,int> freq;
int ans[NN];
int tc=1;
int n,q;

void dfs(int node=1, int father=0)
{
    parent[node] = father;

    val[node] = val[father] - !color[node] + color[node];

    int pre_freq = freq[val[father]];

    freq[val[node]]++;

    for(auto u : adj[node])
    {
        if(u == father) continue;
        dfs(u, node);
    }

    ans[node] = freq[val[father]] - pre_freq;
}


void solve()
{
    dfs();
    while(q--)
    {
        int node;
        cin >> node;
        cout << ans[node] << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ///cin >> tc;
    while(tc--)
    {
        cin >> n >> q;

        for(int i=0 ; i<=n ; i++)
        {
            adj[i].clear();
            val[i] = parent[i] = 0;
        }
        for(int i=1 ; i<=n ; i++)
        {
            cin >> color[i];
        }
        for(int i=1 ; i<n ; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        solve();
    }
    return 0;
}
