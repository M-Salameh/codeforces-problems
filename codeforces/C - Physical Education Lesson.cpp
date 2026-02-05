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

set<int>st;

int n,x;

void help(int y)
{
    for(int i=1 ; i*i <= y ; i++)
    {
        if (y%i) continue;

        if(i/2+1>=x and i%2==0) st.insert(i);

        int j = y/i;

        if(j/2+1>=x and j%2==0) st.insert(j);
    }
}

void solve()
{
    st.clear();

    help(n-x);

    help(n+x-2);

    cout << st.size() << endl;
}


signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> x;
        solve();
    }
    return 0;
}

///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
