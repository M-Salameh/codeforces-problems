#include <bits/stdc++.h>
#define int long long
#define endl '\n'

int n;

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;

    vector<int> arr (n+1,0);
    vector<vector<int>> dp (n+2 , vector<int>(n+2,0));

    for (int i=1;i<=n ; i++)
    {
        cin >> arr[i];
    }
    for (int i=n ; i>=1 ; i--)
    {
        for (int j=i ; j<=n; j++)
        {
            dp[i][j] = max (arr[i]-dp[i+1][j] , arr[j]-dp[i][j-1]);
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}
