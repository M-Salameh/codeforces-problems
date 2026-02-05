#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define Pb push_back
#define S second
#define F first
#define Fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define Endl '\n'
#define V vector<int>
#define Vv vector<vector<ll>>
#define Vp vector<pair<ll,ll>>
#define No cout << "NO" << Endl
#define Yes cout << "YES" << Endl
#define endl '\n'

const int NN = 2e5 + 6;
const int inf = 2e18;

int x[100100];
int y[100100];
int n;


bool solve(int idd)
{
        int xx,yy;xx=x[1];yy=y[idd];
        bool ok=true;
        for(int i=1;i<=n;i++)
        {
            if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
            else
            {
                ok=false;break;
            }
        }
        if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}

        yy=xx-x[idd]+y[idd];
        ok=true;
        for(int i=1;i<=n;i++)
        {
            if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
            else
            {
                ok=false;break;
            }
        }
        if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}

        yy=x[idd]+y[idd]-xx;
        ok=true;
        for(int i=1;i<=n;i++)
        {
            if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
            else
            {
                ok=false;break;
            }
        }
        if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}

        xx=x[idd];yy=y[1];
        ok=true;
        for(int i=1;i<=n;i++)
        {
            if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
            else
            {
                ok=false;break;
            }
        }
        if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}

        yy=xx-x[1]+y[1];
        ok=true;
        for(int i=1;i<=n;i++)
        {
            if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
            else
            {
                ok=false;break;
            }
        }
        if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}

        yy=x[1]+y[1]-xx;
        ok=true;
        for(int i=1;i<=n;i++)
        {
            if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
            else
            {
                ok=false;break;
            }
        }
        if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}

        yy=y[idd];xx=yy-y[1]+x[1];
        ok=true;
        for(int i=1;i<=n;i++)
        {
            if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
            else
            {
                ok=false;break;
            }
        }
        if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}

        xx=y[1]+x[1]-yy;
        ok=true;
        for(int i=1;i<=n;i++)
        {
            if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
            else
            {
                ok=false;break;
            }
        }
        if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}

        yy=y[1];xx=yy-y[idd]+x[idd];
        ok=true;
        for(int i=1;i<=n;i++)
        {
            if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
            else
            {
                ok=false;break;
            }
        }
        if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}

        xx=y[idd]+x[idd]-yy;
        ok=true;
        for(int i=1;i<=n;i++)
        {
            if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
            else
            {
                ok=false;break;
            }
        }
        if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}


        if((y[idd]+x[idd]+y[1]-x[1])%2==0)
        {
            yy=(y[idd]+x[idd]+y[1]-x[1])/2;
            xx=y[idd]+x[idd]-yy;
        }
        ok=true;
        for(int i=1;i<=n;i++)
        {
            if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
            else
            {
                ok=false;break;
            }
        }
        if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}

        if((y[1]+x[1]+y[idd]-x[idd])%2==0)
        {
            yy=(y[1]+x[1]+y[idd]-x[idd])/2;
            xx=y[1]+x[1]-yy;
        }
        ok=true;
        for(int i=1;i<=n;i++)
        {
            if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
            else
            {
                ok=false;break;
            }
        }
        if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}

        if(y[1]+x[1]==y[idd]+x[idd])
        {
            bool ok2=true;
            int id=-1;
            for(int i=1;i<=n;i++)
            {
                if(y[i]+x[i]==y[1]+x[1])continue;
                else
                {
                    ok2=false;
                    id=i;
                    break;
                }
            }
            if(ok2)
            {
                cout<<"YES"<<endl;cout<<x[1]<<" "<<y[1]<<endl;return true;
            }
            else
            {
                yy=y[id];xx=y[1]+x[1]-yy;
                ok=true;
                for(int i=1;i<=n;i++)
                {
                    if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
                    else
                    {
                        ok=false;break;
                    }
                }
                if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}

                xx=x[id];yy=y[1]+x[1]-xx;
                ok=true;
                for(int i=1;i<=n;i++)
                {
                    if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
                    else
                    {
                        ok=false;break;
                    }
                }
                if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}

                if((y[1]+x[1]+y[id]-x[id])%2==0)
                {
                    yy=(y[1]+x[1]+y[id]-x[id])/2;
                    xx=y[1]+x[1]-yy;
                }
                ok=true;
                for(int i=1;i<=n;i++)
                {
                    if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
                    else
                    {
                        ok=false;break;
                    }
                }
                if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}
            }
        }

        if(y[1]-x[1]==y[idd]-x[idd])
        {
            bool ok2=true;
            int id=-1;
            for(int i=1;i<=n;i++)
            {
                if(y[i]-x[i]==y[1]-x[1])continue;
                else
                {
                    ok2=false;
                    id=i;
                    break;
                }
            }
            if(ok2)
            {
                cout<<"YES"<<endl;cout<<x[1]<<" "<<y[1]<<endl;return true;
            }
            else
            {
                yy=y[id];xx=yy-y[1]+x[1];
                ok=true;
                for(int i=1;i<=n;i++)
                {
                    if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
                    else
                    {
                        ok=false;break;
                    }
                }
                if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}

                xx=x[id];yy=y[1]-x[1]+xx;
                ok=true;
                for(int i=1;i<=n;i++)
                {
                    if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
                    else
                    {
                        ok=false;break;
                    }
                }
                if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}

                if((y[1]-x[1]+y[id]+x[id])%2==0)
                {
                    yy=(y[1]-x[1]+y[id]+x[id])/2;
                    xx=yy-y[1]+x[1];
                }
                ok=true;
                for(int i=1;i<=n;i++)
                {
                    if(xx==x[i]||yy==y[i]||yy+xx==x[i]+y[i]||yy-xx==y[i]-x[i])continue;
                    else
                    {
                        ok=false;break;
                    }
                }
                if(ok){cout<<"YES"<<endl;cout<<xx<<" "<<yy<<endl;return true;}
            }
        }
        return false;
}

