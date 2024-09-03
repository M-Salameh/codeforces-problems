#include <bits/stdc++.h>

using namespace std;

const int NN = 1e5+5;

vector<int> adj[NN];

bool visited[NN];
int dp[NN];

int n,m;

int dfs(int src)
{
    if (visited[src]) return dp[src];
    visited[src] = true;
    int ans = 0;
    for (auto i : adj[src])
    {
        ans= max (ans , dfs(i));
    }
    return dp[src]=ans+1;

}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i=1 ; i<=m ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i=1 ; i<=n  ; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    int ans=0;
    for (int i=0 ; i<=n  ; i++)
    {
        ans = max (ans ,  dp[i]);
    }
    cout << ans-1 << endl;
    return 0;
}
