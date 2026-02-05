#include <bits/stdc++.h>
#include <math.h>
///#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
using namespace std;

int tc=1;
const int inf = 1e8;
int n;

vector<int> arr;

///E. Block Sequence

vector<int>dp;

int solve(int pos)
{
    if (pos > n+1) return inf;
    if (pos == n+1) return 0;
    if (dp[pos]+1) return dp[pos];

    int p1 = 1 + solve(pos+1);

    int p2 = solve(pos + arr[pos]+1);

    return dp[pos] = min(p1 , p2);
}

void read()
{
    cin >> n;
    arr = vector<int>(n+1,0);
    for (int i=1 ; i<=n ; i++) cin >> arr[i];
    dp = vector<int>(n+1 , -1);
    cout << solve(1) << endl;
}


signed main()
{
    fast

    cin >> tc;

    while(tc--)
    {
        read();
    }

    return 0;
}
