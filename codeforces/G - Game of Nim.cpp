///https://codeforces.com/gym/104772/problem/G
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int NN = 5e5+5;
const int inf = 8e18;
int tc = 1;
int n, m, p;
int dp[512][501][501];

int solve(int pxor , int rem , int num)
{
    if (pxor == 0 and rem == 0) return 1;
    if (num > n-p) return 0;
    if (rem > n-p) return 0;
    if (rem < num) return 0;

    int& ret = dp[pxor][rem][num];
    if (ret + 1) return ret;

    ret = solve(pxor^num , rem-num , num)%m + solve(pxor , rem , num+1)%m;
    ret += m;
    ret %= m;
    return ret;
}

signed main()
{
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> p >> m;
        memset(dp , -1 , sizeof dp);
        cout << solve(p , n-p , 1) << endl;

    }

    return 0;
}
