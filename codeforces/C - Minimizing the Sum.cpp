#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int mod = 1e9+7;
const int inf = 1e15+8;
const int NN = 3e5+5;
const int KK = 11;

int tc;
int n,k;
int dp[NN][KK];
int arr[NN];

void solve()
{
    for (int i=1 ; i<=n ; i++)
    {
        dp[i][0]= arr[i] + dp[i-1][0];
        int x = min(i-1 , k);
        for (int j=1 ; j<=x ; j++)
        {
            int mini = inf;
            for (int r = 0 ; r <= j ; r++)
            {
                mini = min(mini , arr[i-r]);
                dp[i][j] = min(dp[i][j] , mini+r*mini + dp[i-r-1][j-r]);
            }
        }
    }

    int ans = inf;
    for (int i=0 ; i<=k ; i++) ans = min (ans , dp[n][i]);
    cout << ans << endl;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> tc;
    while(tc--)
    {
        cin >> n >> k;
        for (int i=1 ; i<=n ; i++) cin >> arr[i];

        for (int i=0 ; i <= n; i++) for (int j=0 ; j<=k ; j++) dp[i][j] = inf;

        for (int i=0 ; i<=k ; i++) dp[0][i] = 0 , dp[1][i] = arr[1];

        solve();
    }
    return 0;
}
