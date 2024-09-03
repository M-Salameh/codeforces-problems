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
int modo=998244353;
ll pw(ll x, ll y)
{
    ll res = 1;
    while (y > 0)
    {
        if (y % 2 == 1) res = (res * x)%modo;
        y = (y >> 1)%modo;
        x = (x * x)%modo;
    }
    return res ;
}
int fac[1000001],inv[1000001];
void pre_calc()
{
    int M = 1000000;
    fac[0]=1;
    for (int i=1 ; i<=M ; i++) fac[i]=(fac[i-1]*i)%modo;

    inv[M] = pw(fac[M] , modo-2);

    for(int i = M-1 ; i>=0 ; i--)
    {
        inv[i]=(inv[i+1]*(i+1))%modo;
    }
}

signed main()
{
    fast;
    ///cin >> tc;
    pre_calc();
    while(tc--)
    {
        cin >> n;
        int ans = (n*fac[n])%modo;
        int s = 0;
        for(int k=1; k <= n ; k++)
        {
            s += inv[k];
            s %= modo;
        }
        s = (s*fac[n]) % modo;
        ans = (ans-s) % modo;
        ans++;
        ans = (ans+modo)%modo;
        cout << ans << endl;
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
