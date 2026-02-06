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
vector<int> ans;

void solve()
{
    ans = vector<int> (n , 0);
    if (n&1)
    {
        ans[0] = n-1;
        for (int i = 2 ; i < n-2 ; i += 2)
        {
            ans[i-1]=i+1;
            ans[i] = i;
        }
        ans[n-2] = n;
        ans[n-1] = 1;
    }
    else 
    {
        ans[0] = n;
        int fix = n - (1<< __lg(n));
        for (int i=2 ; i<=n-2 ; i += 2)
        {
            ans[i-1] = i+1;
            ans[i] = i;
        }
        ans[n-1] = 1;
        swap(ans[fix] , ans[0]);
    }

    for (int& i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

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
        if (1 << __lg(n) == n)
        {
            cout << -1 << endl;    
        }
        else 
        {
            solve();
        }
    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
