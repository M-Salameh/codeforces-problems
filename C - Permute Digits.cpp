#include <bits/stdc++.h>
#define ll long long
//#define endl '\n'
#define int long long
using namespace std;

ll pw(ll x, ll y)
{
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x);
        y = (y >> 1);
        x = (x * x);
    }
    return res ;
}

int modo=1000000007;
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int Tc=1;
    //cin>>Tc;
    while(Tc--)
    {
        int a,b;
        cin>>a>>b;
        vector<int>ad,bd;
        vector<int>vis(100,0);
        int aa=a,bb=b;
        while(aa>0)
        {
            ad.push_back(aa%10);
            aa/=10;
        }
        while(bb>0)
        {
            bd.push_back(bb%10);
            bb/=10;
        }
        sort(ad.begin(),ad.end());
        if(bd.size()>ad.size())
        {
            int ans=0;
            for(int i=0;i<ad.size();i++)ans+=ad[i]*pw(10,i);
            cout<<ans<<endl;
            continue;
        }
        int n=bd.size();
        vector<int>t;
        int ans=0;
        if(a<=b)ans=a;
        for(int i=n-1;i>=0;i--)
        {
            //cout<<bd[i]<<endl;
            int x=-1,idx=-1;
            for(int j=ad.size()-1;j>=0;j--)
            {
                if(ad[j]<bd[i]&&vis[j]==0)
                {
                    x=ad[j];
                    idx=j;
                    break;
                }
            }
           // cout<<"x= "<<x<<endl;
            if(x!=-1)
            {
                vis[idx]=1;
                vector<int>ansi;
                for(int j=0;j<t.size();j++)ansi.push_back(t[j]);
                ansi.push_back(x);
                for(int j=ad.size()-1;j>=0;j--)
                {
                    //if(ansi.size()==n)break;
                    if(vis[j]==0)ansi.push_back(ad[j]);
                }
                int p=0;
                for(int j=0;j<ansi.size();j++)
                {
                    p+=ansi[j]*pw(10,ansi.size()-1-j);
                }
                if(p>ans)ans=p;
                vis[idx]=0;
            }
            x=-1,idx=-1;
            for(int j=ad.size()-1;j>=0;j--)
            {
                if(ad[j]<=bd[i]&&vis[j]==0)
                {
                    x=ad[j];
                    idx=j;
                    break;
                }
            }
            if(x!=-1)
            {
                t.push_back(x);
                vis[idx]=1;
            }
            else break;
        }
        int p=0;
        for(int j=0;j<t.size();j++)
        {
            p+=t[j]*pw(10,t.size()-1-j);
        }
        if(p>ans)ans=p;
        cout<<ans<<endl;
    }
    return 0;
}
