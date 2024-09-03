  #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define enter for(ll i=1;i<=n;i++)cin>>a[i]
    #define sorrt sort(a+1,a+n+1);
    #define mem memset(vis,0,sizeof vis);
    #define pb push_back
    #define f first
    #define s second
    ll a[20000005];
    void prime(ll n,ll a[]){
        a[1]=0;a[0]=0;
for(int i=2;i<=n;i++){
if(a[i]==-1){
for(ll j=2*i;j<=n;j+=i)a[j]=0;
}}}
   int main(){
   ll n;cin>>n;
   memset(a,-1,sizeof a);
   prime(n,a);
   bool c=0;
   ll ans1;
   for(int i=1;i<=n;i++){
    if(a[i]==-1){
        if(a[n-i]==-1){ans1=i;c=1;break;}
    }
   }
   if(!c)cout<<-1;
   else cout<<ans1<<" "<<n-ans1;
      return 0;
    }
