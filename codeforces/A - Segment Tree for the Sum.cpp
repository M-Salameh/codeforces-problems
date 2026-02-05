#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int NN = 1e7+6;

ll segt[NN];
ll arr[NN];
ll n , m;
void Read ()
{
    for (ll i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
    }
    ll comp = floor (log(n));

}
void build (ll node , ll l , ll r)
{

    if (l == r)
    {
        segt[node]=arr[r];
        return;
    }
    ll mid = l+r;
    mid/=2;
    build (2*node , l , mid);
    build (2*node+1 , mid+1 , r);
    segt[node]=segt[2*node+1]+segt[2*node];
}

void update (ll node , ll l , ll r , ll val , ll idx)
{
    if (l==idx && r==idx)
    {
        arr[r]=val;
        segt[node]=val;
        return;
    }
    ll mid = (l+r)/2;
    if (idx >=l && idx<= mid)
    {
        update(node*2 , l , mid , val , idx);
        segt[node] = segt[2*node]+segt[2*node+1];
    }
    if (idx > mid && idx<= r)
    {
        update(node*2+1 , mid+1 , r , val , idx);
        segt[node] = segt[2*node]+segt[2*node+1];
    }
}

ll sum (ll node , ll st , ll en ,ll l , ll r)
{
    if (st > en )return 0;
    if (l ==st && r == en)
    {
        return segt[node];
    }
    ll mid = (l+r)/2;
    if (st <= mid && en >=mid)
    {
         return (sum (2*node ,st , mid, l , mid) + sum (2*node+1 , mid+1 ,en , mid+1 , r));
    }
    if (st > mid)
    {
        return sum (2*node+1 , st , en , mid+1 , r);
    }
    if (en <= mid)
    {
        return sum (2*node , st , en , l , mid);
    }
    else return 0;

}

int main()
{
    cin >> n >> m ;
    Read();
    ll sz;
    sz = ceil(log2(n));
    n = pow(2,sz);
    build (1 , 1 , n);
    ll a,b,x;
    ll w,v,st , en;
    cout <<endl <<endl;
     for (ll i=1 ; i<=m ;i++)
    {
        cin >> x >> a >> b ;
        if (x==1)
        {
            w=a+1;
            v=b;
            update(1 , 1 , n , v , w);
        }
        else
        {
            st=a+1;
            en=b;
            cout << sum(1,st,en,1,n)<<endl;
        }
    }

    return 0;
}
