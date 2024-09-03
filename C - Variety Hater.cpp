///https://codeforces.com/gym/105264/problem/C
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int inf = 1e14+8;
const int NN = 5e3+5;
int n , tc=1;
int k;
int arr[NN] , pref[NN];
vector<vector<int>> dp , cost;

void solve()
{
    for (int i=1 ; i<=n ; i++)
    {
        cost[i][i] = 0;
        for (int j=i+1 ; j<=n ; j++)
        {
            for (int k=i ; k<=j ; k++)
            {
                int before = (k-i+1)*arr[k] - (pref[k]-pref[i-1]);
                int after = -(j-k+1)*arr[k] + (pref[j]-pref[k-1]);
                cost[i][j] = min (cost[i][j] , before+after);

                ///cout << "cost["<<i<<"]["<<j<<"]=" << cost[i][j] << endl;
                ///cout << "b4 = " << before << " and after = " << after << endl;
            }
        }
    }

    ///cout << "fufufufu" << endl;
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=i ; j++)
        {
            for (int k=i ; k>=j ; k--)
            {
                ///cout << "dp["<<k-1<<"]["<<j-1<<"]="<< dp[k-1][j-1] << endl;
                dp[i][j] = min (dp[i][j] , dp[k-1][j-1] + cost[k][i]);
            }
        }
    }

    ///cout << "HH" << endl;
    for (int i=1 ; i<=n ; i++)
    {
        ///cout << dp[n][i]<< endl;
        if (dp[n][i] <= k)
        {
            cout << i << endl;
            return;
        }
    }

}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n >> k;
        for (int i=1 ; i <= n; i++)
        {
            cin >> arr[i];
        }
        sort(arr+1 , arr + 1 + n);
        for (int i=1 ; i<=n ; i++) pref[i] = pref[i-1] + arr[i];
        dp = vector<vector<int>> (n+1 , vector<int>(n+1 , inf));
        cost = vector<vector<int>> (n+1 , vector<int>(n+1 , inf));
        dp[1][1] = dp[0][0] = 0;
        solve();
    }

    return 0;
}
