#include <bits/stdc++.h>
#define int long long
///#define endl '\n'

using namespace std;

const int NN = 2e5+5;
const int inf = 1e6+5;
int tc=1;
int n,m;
vector<int> adj[NN];
int dp[NN];
int val[NN];
int ans[NN];

set<int> ms;

void dfs(int node=1 , int parent = 0)
{
    auto it = ms.lower_bound(val[node]);
    int x = 0;
    ans[node] = ms.size() + (it == ms.end());
    if (it == ms.end())
    {
        ms.insert(val[node]);
    }
    else
    {
        x = *it;
        ms.erase(it);
        ms.insert(val[node]);
    }

    for (int& child : adj[node])
    {
        if (child == parent) continue;
        dfs (child , node);
    }
    ms.erase(val[node]);
    if(x) ms.insert(x);

}



signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ///cin >> tc;
    while(tc--)
    {
        ans[0] = 1;
        cin >> n;
        for (int i=2 ; i<=n ; i++)
        {
            int u;
            cin >> u;
            adj[u].push_back(i);
            adj[i].push_back(u);
        }
        for (int i=1 ; i<=n ; i++)
        {
            cin >> val[i];
        }
        dfs();
        for (int i=2 ; i<=n ; i++) cout << ans[i] << " ";


    }
    return 0;
}
