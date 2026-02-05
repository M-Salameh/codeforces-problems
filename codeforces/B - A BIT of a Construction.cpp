#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
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
int n,k;

int before_last_bit(int& z)
{
    return __lg(z);
}
int last_bit(int& z)
{
    return 1 + before_last_bit(z);
}


void solve()
{
    if (n==1)
    {
        cout << k << endl;
        return;
    }
    int x = before_last_bit(k);

    vector<int> ans (n,0);
    x = (1LL << x)  - 1;
    int y = k-x;
    ans[n-2] = y;
    ans[n-1] = x;

    for (auto& i : ans)cout << i << ' ';
    cout << endl;

}

signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> k;
        solve();
    }

    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
