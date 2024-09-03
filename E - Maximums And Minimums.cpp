#include <bits/stdc++.h>
#define ll long long
#define mid (l+r)/2
#define NN int(1e6+9)
#define pll pair<ll,ll>
#define lc 2*node
#define rc 2*node+1
using namespace std;

ll nn;
ll n;
pll segt[NN];
ll arr[NN];
ll ans;

pll merg(pll a , pll b)
{
    a.first=min(b.first,a.first);
    a.second=max(b.second,a.second);
    return a;
}

void build (ll node , ll l , ll r)
{
    if (l==r)
    {
        segt[node].first=segt[node].second=arr[r];
        return;
    }
    build (lc , l , mid);
    build (rc , mid+1 , r);
    segt[node].first = min (segt[lc].first , segt[rc].first);
    segt[node].second = max(segt[lc].second , segt[rc].second);
}



pll subans(ll node , ll l , ll r , ll st , ll en)
{
    if (st<l || en > r || st>en)return{0,0};
    if (st == l && en == r)
    {
       // cout << "pre calc node\n";
        return segt[node];
    }
    if (en <= mid)
    {
      //  cout <<"going left\n";
        return subans(lc , l , mid , st , en);
    }
    if (st > mid)
    {
//cout << "going right \n";
        return subans(rc , mid+1 , r , st , en);
    }
    if (st<=mid && en >=mid)
    {
     //   cout <<"splitting\n";
        return merg(subans(lc , l , mid , st , mid) , subans(rc , mid+1 , r, mid+1,en));
    }
}


void Read()
{
    ans=0;
    for (ll i=1 ; i<=nn ; i++)
    {
        cin >> arr[i];
    }
    for (ll i=0 ; i<=2*n+1; i++)
    {
        segt[i]={0,0};
    }
    build(1,1,n);
}


void solve()
{
    pll res;
    for (ll i=1 ; i<=nn ; i++)
    {
        for (ll j=i ; j<=nn ; j++)
        {
          //  cout << "when i = "<<i << " and j = " <<j << " the min and max respectively are\n";
            res = subans(1,1,n,i,j);
        //    cout << res.first << " , " << res.second << endl;
            ans += (res.second % res.first == 0);
       //    cout << "the curr ans is = " <<ans <<endl;
        }
    }
    cout << ans <<endl;
}


int main()
{
   ll tc;
   cin >> tc;
   while (tc--)
   {
        cin >> nn;
        n = pow (2,ceil(log2(nn)));
        Read();
        solve();
   }
    return 0;
}
