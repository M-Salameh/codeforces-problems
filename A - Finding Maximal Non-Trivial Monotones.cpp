#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t=1;
    while(t--){
      ll n;
      cin>>n;
      string s;
      cin>>s;
      ll ans=0,cnt=0;
      for(int i=0;i<n-1;i++)
      {
          if(s[i]==s[i+1]&&s[i]=='a')
          {
              cnt++;
          }
          else if(cnt>0) {ans+=cnt+1;cnt=0;}
          if(cnt>0&&i==n-2)ans+=cnt+1;
      }
      cout<<ans;

     }

    return 0;
}
