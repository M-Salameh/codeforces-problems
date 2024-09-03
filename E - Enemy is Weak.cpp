#include <bits/stdc++.h>
#define ll long long
#define lc 2*node
#define rc 2*node+1
#define mid (l+r)/2

using namespace std;

const int inf = 1e7+6;

ll nn;
ll n;
ll segtlrg[inf];
ll segtsm[inf];
ll arr[inf];
ll ans;
bool exist[inf];
void build (ll node , ll l , ll r)
{
    fill (segtlrg , segtlrg + n+1 , 0);
    fill (segtsm , segtsm +n+1 , 1);
    return;
}

void updatelrg (ll node , ll l , ll r , ll idx )
{
    if (l == r)
    {
        segtlrg[node] = 1;
        return;
    }
    if (idx <= mid)
    {
        updatelrg (lc , l , mid , idx);
        segtlrg[node] = segtlrg[lc] + segtlrg[rc];
    }
    if (idx > mid)
    {
        updatelrg (rc , mid+1 , r ,idx );
        segtlrg[node] = segtlrg[lc] + segtlrg[rc];
    }
}

void updatesm (ll node , ll l , ll r , ll idx )
{
    if (l == r)
    {
        segtsm[node] = 0;
        return;
    }
    if (idx <= mid)
    {
        updatesm (lc , l , mid , idx);
        segtsm[node] = segtsm[lc] + segtsm[rc];
    }
    if (idx > mid)
    {
        updatesm (rc , mid+1 , r ,idx );
        segtsm[node] = segtsm[lc] + segtsm[rc];
    }
}


ll sum (ll node , ll l , ll r , ll st , ll en )
{
    if (st<l || en>r || st>en)
    {
        return 0;
    }
    if (st==l && en == r)
    {
       // cout << "at node = "<<node << endl;
        return segtlrg[node];
    }
    if (st<=mid && en >= mid)
    {
      //  cout << "splittin\n";
        return sum (lc , l , mid , st , mid)+ sum (rc , mid+1 , r , mid+1 , en);
    }
    if (st > mid)
    {
       // cout << "going right\n";
        return sum(rc , mid+1 , r , st , en);
    }
    if (en <= mid )
    {
        return sum (lc , l , mid , st , en);
    }
}


ll sumsm (ll node , ll l , ll r , ll st , ll en )
{
    if (st<l || en>r || st>en)
    {
        return 0;
    }
    if (st==l && en == r)
    {
       // cout << "at node = "<<node << endl;
        return segtsm[node];
    }
    if (st<=mid && en >= mid)
    {
      //  cout << "splittin\n";
        return sumsm (lc , l , mid , st , mid)+ sumsm (rc , mid+1 , r , mid+1 , en);
    }
    if (st > mid)
    {
       // cout << "going right\n";
        return sumsm(rc , mid+1 , r , st , en);
    }
    if (en <= mid )
    {
        return sumsm (lc , l , mid , st , en);
    }
}


void solve()
{
    ll sm=0 , lrg;
    memset(exist , false , sizeof(exist));
    for (ll i=1 ; i<=nn ; i++)
    {
        cin >> arr[i] ;
        if (arr[i]>sm)sm=arr[i];
    }
    ll sz = ceil(log2(sm));
    n = pow(2,sz);
    build (1,1,n);
    for (ll i=1 ; i<=nn ; i++)
    {
        cout << "cheching on "<<arr[i] <<endl;
        lrg = sum (1,1,n,arr[i]+1,n);
        sm = sumsm (1,1,n,1,arr[i]-1 );
        ans += (lrg*sm);
        cout << "sm = " << sm << "   and   lrg = " << lrg << endl;
        updatelrg(1,1,n,arr[i]);
        updatesm(1,1,n,arr[i]);
    }
    cout << ans <<endl;

}

int main()
{
    cin >> nn ;
    solve();
    return 0;
}
