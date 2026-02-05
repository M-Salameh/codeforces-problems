#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll modo=1000000007;

ll pw(ll a,ll b){
    if(b==0)return 1;
    ll res=pw(a,b/2)%modo;
    res=(res*res)%modo;
    if(b&1)res=(res*a)%modo;
    return res%modo;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t=1;
    cin>>t;
    while(t--){
        ll m,n;
        cin>>m>>n;
        ll x=n;
        ll d=0;
        while(x>0){
            x/=10;
            d++;
        }
        ll xx=(pw(10,d)+modo)%modo;
        xx=(xx-1)%modo;
        xx=(xx+modo)%modo;
        x=pw(10,m*d);
        x=(x+modo)%modo;
        x=(x-1)%modo;
        x=(x+modo)%modo;
        x=(x*pw(xx,modo-2))%modo;
        x=(x+modo)%modo;
        x=(x*n)%modo;
        x=(x+modo)%modo;
        cout<<x<<endl;
    }
    return 0;
}
