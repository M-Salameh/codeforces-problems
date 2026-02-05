#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
int n;
const int inf = 1e9+7;
const int NN = 5050;
string s;
int dp[NN][NN];

int solve(int i=1 , int j=n)
{
    if (j < i) return 0;
    if (i == j) return 1;
    int& ret = dp[i][j];
    if (ret + 1) return ret;

    int p1 = 1 + solve (i+1 , j);
    int p2 = 1 + solve (i , j-1);

    int p3 = inf;
    for (int k = 1+i ; k <= j ; k++)
    {
        if (s[k] != s[i]) continue;
        p3 = min (p3 , solve(i+1,k-1) +solve(k,j));
    }

    return ret = min({p1, p2 , p3});
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;

    cin >> s;
    s = "$"+s;

    memset(dp , -1 , sizeof dp);
    cout << solve() << endl;
    return 0;
}
