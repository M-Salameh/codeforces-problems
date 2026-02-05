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

int a[200100],b[200100];
int aa[200100];
signed main()
{
    int Tc=1;
    Fastio;
    //cin>>Tc;
    while(Tc--)
    {
        int n;cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        sort(a+1,a+1+n);sort(b+1,b+1+n);
        for(int i=1;i<=n;i++)
        {
            int id=upper_bound(b+1,b+1+n,a[i])-b;
            if(id==n+1)aa[i]=-1;
            else aa[i]=id;
        }
        int r=0,l=0;
        int id=n;
        for(int i=n;i>=1;i--)
        {
            if(id==0)break;
            if(aa[i]==-1){r++;id--;}
            else
            {
                int x=min(aa[i]-1,id);
                if(x==0)break;
                r++;
                id=x-1;
            }
        }
        id=n;
        for(int i=n;i>=1;i--)
        {
            if(aa[i]==-1)
            {
                l++;
            }
            else
            {
                if(id>=aa[i])
                {
                    id--;
                }
                else l++;
            }
        }
        cout<<r-l+1<<endl;
        for(int i=l;i<=r;i++)cout<<i<<" ";cout<<endl;
    }
    return 0;
}


