#include <bits/stdc++.h>
#include <math.h>
#define int long long
#define endl '\n'
#include <string>
#define MOD 998244353
using namespace std;

int tc=1;

const int inf = 1e15;
int n;
int m,k;

vector<int> arr;
vector<vector<int>>dp;

int solve(int i , int j)
{
    if (i > n and j==k) return 0;
    if (i>n and j!=k) return -inf;
    if (j == k) return 0;
    if (n-i+1 < m) return 0;
    int& ret  = dp[i][j];
    if (ret + 1) return ret;
    int p1 = arr[i+m-1] - arr[i-1] + solve(i+m , j+1);
    int p2 = solve(i+1 , j);
    return ret = max(p1,p2);
}
void solveRec()
{
    cin >> n >> m >> k;
    arr.resize(n+1);
    for (int i=1 ; i<=n ; i++)
    {
        int x;
        cin >> x;
        arr[i] = arr[i-1] + x;
    }
    dp = vector<vector<int>>(n+1 , vector<int>(k+1 , -1));
    cout << solve(1,0) << endl;
    return;
}

void solveIter()
{
    cin >> n >> m >> k;
    arr.resize(n+1);
    for (int i=1 ; i<=n ; i++)
    {
        int x;
        cin >> x;
        arr[i] = arr[i-1] + x;
    }
    dp = vector<vector<int>>(n+1 , vector<int>(k+1 , 0));
    for (int i=m ; i<=n  ; i++)
    {
        for (int j=1 ; j<=k ; j++)
        {
            ///dp[i][j] = max(max(dp[i][j] , dp[i-1][j-1]) , max(dp[i-1][j] , dp[i-1][j-m]+arr[i-m+1]-arr[i]));
            dp[i][j] = max(dp[i-1][j] , dp[i-m][j-1] + arr[i] - arr[i-m]);
        }
    }

    cout << dp[n][k] << endl;

    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ///cin >> tc;

    while(tc--)
    {
        solveIter();
    }

    return 0;
}
