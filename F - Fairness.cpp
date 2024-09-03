//https://codeforces.com/gym/101061/problem/F
#include <bits/stdc++.h>
///#define int long long
#define endl '\n'

using namespace std;

const int inf = 2e8+7;
int tc = 1;
const int NN = 1010;
int n;
vector<int> arr;
vector<int> pref;
vector<vector<int>> dp;

void solve()
{
    for (int i=1 ; i<=n ; i++)
    {
        dp[i][pref[i]] = pref[i];

        for (int my_sum = 0 ; my_sum <= pref[i] ; my_sum ++)
        {
            int diff = abs(pref[i] - 2*my_sum);
            dp[i][my_sum] = min (dp[i][my_sum] , max(dp[i-1][my_sum] , diff));

            if (my_sum < arr[i]) continue;
            dp[i][my_sum] = min(dp[i][my_sum] , max(dp[i-1][my_sum-arr[i]] , diff));
        }
    }

    int ans = inf;
    for (int i=0 ; i<=pref[n] ; i++)
    {
        ans = min (ans , dp[n][i]);
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> tc;
    while(tc--)
    {
        cin >> n;
        arr = vector<int> (n+1 , 0);
        pref = vector<int> (n+1 , 0);

        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
            pref[i] = pref[i-1] + arr[i];
        }

        dp = vector<vector<int>> (n+1 , vector<int>(pref[n]+5,2*pref[n]));
        solve();
    }
    return 0;
}

