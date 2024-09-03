#include <bits/stdc++.h>
#define ll long long
#define mid (l+r)/2
#define NN int(1e6+9)

using namespace std;

ll segt[NN];
ll arr[NN];
ll n ,m ;

void build (ll node , ll l , ll r)
{
    if (l==r)
    {
        segt[node] = arr[r];
        return;
    }
    build(2*node , l , mid);
    build (2*node +1 , mid+1 , r);
    segt[node] = max (segt[2*node] , segt[2*node+1]);
}

void update (ll node , ll l , ll r , ll val , ll idx)
{
    if (l==r && l == idx)
    {
        segt[node]=val;
        arr[r]=val;
        return;
    }
    if (idx <= mid)
    {
        update (2*node , l , mid , val , idx);
        segt[node] = max (segt[2*node] , segt[2*node+1]);
    }
    if (idx > mid)
    {
        update (2*node +1 , mid+1 , r, val , idx);
        segt[node] = max (segt[2*node] , segt [2*node+1]);
    }
}


ll find_min(ll node , ll l , ll r , ll val)
{
    if (val > segt[1])
    {
        return -1;
    }
    if (l==r)
    {
        if (segt[node]>=val)
        {
            return l-1;
        }
        return r-1;
    }
    if (val > segt[2*node])
    {
        return find_min (2*node+1 , mid+1 , r , val);
    }
    if (val <= segt[2*node])
    {
        return find_min(2*node , l , mid , val);
    }
}

void Read()
{
    cin >> n >> m ;
    for (ll i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
    }
    ll h = ceil (log2(n));
    n = pow(2,h);
    build (1,1,n);
}

int main()
{
    ll a,b,c;
    Read();
    while (m--)
    {
        cin >> a ;
        if (a==1)
        {
            cin >> b >> c;
            b+=1;
            update(1,1,n,c,b);
        }
        else
        {
            cin >> b ;
            cout << find_min(1,1,n,b)<<endl;
        }
    }
    return 0;
}
