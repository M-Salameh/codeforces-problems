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
set<int> adj[500500];
vector<bool> visited;
set<int> vertices;

void dfs (int src , int& ans)
{
    /**cout << "before erasing " << src << endl;
    for (auto it : vertices) cout << it << " ";
    cout << endl << "after erasing " << src << endl;*/
    vertices.erase(src);
    ///for (auto it : vertices) cout << it << " ";
    visited[src] = true;
    ans++;
    int nxt = -inf;
    for(;;)
    {
        ///auto it = vertices.lower_bound(nxt);
        auto it = vertices.upper_bound(nxt);
        if (it == vertices.end()) return;
        nxt = *it;
        if (*adj[src].lower_bound(nxt) == nxt ) continue;
        ///cout << "I am in " << src << " and going to " << nxt << endl;
        dfs(nxt , ans);
    }
}

void solve()
{
    int res = 0;
    multiset<int> ans;
    for (int i=1 ; i<=n ; i++)
    {
        res = 0;
        if (visited[i]) continue;
        dfs(i , res);
        ans.insert(res);
    }
    cout << ans.size() << endl;
    for (auto it : ans )
    {
        cout << it << ' ';
    }
    cout << endl;
}

signed main()
{
    fast;
    ///cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        visited = vector<bool> (n+1 , false);
        vertices.clear();
        for (int i=1 ; i<=n ; i++) adj[i].clear(),vertices.insert(i);

        for (int i=1 ; i<=m ; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);
        }

        solve();

    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
