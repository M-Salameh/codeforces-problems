#include <bits/stdc++.h>
#define int long long
#define double long double
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mid (l+r)/2
#define lc 2*node
#define rc 2*node+1
#define endl '\n'
#define MOD 1000000007
///#define long __int128

using namespace std;

int tc = 1;

int n , k;
int c;

void solve()
{
    cin >> n ;
    vector<int> arr(n+1,0);
    vector<int> visited(n+5,0);
    for (int i=1 ; i <= n ; i++)
    {
        cin >> arr[i] ;
        if (arr[i]<=n) visited[arr[i]] ++ ;
    }
    int ans = 0 ;
    for (int i=1 ; i <= n ; i++)
    {
        int cur = 0 ;
        for (int j=1 ; j*j<=i ; j++)
        {
            if (i%j) continue;
            cur += visited[j] ;
            if (i/j != j)
            {
                cur += visited[i/j];
            }
        }
        ans = max ( ans , cur ) ;
    }
    cout << ans << endl ;
    return;
}


signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
