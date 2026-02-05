#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int NN = 5e5+5;
const int inf = 8e18;
int tc = 1;
int n;
vector<int> adj[NN];
int dp[23][NN];
int arr[NN];

void dfs(int node = 1 , int parent = 0)
{
    for (int i=1 ; i<23 ; i++) dp[i][node] = i*arr[node];

    for (int child : adj[node])
    {
        if (child == parent) continue;
        dfs(child , node);
        for (int i=1 ; i<23 ; i++)
        {
            int temp = inf;
            for (int j=1 ; j<23 ; j++)
            {
                if (i == j) continue;
                temp = min (temp , dp[j][child]);
            }
            dp[i][node] += temp;
        }
    }
}

void solve()
{
    dfs();
    int ans = inf;
    for (int i=1 ; i<23 ; i++) ans = min (ans , dp[i][1]);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
            adj[i].clear();
            for (int j=0 ; j<23 ; j++)
            {
                dp[j][i] = 0;
            }
        }
        for (int i=1 ; i < n ; i++)
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
