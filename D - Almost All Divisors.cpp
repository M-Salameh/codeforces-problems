#include <bits/stdc++.h>
#include <math.h>
#define int long long
#define endl '\n'
#include <string>
using namespace std;

int tc=1;

int n;

vector<int> d;

void solve()
{
    d.clear();
    for (int i=1 ; i<=n ; i++)
    {
        int x;
        cin >> x;
        d.push_back(x);
    }
    sort(d.begin() , d.end());
    int ans = d[0] * (d.back());

    vector<int> divs;
    for (int i=2 ; i*i <= ans ; i++)
    {
        if (ans % i) continue;
        divs.push_back(i);
        if (ans/i != i) divs.push_back(ans/i);
    }
    sort(divs.begin() , divs.end());

    if (divs == d) cout << ans << endl;
    else cout << -1 << endl;

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
