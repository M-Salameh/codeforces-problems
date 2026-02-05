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
#define endl '\n'
#pragma once
#define Pb push_back
#define s second
#define f first
#define endl '\n'
#define V vector<ll>
#define Vv vector<vector<ll>>
#define Vp vector<pair<int,int>>
using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 1e18+6;
int n ;


void solve()
{

}

ll modo=1000000007;

ll pw(ll a,ll b){
    if(b==0)return 1;
    ll res=pw(a,b/2)%modo;
    res=(res*res)%modo;
    if(b&1)res=(res*a)%modo;
    return res%modo;
}

signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        int n;cin>>n;
        int a[200100];
        for(int i=1;i<=n;i++)cin>>a[i];
        map<int,int>cnt;
        for(int i=1;i<=n;i++)
        {
            cnt[a[i]]++;
        }
        int sum=0,c=1,ans=0;
        int k=0;
        while(true)
        {
            sum+=cnt[k];
            int temp=(k*c)%modo;
            temp=(temp*pw(2,n-sum))%modo;
            ans=(ans+temp)%modo;
            ans=(ans+modo)%modo;
            temp=pw(2,cnt[k]);
            temp=(temp-1)%modo;
            c=(c*temp)%modo;
            if(cnt[k]==0)break;
            k++;
        }
        cout<<ans<<endl;
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
