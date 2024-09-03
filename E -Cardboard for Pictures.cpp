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
    cin >> n >> c;
    int b=0;
    int y=0;
    for(int i=1 ; i<=n ; i++)
    {
        int x;
        cin >> x;
        b += x;
        y += x*x;
    }
    b = 2*b/n;
    int u = y/n - c/n;
    int delta = b*b - 4*u;
    delta = sqrt(delta);
    delta -= b;
    delta /= 4;
    cout << delta <<endl;
    return;
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
