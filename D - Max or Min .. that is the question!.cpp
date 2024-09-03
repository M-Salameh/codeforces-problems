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
        int n=5;
        int a[44];
        for(int i=1;i<=5;i++)cin>>a[i];
        sort(a+1,a+1+n);
        cout<<a[n]*a[n-1]<<endl;
    }
    return 0;
}
