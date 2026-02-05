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

using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 5e10+6;
int n,k;
vector<int> adj[50500];
vector<vector<int>> dp;

/**

5 2
1 2
1 3
1 4
1 5


7 2
1 2
2 3
3 4
2 5
6 7
2 6

*/
void dfs(int src ,int parent ,int& ans)
{
    dp[src][0] = 1;

    ///cout << "getting in " << src << endl;

    for (auto i : adj[src])
    {
        if (i == parent) continue;
        dfs(i , src , ans);
    }

    ///cout << "src = " << ' ' << src << endl;
    ///cout << "parent = " << ' ' << parent << endl;
    /*    cout << "********************" <<endl;
        for (int i=1 ; i<=k ; i++)
            cout << "dp["<<src<<"][" << i <<"] = " << dp[src][i] << endl;
        cout << "********************" << endl;
    */
    for (auto child : adj[src])
    {
        if (child == parent) continue;


        for (int i=0 ; i<k ; i++)
        {
            int diff = k-i-1;

            /**if (dp[src][diff] and diff !=0 )
            {
                cout << "hh"<<endl;
                cout << "src = " << src << " and diff = " << diff << endl;
                cout << dp[src][diff] << endl;
                cout << "mm" <<endl;
            }*/
            ans += dp[child][i] * dp[src][diff] ;
        }

        for (int i=1 ; i<=k ; i++)
        {
            ///cout << "in sigma : dp["<<src<<"][" << i <<"] = " << dp[src][i] << endl;
            dp[src][i] += dp[child][i-1];
        }

    }

   /// ans += dp[src][k];
   /**int res = dp[src][k];
   if (res == 1) ans += 1;
   else ans += ((res-1)*res)/2;*/
}


void solve()
{
    int ans = 0;
    dfs( 1 , -1 , ans);
    cout << ans << endl;

}






#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
signed main()
{
    fast;
    ///cin >> tc;
    while(tc--)
    {
        cin >> n >> k;
        dp = vector<vector<int>> (n+1 , vector<int>(k+1,  0));
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
