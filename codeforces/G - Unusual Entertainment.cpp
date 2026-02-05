#include <bits/stdc++.h>
///#define int long long
#define mid (l+r)/2
#define lc 2*node
#define rc 2*node+1
#define all(x) x.begin(),x.end()
#define endl '\n'

using namespace std;

const int NN = 1e5+5;
const int inf = 1e6+5;
int tc=1;
int n,q;
int arr[NN];
int perm[NN];
int in[NN] , out[NN];
vector<int> segt[4*NN];
vector<int> adj[NN];

void build(int node=1 , int l=1 , int r=n)
{
    if (l > r) return;
    if (l==r)
    {
        segt[node] = vector<int>(1,arr[r]);
        return;
    }
    build(lc , l , mid);
    build(rc , mid+1 , r);
    merge
        ( all(segt[lc]) ,
          all(segt[rc]) ,
          back_inserter(segt[node])
        );
    return;
}


int query (int node , int l ,int r , int st , int en  , int val)
{
    if (l>r or st>r or en<l or en<st) return inf;
    if (l>=st and en>=r)
    {
        auto idx = lower_bound(all(segt[node]) , val);
        return (idx == segt[node].end() ? inf : *idx);
    }
    int p1 = query(lc , l , mid , st , en , val);
    int p2 = query(rc , mid+1 , r , st , en , val);
    return min(p1,p2);
}

void dfs(int src, int parent , int& timer)
{
    in[src] = ++timer;

    for (int& child : adj[src])
    {
        if (child == parent) continue;
        dfs(child , src , timer);
    }

    out[src] = timer;
    return;
}

void solve()
{
    int tt=0;
    dfs(1,0,tt);
    for (int i=1 ; i<=n  ; i++) arr[i] = in[perm[i]];

    build();

    while(q--)
    {
        int l , r ,x;
        cin >> l >> r >> x;

        int ub = query(1,1,n, l , r , in[x]);

        if (ub>out[x] or ub<in[x])
        {
            cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }
    cout << endl;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n >> q;
        for (int i=0 ; i<=n ; i++) adj[i].clear();
        for (int i=0 ; i<=4*n+3 ; i++) segt[i].clear();

        for (int i=1 ; i<n ; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i=1 ; i<=n ; i++) cin >> perm[i];

        solve();
    }
    return 0;
}
