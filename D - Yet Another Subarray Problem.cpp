#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const int NN = 3e5+1;
const int MM = 12;
const int inf = 8e18;
int tc=1;
int arr[NN];
int n;
int m,k;
int dp[NN][MM];

/*
5 10 10
1000000000 1000000000 1000000000 1000000000 1000000000

*/

signed main()
{
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> m >> k;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
        }
        for (int i=1 ; i<=n ; i++)
        {
            dp[i][0] = max(dp[i-1][m-1] + arr[i] - k , arr[i]-k);
            for (int j=1 ; j<m and i-j>=1 ; j++)
            {
                dp[i][j] = dp[i-1][j-1] + arr[i];
            }
        }
        int ans = 0;
        for (int i=1; i<=n ; i++)
        {
            for (int j=0 ; j<m ; j++) ans = max(ans , dp[i][j]);
        }
        cout << ans << endl;
    }

    return 0;
}
