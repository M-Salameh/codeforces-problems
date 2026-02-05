#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#include <math.h>
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
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'


using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 5e15+6;
int n,k;
vector<int> arr;

void solve()
{
    int ans = 0;
    sort(all(arr));
	for(int i=1 ; i <= n/2 ; i++)
	{
		int j = n-i+1;
		int x = arr[i+1]-arr[i]+arr[j]-arr[j-1];
        x *= i;
		if (k >= x) k -= x;
		else
		{
			ans = arr[j]-arr[i]-k/i;
			break;
		}
	}
    cout << ans << endl;
    return;
}




signed main()
{
    fast;
    ///cin >> tc;
    while(tc--)
    {
        cin >> n >> k;
        arr = vector<int>(n+1,0);
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
        }
        solve();
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
