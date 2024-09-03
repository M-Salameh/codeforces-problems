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
    vector<int> a (n+1,0);
    vector<int> b (n+1,0);
    vector<int> c;
    for (int i=1 ;i<=n ; i++) cin >> a[i];
    for (int i=1 ;i<=n ; i++) cin >> b[i];
    for (int i=1 ;i<=n ; i++) c.push_back(a[i]-b[i]);
    sort(c.begin() , c.end());

    int ans = 0;
    for (int i=0 ; i<n ; i++)
    {
        if (c[i] < 1) continue;
        int pos = upper_bound(c.begin() , c.end() , -c[i]) - c.begin();
        ans += (i-pos);
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    //cin >> tc;
    while(tc--)
    {
        solve();
    }

    return 0;
}
