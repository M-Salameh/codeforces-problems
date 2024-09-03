#include <bits/stdc++.h>
#define int long long
//#define double long double
#define endl '\n'

using namespace std;

const int inf = 1e17+8;
const int NN = 5e5+5;
int n , tc=1;

int arr[NN];

void solve()
{
    int ans = 0;
    int tot = 0;

    for (int i=2 ; i<=n ; i++)
    {
        if (arr[i]==1 and arr[i-1]>1)
        {
            cout << -1 << endl;
            return;
        }
        tot = max (0LL , (int)ceil(tot-log2(log(arr[i])/log(arr[i-1]))));
        ans += tot;
    }
    cout << ans << endl;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        for (int i=1 ; i <= n; i++)
        {
            cin >> arr[i];
        }
        solve();
    }

    return 0;
}
