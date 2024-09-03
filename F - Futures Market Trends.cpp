#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
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

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int Tc=1;
    //cin>>Tc;
    while(Tc--)
    {
        int n;cin>>n;
        double p;cin>>p;
        double np=(double)0-p;
        int a[3100];
        for(int i=1;i<=n;i++)cin>>a[i];
        int ansp=0,ansn=0;
        int dif[3100];
        int dif2[3100];
        for(int i=2;i<=n;i++)
        {
            dif[i]=a[i]-a[i-1];
            dif2[i]=dif[i]*dif[i];
        }
        dif[1]=0;
        dif2[1]=0;
        int pre1[3100],pre2[3100];
        for(int i=2;i<=n;i++)
        {
            pre1[i]=dif[i]+pre1[i-1];
            pre2[i]=dif2[i]+pre2[i-1];
        }

        for(int l=1;l<=n;l++)
        {
            for(int r=l+2;r<=n;r++)
            {
                int A=pre1[r]-pre1[l];
                double Ad=(double)A;
                Ad=Ad/(r-l);
                int d=pre2[r]-pre2[l];
                int d2=pre1[r]-pre1[l];
                double D=(double)d2;
                D=-2*Ad*D;
                D+=(double)d;
                D+=Ad*Ad*((double)(r-l));
                D/=(double)(r-l);
                D=sqrt(D);
                double P;
                if(D==0&&A>0)ansp++;
                else if(D==0&&A<0){ansn++;}
                else if(D!=0)
                {
                    P=Ad/D;
                    if(P>=p)ansp++;
                    else if(P<=np)ansn++;
                }
            }
        }
        cout<<ansp<<" "<<ansn<<endl;
    }
    return 0;
}
