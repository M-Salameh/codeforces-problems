#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#include <math.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
#define ll long long
#define Pb push_back
#define S second
#define F first
///#define endl '\n'
using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 1e14+6;
int n,c ;
set<pair<int,int>> no_do;

signed main()
{
   fast;
    while(tc--)
    {
        int n,k;cin>>n>>k;
        int ans=0;
        int l1=0;
        for(int i=k;i>=l1;i--)
        {
            if(i>n){l1++;continue;}
            int cc=1;
            int dd=1;
            for(int j=0;j<i;j++)
            {
                cc*=(n-j);
                dd*=(j+1);
                if(cc%dd==0)
                {
                    cc/=dd;
                    dd=1;
                }
            }
            int ce=1;
            for(int j=0;j<i/2;j++)
            {
                ce*=(n/2-j);
                ce/=(j+1);
            }
            if(n%2==0&&i%2==1)ce=0;
            ans+=(cc-ce)/2+ce;
            //cout<<ans<<endl;
        }
        if(k%2==0&&k/2<=n)
        {
            int i=k/2;
            int cc=1;
            for(int j=0;j<i;j++)
            {
                cc*=(n-j);
                cc/=(j+1);
            }
            int ce=1;
            for(int j=0;j<i/2;j++)
            {
                ce*=(n/2-j);
                ce/=(j+1);
            }
            if(n%2==0&&i%2==1)ce=0;
            ans+=(cc-ce)/2+ce;
        }
        cout<<ans<<endl;
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
