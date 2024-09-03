#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int tc;
int n,k;
int tgt;
int arr[404040];

void solve()
{
    arr[0] = LONG_MAX ;
    int cnt=0;
    int ans=0;
    int x;
    for (int i = 1 ; i<=n ; i++)
    {
        cin >> arr[i];
        if (2*arr[i] > arr[i-1])
        {
            cnt++;
        }
        else
        {
            if (cnt>=k)
            {
                ans = ans + (cnt - k +1);
            }
            cnt = 0;

        }
    }
    ans+= max(0ll,cnt-k+1);
    cout << ans <<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc ;
    tgt = tc;
    while (tc--)
    {
        cin >> n >> k ;
        solve();
    }
    return 0;
}
