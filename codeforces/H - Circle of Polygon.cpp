#include <bits/stdc++.h>
//#define int long long
#define double long double
#define endl '\n'
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <math.h>
#include <string.h>
#define ll long long
#define pi 3.14159265358979323846
using namespace std;
ll pw(ll a,ll b){
    if(b==0)return 1;
    ll res=pw(a,b/2);
    res=(res*res);
    if(b&1)res=(res*a);
    return res;
}
int main()
{
    fast;
   double v,s;
   cin>>v>>s;
   double r=s/(2*sin(pi/v));
   double a=pi*r*r;
   cout<<fixed<<setprecision(9)<<a<<endl;
    return 0;
}
