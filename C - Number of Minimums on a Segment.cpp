#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;

const int NN = 1e6+6;
const ll inf = 1e10+9;

pair<ll,ll> segt[NN];
ll arr[NN];
ll n , m;
ll freq [NN];
ll md;

pair<ll, ll> combine(pair<ll, ll> a, pair<ll, ll> b)
{
    if(a.first < b.first) return a;
    if(b.first < a.first) return b;
    return {a.first, a.second+b.second};
}

void build (ll node , ll l , ll r)
{
    if (l==r)
    {
        segt[node].f = arr[r];
        segt[node].s = 1;
        return;
    }
    ll mid = (l+r)/2;
    build (2*node , l , mid );
    build (2*node+1 , mid+1 , r);
    segt[node] = combine(segt[2*node] , segt[2*node+1]);
}

void update (ll node , ll l , ll r , ll val , ll idx)
{
    if (l==idx && l==r)
    {
        arr[r]=val;
        segt[node]={val ,1};
        return;
    }
     ll mid = (l+r)/2;
    if (idx <= mid)
    {
        update(2*node , l , mid , val , idx);
        segt[node] = combine(segt[2*node] , segt[2*node+1]);
    }
    if (idx > mid)
    {
        update(2*node+1 , mid+1 , r , val , idx);
        segt[node] = combine(segt[2*node] , segt[2*node+1]);
    }

}


pair<ll,ll> answer (ll node , ll l , ll r , ll st , ll en)
{
    if (l==st && r == en)
    {
        return segt[node];
    }
    ll mid = (l+r)/2;
    if (st>mid)
    {
        return answer(2*node+1 , mid+1 , r , st , en);
    }
    if (en <= mid)
    {
        return answer(2*node , l , mid , st , en);
    }
    if (st<=mid && en>=mid)
    {
        return combine(answer(2*node , l , mid , st , mid)  ,
                   answer(2*node+1 , mid+1 , r , mid+1 , en) );

    }
}

void Read()
{
    ll sz = ceil(log2(n));
    ll h = pow (2,sz);
    fill (arr , arr+NN , inf);
    pair < ll , ll > p;
    p= {inf , 0};
    fill (segt , segt+NN , p);
    for (ll i=1 ; i<=n ;i++)
    {
        cin >> arr[i];
    }
    n=h;
    build(1,1,n);
}

int main()
{
    cin >> n >> m ;
    Read();
    ll x,a,b;
    pair <ll,ll> p;
   for (ll i=1 ; i<=m ; i++)
    {
        cin >> x >> a >> b ;
        a+=1;
        if (x==1)
        {
            update(1,1,n,b,a);
        }
        else
        {
            p = answer(1,1,n,a,b);
            cout << p.f <<  " " << p.s <<"\n"<< endl;
        }
    }
    return 0;
}
