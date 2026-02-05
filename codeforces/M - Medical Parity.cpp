#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
//#define int int_fast64_t

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 2e18+1;
const int NN = 1e6+3;
const int mod = 1e9+7;
int tc=1;
int n;


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///freopen("test_input.txt" , "r" , stdin);
    ///freopen("test_output.txt" , "w" , stdout);
    auto time_start = clock();
    cin >> tc;
    while (tc--)
    {
        string x , y;
        cin >> x >> y ;
        n = x.size();
        x = "0" + x;
        y = "0" + y;
        vector<int> dp[2];
        dp[0] = vector<int>(n+1,NN);
        dp[1] = vector<int>(n+1,NN);
        dp[0][0] = 0;
        for (int i=1 ; i<=n ; i++)
        {
            int xi = x[i]-'0';
            int yi = y[i]-'0';
            dp[0][i] = min (xi + dp[0][i-1] , dp[1][i-1] + (1-xi)) + yi;
            dp[1][i] = min (1-xi + dp[0][i-1] , dp[1][i-1] + xi) + (1-yi);
        }
        int ans = min (dp[0][n] , dp[1][n]);
        cout << ans << endl;   

    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
