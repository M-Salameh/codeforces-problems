#include <bits/stdc++.h>
#define int long long
#define mid (l+r)/2
#define endl '\n'
using namespace std;

const int inf = 2e18+5;
const int NN = 1e6+2;
int tc=1;
int n,m;
pair<int,int> arr[NN];
pair<int,int> brr[NN];
int c[NN];
int dp[NN];

int get_index(int val)
{
    int l = 1 ; 
    int r = n;
    int idx = 0;
    while (l <= r)
    {
        if (arr[mid].first > val)
        {
            r = mid-1;
        }
        else 
        {
            idx = mid;
            l = mid+1;
        }
    }

    return idx;
}

void solve()
{
    sort(brr+1 , brr + n + 1);
    arr[1] = brr[1];
    int _j = 1;
    for (int i=1 ; i<=n ; i++)
    {
        if (brr[i].second < arr[_j].second)
        {
            arr[++_j] = brr[i];
        }
    }
    n = _j;

    for (int i=1 ; i <= NN ; i++)
    {
        int idx = get_index(i);
        if (idx == 0) continue;
        dp[i] = dp[i-arr[idx].second];
        dp[i] += 2;

    }
    int ans = 0;
    int dif = arr[n].first - arr[n].second;
    for (int i=1 ; i <= m ; i++)
    {
        if (c[i] <= arr[n].first) ans += dp[c[i]];
        else
        {
            int temp = (c[i] - dif)/arr[n].second;
            temp *= 2;
            c[i] -= dif; c[i] %= arr[n].second;
            c[i] += dif;
            ans += temp + dp[c[i]];
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ///cin >> tc ;
    while (tc--)
    {
        cin >> n >> m;
        for (int i=1 ; i<=n ; i++) cin >> brr[i].first ; 
        
        for (int i=1 ; i<=n ; i++)
        {
            cin >> brr[i].second;
            brr[i].second = brr[i].first - brr[i].second;
        }

        for (int i=1 ; i<=m  ; i++) cin >> c[i];
        solve();
    }
    return 0;
}
