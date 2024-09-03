#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mid (l+r)/2
#define lc (2*node)
#define rc (lc+1)
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fori(n) for (ll i=1;i<=n ;i++)
using namespace std;

ll tc;
ll n,q;
const long long inf = 1e6+1;
ll arr[inf];
ll sum[inf];
ll xorr[inf];

ll calc(ll l ,ll r)
{
	return (sum[r]-sum[l-1])-(xorr[r]^xorr[l-1]);
}

void solve()
{
   /* memset(arr , 0 , sizeof(arr));
    memset(sum , 0 , sizeof(sum));
    memset(xorr , 0 , sizeof(xorr));*/
    cin >> n >> q;
    fori(n)
    {
        cin >> arr[i];
        sum[i] = sum[i-1]+arr[i];
        xorr[i] = xorr[i-1]^arr[i];
    }
    ll L,R,ansL,ansR,ans = 1e9;
    cin >> L >> R ;
    ll maxN = calc(L,R);
    for(ll i = L;i <= R;i++)
    {
        ll l = i,r = R,midd,t = R;
        while(l <= r)
        {
           midd = (l+r)/2;
           if(calc(i, midd) >= maxN)
           {

               r = midd-1;
               t = midd;
           }
           else
           {
               l = midd+1;
           }
        }

        if(t-i+1<ans && calc(i,t)==maxN)
        {
            ans = t-i+1;
            ansL = i;
            ansR = t;
        }
    }
    cout << ansL << ' ' << ansR <<endl;

}


int main()
{
    fast_io;
    cin >> tc ;
    while (tc--)
    {
        solve();
    }
    return 0;
}

/*ll val[inf];
ll segt[inf];*/

/*
void build (ll node , ll l , ll r)
{
    if (l==r)
    {
        segt[node] = val[r];
        return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    segt[node] = max(segt[lc],segt[rc]);
}



pair<ll,ll> getloc (ll node ,ll l , ll r ,ll st , ll en)
{
    if (st < l || en > r) return{-1,-1};
    if (st == l && en == r)
    {
        return {l,r};
    }
    if (st>mid)
    {
        return getloc(rc , mid+1,r , st , en);
    }
    if (en <= mid)
    {
        return getloc(lc , l ,mid , st , en);
    }
    if (st<=mid && en>=mid)
    {

        return p;
    }
}
*/

