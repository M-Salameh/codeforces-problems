#include <bits/stdc++.h>
///#define int long long
#define mid (l+r)/2
#define lc 2*node
#define rc 2*node+1
#define endl '\n'

using namespace std;

const int inf = 2e8+7;
int tc = 1;
const int NN = 5e5+6;
int n,q;
struct snode
{
    bool water = false;
    bool push = false;
};

snode segt[4*NN];

snode merg(snode& a , snode& b)
{
    snode ans;
    ans.water = a.water & b.water;
    ans.push = false;
    return ans;
}


void propagate(int& node , int& l , int& r)
{
    if (not segt[node].push) return;
    segt[node].push = false;

    if (l < r)
    {
        segt[lc].push = true;
        segt[rc].push = true;
        segt[rc].water = segt[lc].water = segt[node].water;
    }

    return;
}

void update(int node , int l , int r , int st , int en , bool val)
{
    propagate(node , l ,r);
    if (st>en or st>r or en<l) return;
    if (st<=l and r<=en)
    {
        segt[node].push = val;
        segt[node].water = val;
        propagate(node , l ,r);
        return;
    }
    update(lc , l , mid , st , en , val);
    update(rc , mid+1 , r , st , en , val);
    segt[node].water = (segt[lc].water & segt[rc].water);
    return;
}

bool query(int node , int l , int r , int st , int en)
{
    propagate(node , l ,r);
    if (st>en or st>r or en<l) return true;
    if (st<=l and r<=en)
    {
        return segt[node].water;
    }
    bool f1 = query(lc , l , mid , st , en);
    bool f2 = query(rc , mid+1 , r, st , en);
    return f1&f2;
}

int in[NN];
int out[NN];
int parent[NN];
vector<int> adj[NN];

int timer;

void dfs(int src , int father)
{
    in[src] = ++timer;
    parent[src] = father;
    for (int i : adj[src])
    {
        if (i == father) continue;
        dfs(i , src);
    }
    out[src] = timer;
}


void solve()
{
    dfs(1,0);
    cin >> q;

    while(q--)
    {
        int op , v;
        cin >> op >> v ;
        if (op == 1)
        {
            bool x = query(1, 1 , n , in[v] , out[v]);

            if (!x) update(1,1,n, in[parent[v]], in[parent[v]] , false);

            update(1,1,n , in[v] , out[v] , true);
        }
        else if (op == 2)
        {
            update(1 ,1 ,n , in[v] , in[v] , false);
        }
        else
        {
            bool x = query(1, 1 , n , in[v] , out[v]);
            cout << x << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ///cin >> tc;
    while(tc--)
    {
        cin >> n;
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

