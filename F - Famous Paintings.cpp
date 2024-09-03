#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define int long long
using namespace std;
ll modo=1000000007;

ll pw(ll a,ll b){
    if(b==0)return 1;
    ll res=pw(a,b/2)%modo;
    res=(res*res)%modo;
    if(b&1)res=(res*a)%modo;
    return res%modo;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x,y;
        pair<int,int>a[200];
        for(int i=1;i<=n;i++){
            cin>>x>>y;
            a[i]={x,y};
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int x1=a[i].first,y1=a[i].second;
            for(int j=i+1;j<=n;j++){
                int x2=a[j].first,y2=a[j].second;
                for(int k=j+1;k<=n;k++){
                    int x3=a[k].first,y3=a[k].second;
                    for(int d=k+1;d<=n;d++){
                        int x4=a[d].first,y4=a[d].second;
                        if(!((y2-y1)*(x3-x2)==(y3-y2)*(x2-x1) or (y3-y2)*(x4-x3)==(y4-y3)*(x3-x2) or (y4-y3)*(x1-x4)==(y1-y4)*(x4-x3) or (y1-y4)*(x2-x1)==(y2-y1)*(x1-x4)))ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}