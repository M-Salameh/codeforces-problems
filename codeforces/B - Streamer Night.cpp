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
const int inf = 1e9+7;
int n , k;
vector<int> idx[200200];
vector<int> dp;
vector<int> arr;

int solve(int i=1)
{
    if (i == n+1) return 0;
    int& ret = dp[i];
    if (ret+1) return ret;
    ret = solve(i+1);
    for (auto j : idx[i])
    {
        ret = max (ret , 1+solve(j));
    }
    return ret;
}

signed main()
{
    fast;
    ///cin >> tc;
    while(tc--)
    {
        cin >> n >> k;
        dp = vector<int> (n+1 , -1);
        for (int i=1 ; i<=k ; i++)
        {
            int ai,bi;
            cin >> ai >> bi;
            ///if (idx[ai].size() == 0) arr.push_back(ai);
            idx[ai].push_back(bi);
        }
        cout << solve() << endl;
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
