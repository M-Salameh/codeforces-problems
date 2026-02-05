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
int n;
struct vertex
{
    int lv = 0;
    int rv = 0;
};

vertex node[100100];
vector<int> adj[100100];
vector<pair<int,int>> dp;

int dfs(int src , int parent)
{
    dp[src].first = 0;
    dp[src].second = 0;

    for (int child : adj[src])
    {
        if (child == parent) continue;
        dfs(child , src);
    }

    for (int child : adj[src])
    {
        if (child == parent) continue;

        int x_lv = abs(node[src].lv - node[child].lv)+ dp[child].first;
        int y_lv = abs(node[src].lv - node[child].rv) + dp[child].second;
        dp[src].first += max(x_lv , y_lv);

        int x_rv = abs(node[src].rv - node[child].lv) + dp[child].first;
        int y_rv = abs(node[src].rv - node[child].rv) + dp[child].second;

        dp[src].second += max(x_rv , y_rv);
    }


    return max(dp[src].first , dp[src].second);
}

void solve()
{
    int ans = dfs(1,-1);

    cout << ans << endl;
}




signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        dp = vector<pair<int,int>>(n+1 , {0,0});

        for (int i=1 ; i<=n ; i++)
        {
            int l,r;
            cin >> l >> r;
            node[i].lv = l;
            node[i].rv = r;
            adj[i].clear();
        }

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




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
