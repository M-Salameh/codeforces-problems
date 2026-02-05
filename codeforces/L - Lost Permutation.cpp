#include <bits/stdc++.h>
#define ll long long
//#define endl '\n'
#define int long long
using namespace std;

//int modo=1000000007;

int pw(int a,int b){
    if(b==0)return 1;
    int res=pw(a,b/2);
    res=(res*res);
    if(b&1)res=(res*a);
    return res;
}
int b1[10100],b2[10100],ans1[10100],ans2[10100],p[10100];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int Tc=1;
    cin>>Tc;
    while(Tc--)
    {
        int n;cin>>n;
        for(int i=1;i<=n;i++)p[i]=0;
        for(int i=1;i<=n;i++)
        {
            b1[i]=n+1-i;
        }
        for(int i=1;i<=n;i++)
        {
            if(i==1)b2[i]=1;
            else if(i==n)b2[i]=2;
            else b2[i]=i+1;
        }
        cout<<"? ";
        for(int i=1;i<=n;i++)cout<<b1[i]<<" ";cout<<endl;
        for(int i=1;i<=n;i++)cin>>ans1[i];

        cout<<"? ";
        for(int i=1;i<=n;i++)cout<<b2[i]<<" ";cout<<endl;
        for(int i=1;i<=n;i++)cin>>ans2[i];

        int id=0;
        for(int i=1;i<=n;i++)
        {
            if(ans2[i]==i)
            {
                id=i;
                p[i]=1;
            }
            if(ans1[i]==i)
            {
                p[i]=(n+1)/2;
            }
        }
        p[ans1[id]]=n;
        int id2=ans1[id];
        bool ok=true;
        int i=id2;
        while(ok)
        {
            if(p[i]==n)p[ans2[i]]=2;
            else p[ans2[i]]=p[i]+1;
            i=ans2[i];
            if(i==id2)ok=false;
        }

        int ans[10100];
        for(int i=1;i<=n;i++)
        {
            ans[p[i]]=i;
        }
        cout<<"! ";
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
    }
    return 0;
}
