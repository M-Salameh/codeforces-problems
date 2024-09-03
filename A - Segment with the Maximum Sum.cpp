#include <bits/stdc++.h>
#define ll long long
#define mid (l+r)/2
#define NN int(1e6+9)
using namespace std;


ll n,m;

struct vertex
{
ll seg , pref , suf , sum;
};


ll arr [NN];
vertex segt[NN];


vertex merg (vertex h,vertex g)
{
    vertex ans;
    ans.seg = max (h.seg , max(g.seg , h.suf+g.pref));
    ans.pref = max (h.pref , h.sum+g.pref);
    ans.suf = max (g.suf , g.sum+h.suf);
    ans.sum = h.sum + g.sum;
    return ans;
}


vertex reset (vertex h , ll x)
{
    h.seg=h.pref=h.suf=h.sum=x;
    return h;
}


void build (ll node , ll l , ll r)
{
    if (l==r)
    {
        segt[node] = reset(segt[node] , arr[r]);
        return;
    }
    build (2*node , l , mid);
    build (2*node+1 , mid+1 , r);
    segt[node]=merg(segt[2*node] , segt[2*node+1]);
}


void update (ll node , ll l ,ll r , ll val , ll idx)
{
    if (l==idx && r==l)
    {
        segt[node] = reset (segt[node] , val);
        arr[r]=val;
        return;
    }
    if (idx > mid)
    {
        update (2*node+1 , mid+1 , r , val , idx);
        segt[node]=merg(segt[2*node] , segt[2*node+1]);
    }
    if (idx <= mid)
    {
        update (2*node , l , mid , val, idx);
        segt[node]=merg(segt[2*node] , segt[2*node+1]);
    }
}



void Read ()
{
    cin >> n >> m ;
    for (ll i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
    }
    ll sz = ceil (log2(n));
    n = pow (2 , sz);
    build (1,1,n);
}


void printans(vertex f)
{
    ll k ;
    k = max (max(f.seg,f.pref) , max (f.suf,f.sum));
    (k>0?cout<<k<<endl:cout <<0<<endl);
}


void print()
{
    for (ll i=1 ; i<=2*n ; i++)
    {
        cout << "i = " << i <<endl;
        printans(segt[i]);
        cout << endl;
    }
}


int main()
{
    Read();
    ll in ,v;
    printans(segt[1]);
    for (ll i=1 ; i<=m ; i++)
    {
        cin >> in>> v ;
        in++;
        update(1,1,n,v,in);
        printans(segt[1]);
    }
    return 0;
}
