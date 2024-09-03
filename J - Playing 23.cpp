#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt[20];
        for(int i=1;i<=20;i++)cnt[i]=0;
        int xj,yj;cin>>xj>>yj;cnt[xj]++;cnt[yj]++;
        int xm,ym;cin>>xm>>ym;cnt[xm]++;cnt[ym]++;
        int add=0;
        int x;
        for(int i=1;i<=n;i++){
            cin>>x;
            cnt[x]++;
            add+=min(10,x);
        }
        int sm=min(10,xm)+min(10,ym)+add;
        int ans1=23-sm;
        if(ans1>10)ans1=100;
        else if(ans1==10){
            if(cnt[10]<4)ans1=10;
            else if(cnt[11]<4)ans1=11;
            else if(cnt[12]<4)ans1=12;
            else if(cnt[13]<4)ans1=13;
            else ans1=100;
        }
        else{
            if(cnt[ans1]==4)ans1=100;
        }
        int sj=min(10,xj)+min(10,yj)+add;
        int ans2=100;
        if(sj<sm)ans2=100;
        else{
            for(int x=24;x<=10+sj;x++){
                int y=x-sj;
                if(y==10){
                    if(cnt[10]<4)y=10;
                    else if(cnt[11]<4)y=11;
                    else if(cnt[12]<4)y=12;
                    else if(cnt[13]<4)y=13;
                    else y=100;
                }
                else{
                    if(cnt[y]==4)y=100;
                }
                if(sm+min(y,10)>23)y=100;
                ans2=min(ans2,y);
            }
        }
        int ans=min(ans1,ans2);
        if(ans==100)ans=-1;
        cout<<ans<<endl;
     }

    return 0;
}
