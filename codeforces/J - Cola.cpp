#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll modo=1000000007;

ll pw(ll a,ll b){
    if(b==0)return 1;
    ll res=pw(a,b/2)%modo;
    res=(res*res)%modo;
    if(b&1)res=(res*a)%modo;
    return res%modo;
}
ll a[100100];ll p[100100]; ll f[100100];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t=1;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;

        for(ll i=1;i<=n;i++)cin>>a[i];

        for(ll i=1;i<=n+1;i++)p[i]=0;

        for(ll i=1;i<=n;i++)f[i]=0;
        ll x,y;
        while(m--){
            cin>>x>>y;
            if(y+f[x]>a[x]){
                ll z=a[x]-f[x];
                f[x]=a[x];
                p[x+1]+=y-z;
            }
            else f[x]+=y;
        }
        //for(int i=1;i<=n;i++)cout<<p[i]<<" ";cout<<endl;
        //for(int i=1;i<=n;i++)cout<<f[i]<<" ";cout<<endl;
        for(ll x=1;x<=n;x++){
            p[x]+=p[x-1];
            if(p[x]+f[x]>a[x]){
                ll z=a[x]-f[x];
                f[x]=a[x];
                p[x]-=z;
            }
            else {f[x]+=p[x];p[x]=0;}
        }
        p[n+1]+=p[n];
        cout<<p[n+1]<<endl;
        for(ll i=1;i<n;i++)cout<<f[i]<<" ";cout<<f[n]<<endl;
    }
    return 0;
}
