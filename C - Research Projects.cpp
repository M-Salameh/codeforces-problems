#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int tc=1;
int n,k;

void solve()
{
    int a = n-k;
    int ans=0;
    int b = a/6;
    int c=a - b*6;
    cout << b+(c>0) << endl;
}

signed main()
{

    fast;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> k;
        solve();
    }
    return 0;
}
