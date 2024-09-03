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
        int n;cin>>n;
        map<int,int>cnt;
        for(int i=1;i<=n;i++)
        {
            int k;cin>>k;
            for(int j=1;j<=k;j++)
            {
                int x;cin>>x;cnt[x]++;
            }
        }
        int ans=0;
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            if(cnt[i]>n/2){ans++;v.push_back(i);}
        }
        cout<<ans<<endl;
        for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;
    }
    return 0;
}
