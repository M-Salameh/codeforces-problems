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
#define endl '\n'
#define ll unsigned long long
#define int unsigned long long
#define double long double
#pragma once

using namespace std;
using namespace __gnu_pbds;


int tc=1;
const int inf = 1e18;
int n;
int q;

vector<__int128> sizes;
map<__int128,int> mp;

__int128 sz;

int bs(__int128 k)
{
    while(true)
    {
        if (mp[k]) return mp[k];
        int temp = distance((sizes).begin(), upper_bound(all0(sizes), (k))) -1;
        k %= sizes[temp];
    }
}


void solve()
{
    while (n--)
    {
        int b, x;
        cin >> b >> x;
        if (sz > inf) continue;
        if (b == 1)
        {
            mp[sz++] = x;
        }
        else
        {
            sizes.push_back(sz);

            __int128 newsz = (__int128)sz + sz*x;

            sz = (newsz > inf) ? inf+1 : (int) newsz;
        }
    }

    queue<int> ans;
    while(q--)
    {
        int k;
        cin >> k;
        ans.push(bs(k-1));
    }
    while(ans.size())
    {
        cout << ans.front() << ' ';
        ans.pop();
    }
    cout << endl;
}

signed main()
{
    fast;

    cin >> tc;

    while(tc--)
    {
        cin >> n >> q;
        mp.clear();
        sizes.clear();
        sizes = {0};
        sz = 0;
        solve();
    }
    return 0;
}

