#include <bits/stdc++.h>
#include <math.h>
///#define int long long
#define endl '\n'
#include <string>
using namespace std;

int tc=1;

int n;


void solve()
{
    int x = 0;
    set<int> s;
    s.insert(0);
    for (int i=1 ; i<=n ; i++)
    {
        int a;
        cin >> a;
        x ^= a;
        s.insert(x);
    }

    int ans = *--s.end();

    for (auto i : s)
    {
        for (auto j : s)
        {
            ans = max (ans , i^j);
        }
    }
    cout << ans << endl;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> tc;

    while(tc--)
    {
        cin >> n;
        solve();
    }

    return 0;
}
