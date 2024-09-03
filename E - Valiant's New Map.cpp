#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'

using namespace std;

int tc;
int n , m;

int fill_dp(int i , int j , int val , int** dp , int** arr )
{
    return 0;
}

void solve()
{
    int arr[n+1][m+1];
    for (int i=1 ;i<=n ; i++)
        for (int j=1 ;j<=m;j++) cin >> arr[i][j];

    int dp[n+1][m+1];
    memset(dp , 0 , sizeof(dp));
    fill_dp(1,1,-1 , dp , arr);

}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while (tc--)
    {
        cin >> n >> m ;
        solve();
    }
    return 0;
}
