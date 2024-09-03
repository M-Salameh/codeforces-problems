#include <bits/stdc++.h>
//#define int long long
#define double long double
//#define endl '\n'
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <math.h>
#include <string.h>
#define ll long long

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
    int x,y;
    cin>>x>>y;
    if(x>=y)cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}
