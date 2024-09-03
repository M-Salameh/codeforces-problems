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
///#define int long long
#define double long double
#pragma once
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'


using namespace std;
using namespace __gnu_pbds;

int tc = 1;
///const int inf = 5e15+6;
int n,a,b,k;

vector<int> dp;
vector<int> pref;

int sum(int x , int y)
{
    int z;
    z = x%MOD + y%MOD;
    z %= MOD;
    z += MOD*(z<0);
    return z;
}

int leftt(int idx)
{
    int ans = idx - abs(idx-b) + 1;
    return max (ans , 1);
}
int rightt(int idx)
{
    int ans = idx + abs(idx-b) -1;
    return min (ans , n);
}

void solve()
{
    for (int xyz = 1 ; xyz <= k ; xyz++)
    {
        for (int i=1 ; i<=n ; i++) pref[i] = sum(pref[i-1] , dp[i]);

        for (int i=1 ; i<=n ; i++)
        {
            int le = leftt(i);
            int ri = rightt(i);
            int temp = sum (pref[le-1] , dp[i]);
            dp[i] = pref[ri] - temp;
            dp[i] += MOD*(dp[i] < 0);
            dp[i] %= MOD;
            dp[i] += MOD*(dp[i] < 0);
        }

    }

    cout << dp[a] <<endl;
}

signed main()
{
    fast;
    ///cin >> tc;
    while(tc--)
    {
        cin >> n >> a >> b >> k;
        pref = vector<int>(n+1,0);
        dp = vector<int>(n+1,1);

        solve();

    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
