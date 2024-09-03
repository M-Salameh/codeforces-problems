#include <bits/stdc++.h>
#include <string>
#define endl '\n'
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define ll long long
//#define double long double

using namespace std;

int tc=1;

int n , k ,m;

ll segt[500500];


ll prefscore[200005],prefcost[200005],locs[200005];


void build(int node, int l , int r )
{
    if (r>n or l>r) return;
    if (l==r)
    {
        segt[node] = prefscore[r];
        return;
    }
    build(lc , l , mid);
    build(rc , mid+1 , r);
    segt[node] = max (segt[lc] , segt[rc]);
    return;
}

ll query(int node , int l ,int r , int st , int en)
{
    if (st>en or st>r or en<l or r>n) return -1e9-1;
    if (st<= l and r<=en) return segt[node];
    return max (query(lc , l , mid , st , en) , query (rc , mid+1 , r , st , en));
}

ll reqtopal(string s)
{
    ll n=s.size(),cnt=0;
    for(int i=0;i<n/2;i++)
    if(s[i]!=s[n-i-1])cnt++;
    return cnt;
}


signed main()
{
    fast;
    cin >> tc;
    while (tc--)
    {

       cin>>n>>k;
       prefcost[0]=0;prefscore[0]=0;locs[0]=1;

       for(int i=1;i<=n;i++)
       {
           string s;
           cin>>s;
           ll cost=reqtopal(s);
           prefcost[i]=prefcost[i-1]+cost;
       }
       for(int i=1;i<=n;i++)
       {
           ll score;
           cin>>score;
           prefscore[i]=prefscore[i-1]+score;
       }
       for(int i=1;i<=n;i++)
       {
           int low=lower_bound(prefcost+1,prefcost+n+1,prefcost[i-1]+k+1)-(prefcost);
           if(low>n) low--;
           low -= (prefcost[low]-prefcost[i-1]>k);
           locs[i] = low;
        }

        build(1,1,n);

        ll ans = 0;
        for (int i=1 ;i<=n ; i++)
        {
            if (i>locs[i]) continue;
            int cur = query(1,1,n , i , locs[i]) - prefscore[i-1];
            ans = max (ans , cur);
        }



       for (int i=0 ; i<= 4*n+3 ; i++)
       {
           segt[i] = 0;
       }
       for (int i=0 ; i <= n ; i++)
       {
           prefscore[i] = prefcost[i] = locs[i] = 0;
       }

       cout<<ans<<endl;

    }
    
    return 0;

}
