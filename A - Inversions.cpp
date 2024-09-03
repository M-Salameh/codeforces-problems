#include <bits/stdc++.h>
#define ll long long
#define mid (l+r)/2
#define lc 2*node
#define rc 2*node+1
#define inf int(1e7+6)
using namespace std;

ll n,nn;

ll segt[inf];

ll arr[inf];

ll vis[inf];

ll ans[inf];

void build (ll node , ll l , ll r)
{
    fill(segt , segt+n+2 , 0);

 /*  if (l == r)
    {
        segt[node]=arr[r];
        return;
    }
    build (2*node , l , mid);
    build (2*node+1 , mid+1 , r);
    segt[node]=segt[2*node+1]+segt[2*node];*/
}

void update(ll node , ll l , ll r , ll idx)
{
    if (l==r)
    {
        segt[node] = 1;
        return;
    }
    if (idx <= mid)
    {
        update(lc , l , mid , idx);
        segt[node] = segt[lc] + segt[rc];
    }
    if (idx > mid)
    {
        update(rc , mid+1 , r , idx);
        segt[node] = segt[lc]+segt[rc];
    }
}

ll sum (ll node , ll l , ll r , ll st , ll en)
{
    if (l>st || en > r)
    {
        return  0;
    }
    if (l == st && r == en)
    {
        return segt[node];
    }
    if (st<= mid && en>=mid)
    {
        return sum(lc , l , mid , st , mid)+sum(rc , mid+1 , r , mid+1 , en);
    }
    if (st > mid)
    {
        return sum(rc , mid+1 , r , st , en);
    }
    if (en <= mid)
    {
        return sum (lc , l , mid , st , en);
    }
}

void solve()
{
    ll sz=ceil(log2(nn));
    n = pow(2,sz);
    build(1,1,n);
    for (ll i=1 ; i<=nn ; i++)
    {
        cin >> sz;
        ans[i] = sum(1,1,n,sz+1,n);
        update(1,1,n,sz);
    }
    for (ll i=1 ; i<=nn ; i++)
    {
        cout << ans[i]<<" ";
    }
    cout << endl;

}

int main()
{
    cin >> nn;
    solve();
    return 0;
}
