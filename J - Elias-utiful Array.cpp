#include <bits/stdc++.h>
#include <string>
#define endl '\n'
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
        ll n;
        cin>>n;
        ll a[100100];
        for(ll i=1;i<=n;i++)cin>>a[i];
        ll ans[33];
        for(ll i=0;i<=30;i++)ans[i]=0;
        for(ll i=1;i<=n;i++){
            ll j=0;
            ll x=0;
            while(a[i]>0){
                if(a[i]%2==1)x=j;
                a[i]/=2;
                j++;
            }
            ans[x]++;
        }
        ll anss=0;
        for(ll i=0;i<=30;i++){
            if(ans[i]>anss)anss=ans[i];
        }
        cout<<anss<<endl;
    }
    return 0;
}
