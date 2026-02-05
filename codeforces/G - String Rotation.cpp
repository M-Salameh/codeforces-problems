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

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int Tc=1;
    //cin>>Tc;
    while(Tc--)
    {
        int n,x;cin>>n>>x;
        string s,t;
        cin>>s>>t;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[(i+x)%n])ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
