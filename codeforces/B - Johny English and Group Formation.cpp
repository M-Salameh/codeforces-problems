#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define enter for(ll i=1;i<=n;i++)cin>>a[i]
#define sorrt sort(a+1,a+m+1);
#define mem memset(vis,0,sizeof vis);
#define pb push_back
#define f first
#define s second
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int vis[1000010],a[1000010];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
      int n;cin>>n;
      enter;
      memset(vis,0,sizeof vis);
      for(int i=1;i<=n;i++)
      {
          vis[a[i]]++;
      }
      int mm=0;
      for(int i=1;i<=1000010;i++){
        if(vis[i]>mm)mm=vis[i];
      }
cout<<max((n+1)/2,mm)<<endl;

    return 0;
}
