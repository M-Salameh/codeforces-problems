#include <bits/stdc++.h>
#define int long long
//#define endl '\n'

using namespace std;

const int inf = 2e18+8;
const int NN = 2e5+5;
int n , tc=1;
int m;
vector<int> adj[NN];
int sub[NN];
int arr[NN] , ans[NN] , depth[NN];
int res;
int sum;

void dfs(int node=1 , int parent=0)
{
    sub[node] = arr[node];
    depth[node] = 1 + depth[parent];
    for (int& child : adj[node])
    {
        if (child == parent) continue;
        dfs(child , node);
        sub[node] += sub[child];
    }

}

void dfsdp(int node=1 , int parent = 0)
{
    if (node != 1)
    {
        ans[node] = ans[parent] + sum - 2*sub[node] ;
        res = max(res , ans[node]);
    }
    for (int& child : adj[node])
    {
        if (child == parent) continue;
        dfsdp(child , node);
    }
}


void solve()
{
    depth[0] = -1;
    dfs();
    ans[1] = 0;

    for (int i=1 ; i<=n ; i++) ans[1] += depth[i]*arr[i];

    res = ans[1];

    dfsdp();

    cout << res << endl;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ///cin >> tc;
    while(tc--)
    {
        cin >> n ;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        for (int i=1 ; i<n ;i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve();
    }

    return 0;
}
