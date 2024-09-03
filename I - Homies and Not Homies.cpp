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

const int modo=1e9+7;
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

int a[200100];
int to[200100];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int Tc=1;
    cin>>Tc;
    while(Tc--)
    {
        int n;cin>>n;
        int ans=n;
        int k=0;
        int nn=n;
        while(nn>0)
        {
            nn/=2;k++;
        }
        k--;
        n=n-(1<<k)+1;
        for(int i=2;i<k;i+=2)
        {
            for(int j=i;j<k;j++)
            {
                ans+=(1<<(j-1));
            }
            int add=(n/(1<<(k+1-i)))*(1<<(k-i))+max(0ll,(n%(1<<(k+1-i))-(1<<(k-i))));
            ans+=add;
        }
        if(k%2==0)ans+=(n/2)+max(0ll,n%2-1);
        cout<<ans<<endl;
    }
    return 0;
}
