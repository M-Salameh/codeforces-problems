#include <bits/stdc++.h>
#include <math.h>
#include <string>
#define endl '\n'
#define int long long
#define double long double
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536
#define ll long long

const int MOD = 1e9+7;

using namespace std;

int tc=1;
int n;
int arr [10005];
int even_pref [10005];
int odd_pref [10005];

void set_prefs()
{
    even_pref[1] = even_pref[0] = 0LL;
    odd_pref[0]=0LL;

    for(int i=1;i<=n;i++)
    {
        even_pref[i]=even_pref[i-1]+arr[i]*(!(i&1));
        odd_pref[i]=odd_pref[i-1]+arr[i]*(i&1);
    }
}


void solve()
{
    if(n%2==0)
    {
        cout<<max(even_pref[n],odd_pref[n])<<endl;
        return;
    }
    int ans = -1e17;
    for(int i=1;i<=n;i++)
    {
        if(i&1)
        {
            ans=max(ans,odd_pref[n]-odd_pref[i-1]+even_pref[i-1]);
        }
        else
        {
            ans=max(ans,even_pref[n]-even_pref[i-1]+odd_pref[i-1]);
        }
    }

    cout<<ans<<endl;
    return;
}

signed main()
{
    fast;
    cin >> tc ;
    while(tc--)
    {
      cin>>n;
      for(int i=1;i<=n;i++)
      {
          cin>>arr[i];
      }
      set_prefs();
      solve();
    }

    return 0;
}
