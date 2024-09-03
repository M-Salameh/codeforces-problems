#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int inf = 1e18+2;
int tc = 1;
const int NN = 2e5+6;
int n;

multiset<int> arr;

void solve()
{
    int lcm = 1;
    int ans = 0;
    for (auto x : arr)
    {
        lcm = lcm*(x/(__gcd(x,lcm)));
        if (lcm > *--arr.end())
        {
            cout << n << endl;
            return;
        }
    }
    if (lcm > *--arr.end())
    {
        cout << n << endl;
        return;
    }
    if (*--arr.end() == *arr.begin())
    {
        cout << 0 << endl;
        return;
    }
    set<int> divs;
    for (int i=2 ; i*i <= lcm ; i++)
    {
        if (lcm % i) continue;
        divs.insert(i);
        divs.insert(lcm/i);
    }

    for (auto div : divs)
    {
        if (arr.find(div) != arr.end()) continue;
        int temp = 0;
        int lc = 1;
        int mx=0;
        for (auto x : arr)
        {
            if (div % x) continue;
            lc = (lc*x)/(__gcd(x,lc));
            temp++;
            mx = x;
        }
        ans = max (ans , temp*(mx != lc));
    }
    cout << ans << endl;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n ;
        arr.clear();
        for (int i=1 ; i<=n ; i++)
        {
            int x;
            cin >> x;
            arr.insert(x);
        }
        solve();
    }
    return 0;
}
