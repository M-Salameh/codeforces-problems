#include <bits/stdc++.h>
///#define int long long
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
#define mod %M
using namespace std;

const int M = 1e9+7;

int tc=1;
int n,k;

int dp[1000001];

int solve_rec(int sum)
{
    ///TLE!!!
    if (sum > n) return 0;
    if (sum == n) return 1;
    if (dp[sum] != -1) return dp[sum];
    dp[sum]++;
    for (int i=1 ; i <= sum ; i++)
    {
        dp[sum] = (dp[sum]mod + solve_rec(sum+i)mod)mod;
    }
    return dp[sum];
}


void solve2()
{
    ///TLE !!
    dp[1]=1;
    for (int i=1 ; i<=k ; i++)
    {
        for (int j=1 ; j<=i ; j++)
        {
            if (i+j>k) break;
            dp[i+j] += dp[i];
            dp[i+j] = dp[i+j] mod;
        }
    }
    cout << dp[k] <<endl;
}

void solve()
{
    long long pref[k+1];pref[0]=0;
    pref[1]=1;
    dp[1]=1;
    for (int i=2 ; i<=k ; i++)
    {
        dp[i] = (pref[i-1]-pref[(i-1)/2])mod;
        pref[i] = (dp[i]+pref[i-1]);
    }
    cout << dp[k] << endl;
}
/***
2022
o = 904964280;
10
o = 84
3
o = 1;
*/
signed main()
{
    fast;
   /// cin >> tc;
    while (tc--)
    {
        cin >> k;
        solve();
    }

    return 0;
}
