#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int inf = 1e15+8;
const int NN = 1e5+5;
const int Level = 30;
vector<int> adj[NN];
vector<int> sub_tree_size;
vector<int> depth;
vector<int> parent[Level+10];
int in[NN] , tim = 0;
int out[NN];
set<pair<int,int>> pos[NN];

int n,q , tc=1;

void reset()
{
    for (int i=0 ; i<=n ; i++)
    {
        adj[i].clear();
        pos[i].clear();
    }
    for (int i=0 ; i<Level+10 ; i++) parent[i] = vector<int> (n+1,0);
    depth = vector<int> (n+1 , 0);
    sub_tree_size = vector<int> (n+1 , 0);
}


void dfs(int node , int father)
{
    depth[node] = depth[father]+1;
    parent[0][node] = father;
    sub_tree_size[node] = 1;
    in[node] = ++tim;

    for (auto child : adj[node])
    {
        if(child == father) continue;
        dfs(child , node);
        sub_tree_size[node] += sub_tree_size[child];
    }
    out[node] = tim;
}


int go_up(int node , int diff)
{
    for(int i=0; i<=Level ; i++)
    {
        int temp = (1LL<<i);
        if (diff & temp)
        {
            node = parent[i][node];
        }
    }
    return node;
}

void sparse_matrix()
{
    for (int i=1 ; i <= Level ; i++)
    {
        for (int j=0 ; j<=n ; j++)
        {
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }
}

int LCA(int u,int v)
{
    if (u==v) return v;

    if(depth[u] < depth[v]) swap(u,v);

    u = go_up(u , depth[u]-depth[v]);

    if(u == v) return u;

    for(int i = Level ; i>=0 ; i--)
    {
        if (parent[i][u] == parent[i][v]) continue;
        u = parent[i][u];
        v = parent[i][v];
    }

    return parent[0][u];

}

/**
1
6 1
1 1 2 2 3
6 4 4

1
7 1
1 1 2 2 3 3
3 2 7
*/

void solve()
{
    tim  = 0;
    dfs(1,1);

    sparse_matrix();

    for (int i=1 ; i<=n ; i++)
    {
        for (int child : adj[i])
        {
            if (child == parent[0][i]) continue;
            pos[i].insert({out[child] , child});
        }
    }

    while(q--)
    {
        int v,x,u;
        cin >> v >> x >> u;
        int lca = LCA(u,v);

        if (in[v] <= in[u])
        {
            if (x < in[u]-in[lca]+1)
            {
                cout << "NO" << endl;
            }

            else cout << "YES" << endl;
        }
        else
        {
            auto it = pos[lca].lower_bound({out[v],0});
            int temp = sub_tree_size[it->second];
            temp += (in[u] - in[lca] + 1);
            if (x >= temp)
            {
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n >> q;
        reset();
        for (int i=2 ; i<=n ;i++)
        {
            int p;
            cin >> p;
            adj[p].push_back(i);
            adj[i].push_back(p);
        }

        solve();
    }

    return 0;
}
