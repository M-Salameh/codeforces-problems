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

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--){

        ll n,x;
        cin>>n>>x;

        ll a[220];
        for(ll i=1;i<=n;i++)cin>>a[i];

        sort(a+1,a+1+n);

        bool mp[200];
        for(int i=1;i<=n;i++)mp[i]=false;
        for(ll i=1;i<n;i++){
            for(ll j=i+1;j<=n;j++){
                if(a[j]%a[i]==0)mp[j]=true;
            }
        }

        vector<ll>v;
        for(ll i=1;i<=n;i++){
            if(mp[i]==false)v.push_back(a[i]);
        }

        ll ans=0;
        ll s=v.size();
        ll cnt=0,r=1;
        for(ll j=1;j<(1<<s);j++){
            cnt=0;r=1;
            for(ll k=0;k<s;k++){
                if(j&(1<<k)){
                    r*=v[k];
                    cnt++;
                }
            }
            //cout<<r<<endl;
            if(cnt&1)ans+=x/r;
            else ans-=x/r;
        }

        cout<<ans<<endl;

    }
    return 0;
}