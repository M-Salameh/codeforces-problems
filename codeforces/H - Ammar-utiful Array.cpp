#include <bits/stdc++.h>
#include <string>
#define endl '\n'
#define lc 2*node
#define rc lc+1
//#define mid (l+r)/2
#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define ll long long
//#define double long double

using namespace std;

int tc=1;

int n;


int power(int a , int b)
{
    if (b==0) return 1;
    if (b==1) return a;
    int res = power(a,b/2) % MOD;
    res = (res*res) % MOD;
    if (b&1) res = (a*res)%MOD;
    return res%MOD;
}

int power3(int a , int b)
{
    if (b==0) return 1;
    if (b==1) return a;
    int res = power(a,b/2);
    res = (res*res);
    if (b&1) res = (a*res);
    return res;
}


vector<ll> pre[200005];
ll a[200005],cnt[200005];
signed main()
{
    fast;
   // cin >> tc;
    while (tc--)
    {
        ll n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        memset(cnt,0,sizeof (cnt));
        for(int i=1;i<=n;i++)
        {
            ll x;
            cin>>x;
           if(cnt[x]) pre[x].push_back(a[i]+pre[x][cnt[x]-1]);
           else pre[x].push_back(a[i]);
           //cout<<x<<" "<<pre[x][cnt[x]]<<endl;
           cnt[x]++;
        }
        memset(cnt,0,sizeof (cnt));
        ll q,sum=0;
        cin>>q;
        while(q--)
        {
            ll ty,co,val;
            cin>>ty>>co>>val;
            if(ty==1)
            {
               cnt[co]+=val;
               sum+=val;
            }
            else
            {
            ll l=0,r=pre[co].size()-1,ans;
           while(l<=r)
           {
               ll mid=(l+r)/2;
               ll x=(mid+1)*(cnt[co]-sum)+val;
               //cout<<x<<endl;
               if(pre[co][mid]>=x){r=mid-1;ans=mid;}
               else {l=mid+1;}
           }
            if(pre[co][ans]==(ans+1)*(cnt[co]-sum)+val)cout<<ans+1<<endl;
            else cout<<ans<<endl;
            }
        }
    }
    return 0;

}
