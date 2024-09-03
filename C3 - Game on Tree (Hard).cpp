#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int inf = 2e18+8;
const int NN = 2e5+5;
int n , tc=1 , t;
int sum[NN][2];
bool ans[NN];
vector<int> adj[NN];
int parent[NN];
string HH = "Hermione";
string RR = "Ron";

void dfs1(int node=1 , int father = 0)
{
    parent[node] = father;
    for (int& child : adj[node])
    {
        if (child == father) continue;
        dfs1(child , node);
        sum[node][0] += (sum[child][0] == 0);
    }
}

void dfs2(int node=1 , int father = 0)
{
    for (int& child : adj[node])
    {
        if (child == father) continue;

        if (sum[node][1]) sum[child][1] = 0;

        else if (sum[node][0]==1 and sum[child][0]>0) sum[child][1] = 0;

        else if (sum[node][0] > 1) sum[child][1] = 0;

        else sum[child][1] = 1 ;

        dfs2(child,node);
    }
}

void dfs()
{
    dfs1();
    dfs2();
}

void solve()
{

    dfs();

    while(t--)
    {
        int node;
        cin >> node;
        if (sum[node][0] or sum[node][1]) cout << RR << endl;
        else cout << HH << endl;
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ///cin >> tc;
    while(tc--)
    {
        cin >> n >> t ;
        for (int i=1 ; i<n ; i++)
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
