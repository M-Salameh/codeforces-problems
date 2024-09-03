#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int inf = 1e9+7;
int tc = 1;
const int NN = 1e6+6;
int n,m;
int dp[NN] , arr[NN], pre[NN] , sum[NN];

void solve()
{
    pre[0] = 0;

    for (int i=1 ; i<=n ; i++) sum[i] = sum[i-1] + arr[i];

    for (int i=n ; i ; i--) pre[i] = min (pre[i] , pre[i+1]);

    for (int i=1 ; i<=n ; i++)
    {
        dp[i] = max (dp[i-1] , sum[i] + dp[pre[i]-1]);
    }

    cout << dp[n] << endl;
    return;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        for (int i=0 ; i<=n+3 ; i++)
        {
            pre[i] = i;
            dp[i] = sum[i] = 0;
            arr[i] = 0;
        }
        for (int i=1 ; i<=m ; i++)
        {
            int l,r;
            cin >> l >> r;
            arr[l]++;
            arr[r+1]--;
            pre[r] = min (l , pre[r]);
        }
        solve();
    }

    return 0;
}
