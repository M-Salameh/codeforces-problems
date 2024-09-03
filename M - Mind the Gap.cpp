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
#define endl '\n'
#pragma once
#define ll long long
#define Pb push_back
#define S second
#define F first
#define endl '\n'
#define V vector<ll>
#define Vv vector<vector<ll>>
#define Vp vector<pair<int,int>>
#define No cout << "NO" << endl
#define Yes cout << "YES" << endl
using namespace std;
using namespace __gnu_pbds;
ll modo;
ll pw(ll x, ll y)
{
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x)%modo;
        y = (y >> 1)%modo;
        x = (x * x)%modo;
    }
    return res % modo;
}

int tc = 1;
const int inf = 1e18+6;
int n ;


void solve()
{

}
int a[100100];
signed main()
{
    fast;
    //cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        for(int i=1;i<=n;i++)
            cin >> a[i];
        sort(a+1, a+n+1);
        a[0] = 0;
        ll Le = 0, Ri = 1e17;
        for(int i=1;i<n;i++){
            int x = a[i] - a[i-1], y = a[i+1]-a[i-1];
            Le = max(Le, x);
            Ri = min(Ri, y - 1);
        }
        Le = max(Le, a[n]-a[n-1]);
        if(Le > Ri)
            cout << 0 <<endl;
        else
            cout << Le << endl;
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
