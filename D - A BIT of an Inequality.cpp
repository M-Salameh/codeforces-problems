#include <bits/stdc++.h>
///#define int long long
#define endl '\n'

using namespace std;

const int inf = 1e14+8;
const int NN = 2e5+5;
int n , tc=1;
int k;
int arr[NN];
int pref[32][NN] , even[32][NN] , odd[32][NN];

void solve()
{
    long long ans = 0;
    for (int i=1 ; i<=n ; i++)
    {
        int msb = __lg(arr[i]);
        long long ev = 1LL * even[msb][i-1] * (even[msb][n] - even[msb][i-1]);
        long long od = 1LL * odd[msb][i-1] * (odd[msb][n] - odd[msb][i-1]);
        ans += (ev + od);
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> tc;

    for (int bit = 0 ; bit<=31 ; bit++)
    {
        even[bit][0] = 1;
    }

    while(tc--)
    {
        cin >> n;
        for (int i=1 ; i <= n; i++)
        {
            cin >> arr[i];
            for (int bit = 0  ; bit<=31 ; bit++)
            {
                pref[bit][i] = pref[bit][i-1];
                pref[bit][i] += ((arr[i] & (1<<bit)) > 0);
                even[bit][i] = even[bit][i-1] + (!(pref[bit][i] & 1));
                odd[bit][i] = odd[bit][i-1] + (pref[bit][i] & 1);
            }
        }

        solve();
    }

    return 0;
}
