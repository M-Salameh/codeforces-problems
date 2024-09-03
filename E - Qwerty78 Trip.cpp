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
///int MOD=1e9+7;
using namespace std;

int fac[300100];
int n,m;

int pw(int a,int b)
{

    if(b==1)return a%MOD;
    if(b==0)return 1;
    int res=pw(a,b/2)%MOD;
    res=(res*res)%MOD;
    if(b&1)res=(res*a)%MOD;
    return res%MOD;
}

void factorial()
{
    fac[0]=1;
    for(int i=1;i<=300005;i++)
    {
        fac[i]=(fac[i-1]*i)%MOD;
        fac[i]%MOD;
    }
}


signed main()
{
    fast;
    factorial();
    int tc;
    cin >> tc ;
    while(tc--)
    {
      cin >> n >> m;
      int i,j;
      cin >> i >> j;

      int ans1=(fac[n+m-2]*pw(fac[n-1],MOD-2))%MOD;
      if(ans1<0) ans1+=MOD;
      ans1=(ans1*pw(fac[m-1],MOD-2))%MOD;
      if(ans1<0)ans1+=MOD;

      int ans2=(fac[n+m-i-j]*pw(fac[n-i],MOD-2))%MOD;
      if(ans2<0)ans2+=MOD;
      ans2=(ans2*pw(fac[m-j],MOD-2))%MOD;
      if(ans2<0)ans2+=MOD;

      int ans3=(fac[i+j-2]*pw(fac[i-1],MOD-2))%MOD;
      if(ans3<0)ans3+=MOD;
      ans3=(ans3*pw(fac[j-1],MOD-2))%MOD;
      if(ans3<0)ans3+=MOD;

      ans2=(ans2*ans3)%MOD;
      if(ans2<0)ans2+=MOD;

      int ans=(ans1-ans2)%MOD;
      if(ans<0)ans+=MOD;

      cout<<ans<<endl;
    }

    return 0;
}
