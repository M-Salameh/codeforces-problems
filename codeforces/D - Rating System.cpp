#include <bits/stdc++.h>
#define int long long
#define double long double
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mid (l+r)/2
#define lc 2*node
#define rc 2*node+1
#define endl '\n'
#define inf LONG_LONG_MAX
using namespace std;

int tc = 1;
int n;

void solve()
{
    vector<int> arr(n+1,0);
    int mx = -inf;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
        mx = max (mx , arr[i]);
    }
    if (mx < 0)
    {
        cout << 0 << endl;
        return;
    }

    int gap = 0;
    int sum = 0;
    int max_sum = 0;
    int k = 0;
    for (int i=1 ; i<=n ; i++)
    {
        sum += arr[i];
        max_sum = max(max_sum , sum);
        if (max_sum - sum > gap)
        {
            gap = max_sum - sum;
            k = max_sum;
        }
    }
    cout << k << endl;
}

signed main()
{
    fast;
    cin >> tc;
    while (tc--)
    {
        cin >> n ;
        solve();
    }
    return 0;
}
