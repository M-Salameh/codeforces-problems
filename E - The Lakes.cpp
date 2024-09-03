#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int tc;
int n,m;

int arr[1001][1001];
bool vis[1001][1001];

void Read()
{
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=m ; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void reset()
{
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=m ; j++)
        {
            arr[i][j]=0;
            vis[i][j]=false;
        }
    }
}


int dfs(int i ,int j)
{
    if (i<=0 or j<=0 or j>m or i>n) return 0;
    if (vis[i][j]) return 0;
    if (arr[i][j]==0) return 0;
    vis[i][j] = true;
    int ans = arr[i][j];
    ans += dfs(i,j+1)+dfs(i,j-1)+dfs(i-1,j)+dfs(i+1,j);
    return ans;
}

void solve()
{
    int ans=0;
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=m ; j++)
        {
            if (arr[i][j]!=0 and !vis[i][j])
            {
                ans = max (ans , dfs(i,j));
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    fast;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> m ;
        Read();
        solve();
        reset();
    }
    return 0;
}
