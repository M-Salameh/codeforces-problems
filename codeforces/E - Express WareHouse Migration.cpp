#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define s second
#define f first
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
int main()
{
    fastio;
    ll tt=1;
    //cin>>tt;
    while(tt--)
    {
   ll n,m;
   cin>>n>>m;
   cout<<n/m+(n%m>0)<<endl;
}
    return 0;
}
 