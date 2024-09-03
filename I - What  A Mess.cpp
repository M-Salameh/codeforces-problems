#include <bits/stdc++.h>
#include <math.h>
#include <string>
#define endl '\n'
//#define int long long
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
int a[100100];
int cnt[1000006];
int n;
ll ans;
signed main()
{
    fast;
    cin >> tc ;
    while(tc--)
    {
      cin>>n;
      for(int i=1;i<=n;i++)cnt[i]=0;
      for(int i=1;i<=n;i++)
      {
        cin>>a[i];
        cnt[a[i]]++;
      }
      sort(a+1,a+1+n);
      ans=0;
      for(int i=n;i>=1;i--)
      {
        ans+=cnt[a[i]]-1;
        cnt[a[i]]--;
        for(int j=2;j<=sqrt(a[i]);j++)
        {
            if(a[i]%j==0)
            {
                ans+=cnt[j];
                if(a[i]/j != j)ans+=cnt[a[i]/j];
            }
        }
      }
      cout<<ans<<endl;
    }

    return 0;
}
