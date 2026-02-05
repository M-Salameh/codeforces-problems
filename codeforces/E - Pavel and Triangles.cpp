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
int n;
vector<int> arr;

signed main()
{
    fast;
    ///cin >> tc;
    while(tc--)
    {
        cin >> n;
        int ans = 0;
        arr = vector<int> (n+1 , 0);
        for(int i=1 ; i<=n ; i++)
        {
           cin >> arr[i];
        }
        int s = 0;
        for(int i=1 ; i<=n ; i++)
        {
           int x = 2*s;
           if(arr[i] >= x)
           {
               ans += s;
               arr[i] -= x;
               s = 0;
           }
           else
           {
               ans += arr[i]/2;
               s -= arr[i]/2;
               arr[i] -= 2*(arr[i]/2);
           }
           ans += arr[i]/3;
           s += arr[i]%3;
        }
       cout << ans << endl;
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
