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
        ll q;
        cin>>q;
        ll x=0;
        while(q%2==0){
            x++;
            q/=2;
        }
        if(x%2==0)cout<<"First Box"<<endl;
        else cout<<"Second Box"<<endl;
    }
    return 0;
}
