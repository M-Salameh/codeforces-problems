#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
int n;
const int NN = 5050;
int arr[NN];
int dp[NN][NN];

int solve(int i=1 , int j = n)
{
    if (j < i) return 0;
    int& ret = dp[i][j];
    if (ret + 1) return ret;
    int temp = n - (j-i);

    int p1 = temp*arr[i] + solve(i+1 , j);
    int p2 = temp*arr[j] + solve(i , j-1);

    return ret = max(p1,p2);
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=1 ; i<=n ; i++) cin >> arr[i];
    memset(dp , -1 , sizeof dp);
    cout << solve() << endl;
    return 0;
}
