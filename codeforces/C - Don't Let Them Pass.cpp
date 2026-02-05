#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define MOD 1000000007
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define all(x) x.begin()+1,x.end()
#define all0(x) x.begin(),x.end()
#define double long double
#pragma once
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define endl '\n'


using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 1e15+7;
int n , m;
int pos[1010];
int pos2[1010];
int dp[1010][1010];
int rr;
/**int chck()
{
    bool ans = true;
    pos2[0] = pos2[1];
    for (int i=1; i<=m ;i++)
    {
        ans &= (pos2[i]==pos2[i-1] or pos2[i]==pos2[i-1]-1 or pos2[i]==pos2[i-1]+1);
    }
    if(ans) return 0;
    return -inf;
}*/

int solve(int idx=2 , int pre = rr)
{
    if (idx == m+1) return 0;

    int& ret = dp[idx][pre];
    if (ret+1) return ret;

    int loc1 = pre, cost1 = abs(pos[idx]-loc1);
    int loc2 = min(pre+1,n) , cost2 = abs(pos[idx] - loc2);
    int loc3 = max(pre-1 , 1LL) , cost3 = abs(pos[idx] - loc3);

    int p1 = cost1 + solve(idx+1 , loc1);
    int p2 = cost2 + solve(idx+1 , loc2);
    int p3 = cost3 + solve(idx+1 , loc3);

    ret = min ({p1,p2,p3});
    return ret;

}

signed main()
{
    fast;
    ///cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        memset(dp , -1 , sizeof(dp));

        for (int i=1 ; i<=n ; i++)
        {
            for (int j=1 ; j<=m ; j++)
            {
                bool x;
                cin >> x;
                if (x==1) pos[j]=i;
            }
        }
        int ans = inf;
        for (int i=1 ; i<=n ; i++)
        {
            int temp = abs (pos[1] - i);
            rr = i;
            ans = min (ans , temp + solve());
        }
        cout << ans << endl;
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
