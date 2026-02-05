#include <bits/stdc++.h>
#define ll long long
#define mid (l+r)/2
#define NN int(1e6+9)

using namespace std;

ll arr[NN];
ll segt[NN];
ll n ,m;


void build (ll node , ll l , ll r)
{
    if (l==r)
    {
        segt[node]=arr[r];
        return;
    }
    build (2*node , l , mid);
    build (2*node+1 , mid+1 , r);
    segt[node] = segt[2*node] + segt[2*node+1];
}


void update (ll node , ll l , ll r , ll idx)
{
    if (l==r && l == idx)
    {
        arr[r]= 1-arr[r];
        segt[node] = arr[r];
        return;
    }
    if (idx <= mid)
    {
        update (2*node , l , mid , idx);
        segt[node] = segt[2*node]+segt[2*node+1];
    }
    if (idx > mid)
    {
        update (2*node+1 , mid+1 , r , idx);
        segt[node] = segt[2*node] + segt[2*node+1];
    }
}


ll findk(ll node , ll l , ll r , ll k )
{
    if (l == r )
    {
        return l-1;
    }
    /*if (node<n)
    {
        if (k==segt[node] && segt[2*node+1]!=0)
        {
            return r-1;
        }
    }*/
    if (k > segt[2*node])
    {
        return findk (2*node+1 , mid+1 , r, k-segt[2*node]);
    }
    if (k<=segt[2*node])
    {
        return findk (2*node , l , mid , k);
    }
}


void Read()
{
    cin >> n >> m ;
    for (ll i=1 ; i <= n ; i++)
    {
        cin >> arr[i];
    }
    ll h = ceil(log2(n));
    n = pow (2,h);
    build (1,1,n);
}

void print()
{
    for (ll i=1 ; i<2*n ; i++)
    {
        cout << i << "   " << segt[i] <<endl;
    }
}

int main()
{
    ll a,b;
    Read();
    for (ll i=1 ; i<=m ; i++)
    {
        cin >> a >> b ;
        b+=1;
        if (a==1)
        {
            update (1,1,n,b);
        }
        else
        {
            cout << findk(1,1,n,b)<<endl;
        }
    }
    return 0;
}
