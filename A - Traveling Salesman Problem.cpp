#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
using namespace std;

int tc=1;
int n;

void solve()
{
    cin >> n;
    int max_x = -1e15;
    int min_x = 1e15;
    int max_y = -1e15;
    int min_y = 1e15;
    for (int i=0; i<n; i++)
    {
        int x , y;
        cin >> x >> y;
        max_x = max (max_x , x);
        max_y = max (max_y , y);
        min_x = min (min_x , x);
        min_y = min (min_y , y);
    }
    int ans = 0;
    if (max_x > 0) ans += 2*max_x;
    if (max_y > 0) ans += 2*max_y;
    if (min_x < 0) ans -= 2*min_x;
    if (min_y < 0) ans -= 2*min_y;

    cout << ans << endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
