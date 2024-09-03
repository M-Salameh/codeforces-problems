///https://codeforces.com/gym/104805/problem/C
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int mod = 1e9+7;
const int inf = 1e15+8;
const int Level = 25;
const int NN = 300300;
vector<int> adj[NN];
vector<int> sub_tree_size;
vector<int> depth;
vector<int> parent[Level+10];
map <pair<int,int> , int> weight;
int ans[NN];
int n ,q;

void reset()
{
    for (int i=0 ; i<=n ; i++)
    {
        adj[i].clear();
    }
    for (int i=0 ; i<Level+10 ; i++) parent[i] = vector<int> (n+1,0);
    depth = vector<int> (n+1 , 0);
    sub_tree_size = vector<int> (n+1 , 0);
}

void modo(int& a)
{
    a %= mod;
    if (a<0) a+=mod;
}

int mult(int& a , int&b)
{
    modo(a); modo(b);
    int c = a*b;
    modo(c);
    return c;
}

int dfs(int node , int father)
{
    depth[node] = depth[father]+1;
    parent[0][node] = father;
    sub_tree_size[node] = 1;

    ans[node] = mult(ans[father] , weight[{father,node}]);

    for (auto child : adj[node])
    {
        if(child == father) continue;
        sub_tree_size[node] += dfs(child , node);
    }
    return sub_tree_size[node];
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

int dist(int u , int v)
{
    int lca = LCA (u , v);
    int x = depth[u] + depth[v] - 2*depth[lca];
    return x;
}

int power(int a , int b)
{
    if (b==0) return 1;
    if (b==1) return a;
    int res = power(a,b/2);
    modo(res);
    res = (res*res) % mod;
    if (b&1) res = (a*res)%mod;
    modo(res);
    return res;
}

void solve()
{
    ans[1] = 1;
    weight[{1,1}] = 1;
    dfs(1,1);
    sparse_matrix();

    cin >> q;
    while(q--)
    {
        int u,v;
        cin >> u >> v;
        int lca = LCA(u,v);

        int temp = mult(ans[u] , ans[v]);
        int temp2 = mult(ans[lca] , ans[lca]);

        temp2 = power(temp2 , mod-2);

        temp = mult(temp,temp2);

        cout << temp << endl;


    }

}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n ;
    reset();
    for (int i=1 ; i<n ; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        weight[{u,v}] = w;
        swap(u,v);
        adj[u].push_back(v);
        weight[{u,v}] = w;
    }
    solve();
    return 0;
}

