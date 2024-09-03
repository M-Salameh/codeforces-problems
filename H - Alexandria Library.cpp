///https://codeforces.com/gym/104147/problem/H
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#include <math.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define pi pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin()+1,x.end()
#define all0(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define ll unsigned long long
#define int long long
#define double long double
#define endl '\n'
#pragma once
using namespace std;
using namespace __gnu_pbds;

int tc = 1;
int n , q;
const int inf = 1e15+8;
const int Level = 30;
vector<int> adj[500500];
vector<int> sub_tree_size;
vector<int> depth;
vector<int> parent[Level+10];


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


int dfs(int node , int father)
{
    depth[node] = depth[father]+1;
    parent[0][node] = father;
    sub_tree_size[node] = 1;

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
    for (int i=1 ; i<= Level ; i++)
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

    u = half_way(u , depth[u]-depth[v]);

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

void solve()
{
    dfs(1,1);
    sparse_matrix();

    while(q--)
    {
        int u , v;
        cin >> u >> v;
        int distt = dist(u,v);
        if (distt&1)
        {
            cout << 0 << endl;
            continue;
        }
        int lca = LCA(u , v);

        int middle = go_up(depth[u]>depth[v]?u:v , distt/2);

        int ans = 1;
        for(auto child : adj[middle])
        {
            int leftt = LCA(child , u);
            int rightt = LCA (child , v);

            if(leftt!=child and rightt!=child and parent[0][child]==middle)
            {
                ans += sub_tree_size[child];
            }
        }
        cout << ans + (sub_tree_size[1]-sub_tree_size[lca])*(lca==middle) << endl;
    }
}


signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> q;
        reset();
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
