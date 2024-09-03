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
#pragma once
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 1e18+6;
int n,k ;
vector<int> clique;

void solve()
{
    int offset = 0;
    while (true)
    {
        int st = (offset++)*k+1;
        int en = min(offset*k , n);

        int temp = (st+en)/2;

        for (int i=temp+1 ; i<=en ; i++) cout << i << ' ';
        for (int i=st ; i<=temp ; i++) cout << i << ' ';

        /**cout << "st = " << st << endl << "en = " << en << endl;
        cout << "med = " << med<<endl;*/


        for (int i = st ; i <= en ; i++) clique[i] = offset;
        if (en == n) break;
    }

    cout << endl << offset << endl;

    for (int i=1 ; i<=n ; i++)
    {
        cout << clique[i] << ' ';
    }
    cout << endl;
    return;

}

signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> k;
        ///arr = vector<int>(n+1 , 0);
        clique = vector<int>(n+1 , 0);
        solve();

    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
