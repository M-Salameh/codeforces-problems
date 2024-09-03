#include <bits/stdc++.h>
#define ll long long
#define MOD %1000000007
#define starr(dp) memset(dp , 0, sizeof(dp))
#define ll long long
#define endl '\n'
using namespace std;

ll dp[500][2];
ll n , k , d;

ll Ktree (ll sum , bool flag)
{
    if (sum > n) return 0;
    if (sum == n) return flag;
    if (dp[sum][flag] != 0)
    {
        return dp[sum][flag];
    }

    for (ll i=1; i<=k ; i++)
    {
        dp[sum][flag] = (((dp[sum][flag])MOD + Ktree(sum+i , flag || (i>=d))MOD)MOD);
    }
    return dp[sum][flag];
}

void Read()
{
    starr(dp);
    cin >> n >> k >> d ;
    cout << Ktree(0,0) <<endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Read();
    return 0;
}
