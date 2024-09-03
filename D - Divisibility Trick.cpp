#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int int64_t
#define Pb push_back
#define S second
#define F first
#define Fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Endl '\n'
#define V vector<int>
#define Vv vector<vector<ll>>
#define Vp vector<pair<ll,ll>>
#define No cout << "NO" << Endl
#define Yes cout << "YES" << Endl

const int N = 3e5 + 1, De = (1 << 19), inf = 3e18;
int n;
vector<int> adj[N];
int dp[35][N];
int arr[N];

void clearr()
{
    for (int i=0 ; i<=n ; i++)
    {
        adj[i].clear();
        for (int j=1 ; j<=23 ; j++)
        {
            dp[j][i] = 0;
        }
    }
}

void dfs(int node=1 , int parent = 0)
{
    for (int i=1 ; i<=24 ; i++) dp[i][node] = arr[node] * i;

    for (int child : adj[node])
    {
        if (child == parent) continue;
        dfs(child , node);

        int temp = 5e18;
        for (int i=1 ; i<=23 ; i++)
        {
            for (int j=1 ; j<=23 ; j++)
            {
                if (i==j) continue;
                temp = min (temp , dp[j][child]);
            }
            dp[i][node] += temp;
        }
    }
}

void solve()
{
    dfs();
    int ans = 1e18;
    for (int i=1 ; i<=22 ; i++)
    {
        ans = min (ans , dp[i][1]);
    }

    cout << ans << Endl;
}


signed main()
{
    int Tc=1;
    Fastio;
    //cin>>Tc;
    while(Tc--)
    {
        int d;cin>>d;
        int sum=0;
        int kk=d;
        while(kk>0)
        {
            sum+=kk%10;kk/=10;
        }
        int x=sum*d;
        for(int i=1;i<=x;i++)cout<<d;cout<<endl;
    }
    return 0;
}


