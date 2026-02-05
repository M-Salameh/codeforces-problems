#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int inf = 2e18+8;
const int NN = 1e5+5;
int n , tc=1;
int m,c;
int ans;
vector<int> adj[NN];
int subtree_size[NN];

void solve()
{

}

void dfs(int node=1 , int parent=0)
{
    subtree_size[node] = 1;
    for (int& child : adj[node])
    {
        if (child == parent) continue;
        dfs(child , node);
        subtree_size[node] += subtree_size[child];
    }

    int temp = subtree_size[node]*subtree_size[node];
    temp += (n-subtree_size[node])*(n-subtree_size[node]);

    ans = min (ans , temp);
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m >> c;
        for (int i=0 ; i<=n ; i++)
        {
            adj[i].clear();
        }
        for (int i=1 ; i<n ;i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans = inf;
        dfs();
        cout << ans << endl;
    }

    return 0;
}
