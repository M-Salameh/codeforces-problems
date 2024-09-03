#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#include <math.h>
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
#pragma once
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'


using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 5e15+6;
int n,m;
vector<int> directed[500500];
vector<pair<int,int>> undirected;
vector<int> degree;
vector<int> order;

bool chck()
{
    queue<int> bfs;
    order = vector<int> (n+1 , 0);
    int cnt =  0;

    for (int i=1 ; i<=n ; i++)
    {
        if (degree[i]==0) bfs.push(i);
    }

    while(bfs.size())
    {
        int u = bfs.front();
        bfs.pop();
        order[u] = ++cnt;
        for (int v : directed[u])
        {
            degree[v]--;
            if(degree[v] == 0) bfs.push(v);
        }
    }

    return !(cnt < n);
}

void solve()
{
    if (!chck())
    {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;

    for (int node=1 ; node<=n ; node++)
    {
        for (int v : directed[node])
        {
            cout << node << ' ' << v << endl;
        }
    }

    for (auto& [src , dest] : undirected)
    {
        if(order[src] < order[dest])
        {
            cout << src << ' ' << dest << endl;
            continue;
        }
        cout << dest << ' ' << src <<endl;
    }
    return;
}




signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        degree = vector<int>(n+1,0);
        undirected.clear();
        for (int i=1 ; i<=n ; i++)
        {
            directed[i].clear();
        }

        for (int i=1 ; i<=m ; i++)
        {
            int t,u,v;
            cin >> t >> u >> v;
            if (t==1)
            {
                directed[u].push_back(v);
                degree[v]++;
                continue;
            }
            undirected.push_back({u,v});
        }

        solve();
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
