#include <bits/stdc++.h>
#define ll long long
#define fori(n) for (ll i=1 ;i<=n ; i++)
#define mid (l+r)/2
#define lc 2*node
#define rc lc+1
#define endl '\n'
#define oper  segt[node] = segt[lc]+segt[rc]
#define inf (int) 1e6+1
using namespace std;
ll n;
ll tc;
ll gcd;
ll ans;
void setv()
{
    gcd =0;
    ans=3;
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while (tc--)
    {
        cin >> n ;
        setv();
        vector<ll> a(n+1);
        fori(n)
        {
            cin >> a[i];
            gcd = __gcd(gcd,a[i]);
        }
        if (gcd == 1)
        {
            ans=0;
        }
        else
        {
            ll k;
            fori (n)
            {
                k = __gcd(i,gcd);
                if (k==1)
                {
                    ans = min(ans , n-i+1);
                }
            }
        }
        cout << ans <<endl;
    }
    return 0;
}
