#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#include <math.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define pi pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin()+1,x.end()
#define all0(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define ll unsigned long long
#define int long long
#define double long double
#define endl '\n'
#pragma once
using namespace std;
using namespace __gnu_pbds;

int tc = 1;
int n , m , _k ,dist;
const int inf = 1e18+6;
vector<int> pref;
multiset<int> ms;

void solve(int idx)
{
    vector<int> arr(m+1,0);
    for(int i=1 ; i<=m ; i++)
    {
        cin >> arr[i];
        arr[i]++;
    }
    vector<int> dp(m+1 , 0);

    dp[1]=1;
    ms = {dp[1]};

    for (int i = 2 ; i<=m ; i++)
    {
        dp[i] = arr[i] + *ms.begin();
        ///cout << "dp[" <<i <<" = " << dp[i] << endl;
        if (i > dist)
        {
            ms.erase(ms.find(dp[i-dist]));
        }
        ms.insert(dp[i]);
    }

    pref[idx] = pref[idx-1]+dp[m];
}

signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m >> _k >> dist;
        dist++;
        _k--;
        pref = vector<int> (n+1 , 0);
        ms.clear();

        for(int i=1 ; i<=n ; i++) solve(i);

        int ans = inf;
        for (int i=1 ; i+_k<=n ; i++)
        {
            ans = min(ans , pref[i+_k]-pref[i-1]);
        }
        cout << ans << endl;
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
