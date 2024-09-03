#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define s second
#define f first
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
int main()
{
    fastio;
    ll tt=1;
    //cin>>tt;
    while(tt--)
    {
   ll n;
   cin>>n;
   ll dis[n+1]={0},time[n+1]={0},ans=0;
   for(int i=1;i<=n-1;i++)
   {
       cin>>dis[i];
   }
    for(int i=1;i<=n;i++)
   {
       cin>>time[i];
   }
   ll trin1[n+1]={0},trin2[n+2]={0};
   for(int i=1;i<=n;i++)
   {
       trin1[i]+=trin1[i-1]+time[i];
       trin1[i]+=dis[i-1];
   }
   for(int i=n;i>=1;i--)
   {
       trin2[i]+=trin2[i+1]+time[i];
       trin2[i]+=dis[i];
   }
   for(int i=1;i<=n;i++)
   {
       trin1[i]-=time[i];
       trin2[i]-=time[i];
       if(time[i]-abs(trin1[i]-trin2[i])>0)ans+=time[i]-abs(trin1[i]-trin2[i]);
   }
   cout<<ans<<endl;
}
    return 0;
}

