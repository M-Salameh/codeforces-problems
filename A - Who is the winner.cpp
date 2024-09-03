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
signed main()
{
    fast;
    cin>>tc;
    while(tc--)
    {
    ll h1,m1,s1,h2,m2,s2;
    cin>>h1>>m1>>s1>>h2>>m2>>s2;
    ll t1=h1*3600+m1*60+s1,t2=h2*3600+m2*60+s2;
    if(t2>t1)cout<<"Player1"<<endl;
    else if(t1>t2)cout<<"Player2"<<endl;
    else cout<<"Tie"<<endl;
    }
    return 0;
}
