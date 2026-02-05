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
//#define ll long long
//#define double long double

using namespace std;

int tc=1;

int n ;

vector<int> arr;

void solve()
{
    int even = 0;
    int odd = 0;
    for (int i=1 ;i<=n ; i++)
    {
        if (arr[i] <= 0) continue;
        if (i&1) odd += arr[i];
        else  even+= arr[i];
    }
    int ans = max (even , odd);
    cout << ans << endl;
    return;
}

signed main()
{
    fast;
    cin >> tc;
    while (tc--)
    {
        cin >> n ;
        arr.clear();
        arr = vector<int> (n+1,0);
        int best = -1e12;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
            best = max (arr[i] , best);
        }
        if (best <= 0) cout << best << endl;
        else solve();
    }
    return 0;
}
