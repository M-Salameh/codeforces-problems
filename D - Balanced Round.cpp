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
    cin >> n >> k;
    vector<int> arr (n+1 , 0);
    for (int i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin()+1 , arr.end());
    int pos = 1;
    int ans = 1;
    int r = 2;
    int cur = 0;
    while (r <= n)
    {
        if (arr[r]-arr[r-1] > k)
        {
            ans = max (ans , cur);
            pos = r;
            r++;
            cur = 0;
        }
        else
        {
            cur = r-pos+1;
            r++;
        }
    }
    ans = max (ans , cur);
    ans = n-ans;
    cout << ans << endl;  
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
