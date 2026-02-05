#include <bits/stdc++.h>
#include <math.h>
#define ll long long

using namespace std;
const int NN = 1e7+6;
const ll inf = 1e10+9;
ll segt[NN];
ll arr[NN];
ll n , m;

void build (ll node , ll l , ll r)
{
    if (l == r)
    {
        segt[node]= arr[r];
        return;
    }
    ll mid = (l+r)/2;
    build (2*node , l , mid);
    build (2*node+1 , mid+1 , r);
    segt[node] = min(segt[2*node] , segt[2*node+1]);
}

void update (ll node , ll l , ll r , ll val , ll idx)
{
    if (l==idx && r==idx)
    {
        arr[r]=val;
        segt[node]=val;
        return;
    }
    ll mid  = (l+r)/2;
    if (idx <= mid)
    {
        update(2*node , l , mid , val , idx);
        segt[node] = min(segt[node*2] , segt[2*node+1]);
    }
    if (idx > mid)
    {
        update (2*node+1 , mid+1 ,r , val , idx);
        segt[node] = min (segt[node*2] , segt[2*node+1]);
    }
}


ll find_min (ll node , ll l , ll r ,ll st ,ll en)
{
    if (l==st && en==r)
    {
        return segt[node];
    }
    ll mid = (l+r)/2;
    if (st > mid)
    {
        return find_min (2*node+1 , mid+1 , r , st , en);
    }
    if (en <= mid)
    {
        return find_min (2*node , l , mid , st , en);
    }
    if (st<= mid && en >= mid)
    {
        return min (find_min(2*node , l , mid , st , mid ) , find_min (2*node+1 , mid+1 , r , mid+1 , en ) );
    }
}

void Read()
{
    ll sz = ceil(log2(n));
    ll h = pow(2,sz);
    fill(arr , arr+h , inf);
    for (ll i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
    }
    n=h;
}

int main()
{
    cin >> n >> m;
    Read();
    build(1,1,n);
    ll x,a,b,c;
    for (ll i=1 ; i<=m ; i++)
    {
        cin >> x >> a >> b ;
        if (x==1)
        {
            a+=1;
            update(1,1,n,b,a);
        }
        else
        {
            a+=1;
            cout << find_min(1,1,n,a,b)<<endl;
        }
    }
    return 0;
}
