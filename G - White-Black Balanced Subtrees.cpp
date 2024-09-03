#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int tc=1;
int n;

int arr[5000];
int parent[5000];
bool vis[5000];
int dp[5000];
vector<int>adj[5000];
int ans;

int dfs(int src)
{
    if (vis[src]) return dp[src];
    vis[src] = true;
    int sum = arr[src];
    for (auto i : adj[src])
    {
        sum += dfs(i);
    }
    dp[src] = sum;
    if (sum==0) ans++;
    return dp[src];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>tc;
    while(tc--)
    {
        cin >> n;
        ans=0;
        parent[1]=1;
        for (int i=2 ; i<=n  ;i++)
        {
            int x;
            cin >> x;
            parent[i]=x;
            adj[x].push_back(i);
        }
        string s;
        cin >> s;
        for (int i=0 ;i<s.size() ;i++)
        {
            if (s[i]=='W')
            {
                arr[i+1]=1;
            }
            else arr[i+1]=-1;
        }

        int g = dfs(1);
        cout << ans << endl;

        for(int i=1 ; i<= n;i++)
        {
            arr[i]=0;
            parent[i]=0;
            dp[i]=0;
            vis[i]=false;
            adj[i].clear();
        }
    }

    return 0;
}
