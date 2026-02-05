#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int tc;

int n,m;

void solve()
{
    if (n==2)
    {
        cout << 7 << endl;
        return;
    }
    cout << 3 << endl;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> tc ;
    while(tc--)
    {
        cin >> n ;
        solve();
    }


    return 0;
}
