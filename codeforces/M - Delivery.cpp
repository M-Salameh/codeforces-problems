#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define V vector<int>
#define Vv vector<vector<int>>
#define Vp vector<pair<int, int>>
#define No cout << "NO" << Endl
#define Yes cout << "YES" << Endl
#define ll long long
#define Pb push_back
#define S second
#define F first
using namespace std;

int modo=1e9+7;
const int NN = 1e7+2;

int pw(int x, int y)
{
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x)%modo;
        y = (y >> 1)%modo;
        x = (x * x)%modo;
    }
    return res ;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int Tc=1;
    cin>>Tc;
    while(Tc--)
    {
       int x;cin>>x;
       if(x==1){cout<<-1<<endl;continue;}
       if(x%2==1)
       {
           cout<<(x-1)/2<<" "<<(x-1)/2+1<<endl;
           continue;
       }
       bool ok=false;
       int l=-1,r=-1;
       for(int k=2;k<=sqrt(2*x)+1;k++)
       {
           int a=x-(k*(k-1))/2;
           if(a%k==0)
           {
               if(a+k*(k-1)/2==x)
               {
                   ok=true;
                    l=a/k;r=a/k+k-1;
                    break;
               }
           }
       }
       if(ok)cout<<l<<" "<<r<<endl;
       else cout<<-1<<endl;
    }
    return 0;
}
