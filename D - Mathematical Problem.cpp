
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
int n;

void solve()
{
    if(n == 1)
    {
      cout << 1 << endl;
      return;
    }
    int cnt = n-1;

    cout << "196" + string(n - 3, '0') << endl;

    for(int dist = 0; dist * 2 + 3 <= n; dist++)
    {
        if(cnt)
        {
            cnt--;
            cout << "1" << string(dist, '0') + "6" << string(dist, '0') << "9" << string(n - dist * 2 - 3, '0') << endl;
        }
        if(cnt)
        {
            cnt--;
            cout << "9" << string(dist, '0') + "6" << string(dist, '0') << "1" << string(n - dist * 2 - 3, '0') << endl;
        }
    }

    return;
}

signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        solve();
    }
    return 0;
}

///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
