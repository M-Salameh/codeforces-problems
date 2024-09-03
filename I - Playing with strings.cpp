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
        string s1,s2;
        cin>>s1>>s2;
        int cnt1[2220],cnt2[2220];
        for(int i=1;i<=2000;i++){cnt1[i]=0;cnt2[i]=0;}
        for(int i=0;i<s1.size();i++){
            cnt1[(int)s1[i]]++;
        }
        for(int i=0;i<s2.size();i++){
            cnt2[(int)s2[i]]++;
        }
        int ans=0;
        for(int i=1;i<=2000;i++){
            ans+=abs(cnt2[i]-cnt1[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