signed main()
{
    int Tc=1;
    Fastio;
    cin>>Tc;
    while(Tc--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int xx,yy;cin>>xx>>yy;x[i]=xx;y[i]=yy;
        }
        if(n==1)
        {
            cout<<"YES"<<endl;
            cout<<x[1]<<" "<<y[1]<<endl;
            continue;
        }
        if(n==2)
        {
            cout<<"YES"<<endl;
            cout<<x[1]<<" "<<y[2]<<endl;
            continue;
        }

        bool ok=solve(2);
        if(ok)continue;
        int idd=1;
        for(int i=2;i<=n;i++)
        {
            if(x[i]!=x[1])
            {
                idd=i;
                break;
            }
        }
        if(idd==1)
        {
            cout<<"YES"<<endl;
            cout<<x[1]<<" "<<y[1]<<endl;
            continue;
        }
        ok=solve(idd);
        if(ok)continue;

        idd=1;
        for(int i=2;i<=n;i++)
        {
            if(y[i]!=y[1])
            {
                idd=i;
                break;
            }
        }
        if(idd==1)
        {
            cout<<"YES"<<endl;
            cout<<x[1]<<" "<<y[1]<<endl;
            continue;
        }
        ok=solve(idd);
        if(ok)continue;

        idd=1;
        for(int i=2;i<=n;i++)
        {
            if(y[i]+x[i]!=y[1]+x[1])
            {
                idd=i;
                break;
            }
        }
        if(idd==1)
        {
            cout<<"YES"<<endl;
            cout<<x[1]<<" "<<y[1]<<endl;
            continue;
        }
        ok=solve(idd);
        if(ok)continue;

        idd=1;
        for(int i=2;i<=n;i++)
        {
            if(y[i]-x[i]!=y[1]-x[1])
            {
                idd=i;
                break;
            }
        }
        if(idd==1)
        {
            cout<<"YES"<<endl;
            cout<<x[1]<<" "<<y[1]<<endl;
            continue;
        }
        ok=solve(idd);
        if(ok)continue;


        cout<<"NO"<<endl;
    }
    return 0;
}
