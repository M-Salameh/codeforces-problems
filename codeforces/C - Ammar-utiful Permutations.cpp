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
        ll i=2;
        while(i<=n){
            cout<<i<<" ";
            i+=2;
        }
        i=1;
        while(i<=n){
            cout<<i<<" ";
            i+=2;
        }
        cout<<endl;
    }
    return 0;
}
