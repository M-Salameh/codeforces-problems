/// https://codeforces.com/gym/105493/problem/D
#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
///#define int int_fast64_t
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 1e15+1;
const int NN = 2e6+3;
const int mod = 1e9+7;
int tc=1;
int n , m;
vector<int> divs[NN];
pair<int,int> arr[NN];
bool taken[NN];
bool prime[NN];

void sieve()
{
    for (int i=2; i<NN ; i++) prime[i] = true;

    for (int i=2 ; i<NN ; i++)
    {
        if (not prime[i]) continue;
        divs[i].push_back(i);
        for (int j=i+i ; j<NN ; j+=i)
        {
            prime[j] = false;
            divs[j].push_back(i);
        }

    }
}

int last[NN];
int parent[NN];

void solve()
{
    for (int div : divs[arr[1].first])
    {
        last[div] = 1;
    }
    vector<int> dp(n+1 , 1);

    taken[arr[1].first] = true;

    for (int i=2 ; i<=n ; i++)
    {
        int x = arr[i].first;

        if (taken[x]) continue;

        taken[x] = true;
        for (int& px : divs[x])
        {
            if (last[px] != 0 and x > arr[last[px]].first)
            {
                int cur = max (dp[i] , 1 + dp[last[px]]);
                if (cur > dp[i])
                {
                    parent[i] = last[px];
                }
                dp[i] = cur;
            }
            last[px] = i;
        }
    }
    int ans = 0  , idx = -1;
    for (int i=1 ; i<=n ; i++)
    {
        if (dp[i] > ans)
        {
            ans = dp[i];
            idx = i;
        }
    }
    vector<int> path;

    while(idx != 0)
    {
        path.push_back(idx);
        idx = parent[idx];
    }
    reverse(all(path));

    cout << ans << endl;

    for (int i : path ) cout << arr[i].second << " ";

}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    auto time_start = clock();
    ///cin >> tc;
    sieve();
    while (tc--)
    {
        ///freopen("test_input_tle.txt" , "r" , stdin);
        cin >> n;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i].first;
            arr[i].second = i;
        }
        sort(arr+1 , arr+n+1);

        solve();
    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
