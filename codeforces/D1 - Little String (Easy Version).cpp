#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast64_t
#define pii pair<int,int>

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 2e18+1;
const int NN = 2e5+3;
const int mod = 1e9+7;
int tc=1;
int n, c;
string w;


void solve()
{
    if (w[1] == '0' || w[n] == '0')
    {
        cout << -1 << endl;
        return ;
    }
    int ans = 1;
    int cond = 1;
    for (int i=1 , temp; i<n ; i++)
    {
        temp = ( (w[i]-'0') * 2 + (1 - (w[i] - '0') ) * (i-1) );
        ans *= temp;
        ans %= mod;
        if (ans < 0) ans += mod;
        cond *= temp;
        cond %= c;
        if (cond < 0) cond += c;
    }   
    ans = cond == 0 ? -1 : ans;
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
        cin >> n >> c;
        cin >> w;
        w = "#" + w + "#";
        solve();
    }
    
    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}