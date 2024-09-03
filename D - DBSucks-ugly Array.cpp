#include <bits/stdc++.h>
#include <string>
//#define endl '\n'
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define ll long long
//#define double long double

using namespace std;

int tc=1;

int n;


int power(int a , int b)
{
    if (b==0) return 1;
    if (b==1) return a;
    int res = power(a,b/2) % MOD;
    res = (res*res) % MOD;
    if (b&1) res = (a*res)%MOD;
    return res%MOD;
}

int power3(int a , int b)
{
    if (b==0) return 1;
    if (b==1) return a;
    int res = power(a,b/2);
    res = (res*res);
    if (b&1) res = (a*res);
    return res;
}



signed main()
{
    fast;
    cin >> tc;
    while (tc--)
    {
        int n,m;
        cin>>n>>m;
        int a[100100];
        bool d[100100];
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=100001;i++)d[i]=false;
        for(int i=1;i<=n;i++){
            if(a[i]!=1)d[a[i]]=true;
            for(int j=2;j<=sqrt(a[i]);j++){
                if(a[i]%j==0){
                    d[j]=true;
                    d[a[i]/j]=true;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            bool x=false;
            for(int j=1;j<=sqrt(i);j++){
                if(i%j==0){
                    if(d[j])x=true;
                    if(d[i/j])x=true;
                }
            }
            if(!x)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
