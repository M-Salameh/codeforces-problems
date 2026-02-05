#include <bits/stdc++.h>
///#define int long long
#define double long double
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mid (l+r)/2
#define lc 2*node
#define rc 2*node+1
#define endl '\n'
#define MOD 1000000007
#define long __int128

using namespace std;

int tc = 1;

int n;

signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        int arr[3];
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr , arr+3);
        if (arr[2] + arr[1] >= 10) cout <<"YES" <<endl;
        else cout << "NO" <<endl;
    }
    return 0;
}