#include <bits/stdc++.h>
///#define int long long
using namespace std;
vector <int> wt;
vector <int> val;
int n;
int W;

int knapSack()
{
    int dp[2][W+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 or j == 0) dp[i % 2][j] = 0;
            else if (wt[i - 1] <= j)
            {
                dp[i % 2][j] = max(val[i - 1]+ dp[(i - 1) % 2][j - wt[i - 1]], dp[(i - 1) % 2][j]);
            }
            else
            {
                dp[i % 2][j] = dp[(i - 1) % 2][j];
            }
        }
    }
    return dp[n % 2][W];
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> W;
    for (int i=0 ; i<n ; i++)
    {
        int x;
        cin >> x;
        wt.push_back(x);
        cin >> x;
        val.push_back(x);
    }
    int ans = knapSack();
    cout << ans << endl;
    return 0;
}
