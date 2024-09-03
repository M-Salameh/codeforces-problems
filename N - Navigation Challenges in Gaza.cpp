//https://codeforces.com/gym/538311/problem/O
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int inf = 1e18+8;
const int NN = 5e5+5;
int n , tc=1;
int arr[NN];
int pref[NN];
int dp[NN];

void solve()
{
    for (int i=2 ; i<=n ; i++)
    {
        int j = i-1;
        while (j)
        {
            if (pref[i-1] - pref[j-1] >= arr[i])
            {
                dp[i] = j;
                break;
            }
            j = dp[j];
        }
    }
    int ans = 0;
    for (int i=1 ; i<=n ; i++)
    {
        int x = (dp[i] > 0);
        x *= i-dp[i];
        ans += x;
    }
    cout << ans << endl;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ///cin >> tc;
    while(tc--)
    {
        cin >> n;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
            pref[i] = pref[i-1] + arr[i];
        }
        solve();
    }

    return 0;
}
