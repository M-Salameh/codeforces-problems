#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#include <math.h>
#define MOD 1000000007
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define pi pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin()+1,x.end()
#define all0(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define ll unsigned long long
#define int long long
#define double long double
#pragma once
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'


using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 5e15+6;
int n,q;
int arr[200100];
int cnt[1000001];
int MM = 1000000;
vector<pair<int,pair<int,int>>>v[200100];


signed main()
{
    fast;
    ///cin >> tc;
    while(tc--)
    {
        cin >> n >> q;
        for(int i=1;i<=n;i++)
        {
            cin >> arr[i];
        }

        for(int i=1 ; i<=MM ; i++) cnt[i]=0;
        int x = sqrt(n);
        if(x*x != n) x++;
        int m = 0;
        for(int i=1 ; i<=q ; i++)
        {
           int l,r;
           cin >> l >> r;
           int id=l/x;
           m = max(m,id);
           v[id].push_back({r,{l,i}});
        }

        for(int i=0;i<=m;i++) sort(all0(v[i]));
        int l=1,r=1;

        vector<int>ansq(200100,0);
        int ans = 0;
        for(int i=0 ; i<=m ; i++)
        {
           for(int j=0;j<v[i].size();j++)
           {
               int rg=v[i][j].first;
               int lg=(v[i][j].second).first;
               int id=(v[i][j].second).second;
               while(r<=rg)
               {
                   int x=arr[r];
                   ans -= cnt[x]*cnt[x]*x;
                   cnt[x]++;
                   ans+=cnt[x]*cnt[x]*x;
                   r++;
               }
               while(l<lg)
               {
                   int x=arr[l];
                   ans-=cnt[x]*cnt[x]*x;
                   cnt[x]--;
                   ans+=cnt[x]*cnt[x]*x;
                   l++;
               }
               while(l>lg)
               {
                   l--;
                   int x=arr[l];
                   ans-=cnt[x]*cnt[x]*x;
                   cnt[x]++;
                   ans+=cnt[x]*cnt[x]*x;
               }
               while(r>rg+1)
               {
                   r--;
                   int x=arr[r];
                   ans-=cnt[x]*cnt[x]*x;
                   cnt[x]--;
                   ans+=cnt[x]*cnt[x]*x;
               }
               ansq[id]=ans;
           }
        }
       for(int i=1;i<=q;i++)cout<<ansq[i]<<endl;
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
