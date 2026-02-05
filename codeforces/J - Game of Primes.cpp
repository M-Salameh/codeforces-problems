#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define V vector<int>
#define Vv vector<vector<int>>
#define Vp vector<pair<int, int>>
#define No cout << "NO" << Endl
#define Yes cout << "YES" << Endl
#define ll long long
#define Pb push_back
#define S second
#define F first
using namespace std;

const int modo=1e9+7;
const int NN = 1e7+2;

int pw(int x, int y)
{
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x)%modo;
        y = (y >> 1)%modo;
        x = (x * x)%modo;
    }
    return res ;
}

int a[100100];
bool p[1000100];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int Tc=1;
    cin>>Tc;
    int M=1000005;
    for(int i=0;i<=M;i++)p[i]=false;
    for(int i=2;i<=M;i++)
    {
        if(!p[i])
        {
            for(int j=2*i;j<=M;j+=i)p[j]=true;
        }
    }
    while(Tc--)
    {
       int n;cin>>n;
       for(int i=1;i<=n;i++)cin>>a[i];
       int ans=0;int cnt=0;
       for(int i=1;i<=n;i++)
       {
           if(!p[a[i]])
           {
                ans++;
                continue;
           }
           int x;
           for(int j=2;j<=a[i];j++)
           {
               if(a[i]%j==0)
               {
                   x=j;
                   break;
               }
           }
           //cout<<i<<" "<<a[i]<<endl;
           //cout<<x<<" "<<a[i]/x<<endl;
           if(!p[x]&&!p[a[i]/x])ans++;
           else cnt++;
       }
       cout<<ans+(cnt+1)/2<<endl;
    }
    return 0;
}
