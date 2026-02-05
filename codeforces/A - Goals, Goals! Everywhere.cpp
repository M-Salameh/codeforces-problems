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

const int Mod=998244353;
const int NN = 1e7+2;

int pw(int x, int y)
{
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x)%Mod;
        y = (y >> 1)%Mod;
        x = (x * x)%Mod;
    }
    return res ;
}

int a[300100];

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int Tc=1;
    cin>>Tc;
    while(Tc--)
    {
       int n;cin>>n;
       for(int i=1;i<=n;i++)cin>>a[i];
       sort(a+1,a+1+n);
       int sum=0;
       for(int i=1;i<=n;i++)sum+=a[i];
       if(a[n]>sum-a[n])cout<<a[n]<<" "<<sum<<endl;
       else cout<<(sum+1)/2<<" "<<sum<<endl;
    }
    return 0;
}
