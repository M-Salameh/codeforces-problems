#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int n;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n ;
    if (n<=2)
    {
        cout << n << endl;
        return 0;
    }
    if (n==3)
    {
        cout << 6 << endl;
        return 0;
    }
    if(n&1)
    {
        int ans = n*(n-1)*(n-2);
        cout << ans << endl;
        return 0;
    }
    if (! (n%6))
    {
        int x = (n-1)*(n-2)*(n-3);
        cout << x << endl;
        return 0;
    }
    else
    {
        int x = (n)*(n-1)*(n-3);
        cout << x << endl;
        return 0;
    }

    return 0;
}
