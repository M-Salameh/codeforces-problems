#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define MOD 1000000007
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define all(x) x.begin()+1,x.end()
#define all0(x) x.begin(),x.end()
#define double long double
#pragma once
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define endl '\n'


using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 1e15+7;
int n , m;
int arr[2][100100];
int dp[3][100100];

int solve(int i=1 , int last = 2)
{
    if (i == n+1) return 0;
    int& ret = dp[last][i];
    if (ret + 1) return ret;

    ret = max(ret ,solve(i+1, last));

    if (last != 0) ret = max (ret , arr[0][i] + solve(i+1 , 0));
    if (last != 1) ret = max (ret , arr[1][i] + solve(i+1 , 1));

    return ret;
}

signed main()
{
    fast;
    ///cin >> tc;
    while(tc--)
    {
        cin >> n;
        for (int i=0 ; i<2 ; i++) for (int j=1  ; j<=n ; j++) cin >> arr[i][j];

        memset(dp , -1 , sizeof dp);

        cout << solve() << endl;
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
