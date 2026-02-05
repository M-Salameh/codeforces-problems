#include <bits/stdc++.h>
#include <string>
#define endl '\n'
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
//#define double long double

using namespace std;
int tc=1;


__int128 power3(__int128 a , __int128 b)
{
    if (b==0) return 1;
    if (b==1) return a;
    __int128 res = power3(a,b/2);
    res = (res*res);
    if (b&1) res = (a*res);
    return res;
}




void solve_E2()
{
    int n; cin >> n;
    for (__int128 j = 2; j <= 60; j++)
    {
        __int128 l = 2;
        __int128 r = ceil(pow(n, 1.0/j));
        __int128 ans = 0;
        while (l <= r)
        {
            __int128 x = (power3(mid, j + 1) - 1);
            x /= (mid - 1);

            if (x >= n)
            {
                ans = x;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (ans == n)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}

signed main()
{
    fast;
    cin >> tc;
    while (tc--)
    {
        solve_E2();
    }
    return 0;
}
