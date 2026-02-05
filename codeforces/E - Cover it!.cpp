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
#pragma once

#define endl '\n'
using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 5e10+6;
int n,m ;
vector<int> adj[500500];
vector<int> degree;

void solve()
{

    degree[1] = 1;
    queue<int> bfs;
    vector<int> odd,even;

    bfs.push(1);
    odd.push_back(1);
    while (bfs.size())
    {
        int u = bfs.front();
        bfs.pop();
        for (int i : adj[u])
        {
            if(degree[i]+1) continue;
            degree[i] = 1 + degree[u];
            bfs.push(i);
            if (degree[i] & 1) odd.push_back(i);
            else even.push_back(i);
        }
    }

    if (even.size() < odd.size())
    {
        swap(even , odd);
    }

    cout << odd.size() << endl;
    for (int i : odd) cout << i << ' ' ; cout << endl;
    return;
}
/**
1
9 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 1

*/


signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        degree = vector<int> (n+1 , -1);
        for (int i=1 ; i<=n; i++)
        {
            adj[i].clear();
        }
        for (int i=1 ; i<=m ; i++)
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




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
