#include <bits/stdc++.h>
//#define int long long
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
    int pos=0 , neg = 0;
    for (int i=1 ; i<=n ; i++)
    {
        int x;
        cin >> x;
        if (x<0) neg++;
        else pos++;
    }
    int ans = 0;
    if (pos < neg)
    {
        ans += (neg - pos + 1)/2;
        neg -= ans;
        pos += ans;
    }
    if (neg&1)
    {
        ans++;
    }
    cout << ans << endl;


}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> tc;
    while(tc--)
    {
        solve();
    }

    return 0;
}
