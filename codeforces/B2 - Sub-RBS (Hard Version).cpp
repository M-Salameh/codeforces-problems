#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast64_t
//#define pii pair<int,int>

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 2e18+1;
const int NN = 1e2+2;
//const int mod = 1e9+7;
const int mod = 998244353;
int tc=1;
int n ;
string s;
int dp [NN][NN][NN][4];
const int zero = 0;

void solve()
{
    dp[0][0][0][0] = 1;
    for (int idx=0 ; idx<n ; idx++)
    {
        int val = (s[idx] == '(' ? 1 : -1);
        for (int len=0 ; len <= n; len++)
        {
            for (int stk=0 ; stk <=n ; stk++)
            {
                // cout << "stack size balancing = " << stk << endl;
                // cout << "taking value " << val << endl;
                for (int pat=0 ; pat < 4 ; pat++)
                {
                    int prev_dp = dp[idx][len][stk][pat];
                    dp[idx + 1][len][stk][pat] += prev_dp;
                    dp[idx + 1][len][stk][pat] %= mod;

                    if (stk + val < 0) continue;
                    //cout << "no cont" << endl;
                    int nxt_p = pat;
                    if (pat == 0 and val==-1) nxt_p++;
                    else if (pat > 0 and pat < 3) nxt_p += (max(val , zero));

                    // cout << "prev pattern is " << pat << endl;
                    // cout << "current pattern of importance " << nxt_p << endl;
                    int& temp = dp[idx+1][len+1][stk+val][nxt_p];
                    temp += prev_dp;
                    temp %= mod;

                }
            }
        }
    }
    
    int ans = 0;
    for (int len=0 ; len <=n ; len ++)
    {
        // cout << dp[n][len][0][0] << endl;
        // cout << dp[n][len][0][1] << endl;
        // cout << dp[n][len][0][2] << endl;
        // cout << dp[n][len][0][3] << endl;
        ///if (dp[n][len][0][3] < 0) cout << "fuck debug ERRRRIRIRIR" << endl;
        ans += dp[n][len][0][3] * (len - 2);
        ans %= mod;
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///freopen("test_input.txt" , "r" , stdin);
    ///freopen("test_output.txt" , "w" , stdout);
    auto time_start = clock();
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        cin >> s;
        for (int i=0 ; i<=n+1 ; i++)
        {
            for (int j=0 ; j<=n+1 ; j++)
            {
                for (int k=0 ; k<=n+1 ; k++)
                {
                    for (int q=0 ; q<4 ; q++) dp[i][j][k][q] = 0;
                }
            }
        }
        solve();
    }
    
    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
