#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define mid (l+r)/2
using namespace std;

int arr[606060];
int sum[606060];
int support[606060];
int tc;
int n,m;

void solve()
{
    for (int i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i-1]+arr[i];
    }
    if (sum[n] % 3)
    {
        cout << 0 << endl;
        return;
    }
    m = sum[n]/3;
    int cnt = 0;
    /**
    int ans = 0;
    for (int i=1 ;i<n ; i++)
    {
        if (sum[i] == 2*m) ans+=cnt;
        if (sum[i] == m) cnt++;
    }*/
   int ans=0;
    if (m==0)
    {
        for (int i=1 ;i<n ; i++)
        {
            if (sum[i] == 0)
            {
                ans++;
            }
        }
        cout << ans*(ans-1)/2 <<endl;
        return;
    }
    for (int i=n ;i>=1 ; i--)
    {
        support[i] = support[i+1];
        if (sum[i] == 2*m)
        {
            support[i]++;
        }
    }
    for (int i=1 ;i<=n ; i++)
    {
        if (sum[i]==m)
        {
            ans += support[i];
        }
    }
    cout << ans << endl;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //cin >> tc ;
    tc=1;
    while (tc--)
    {
        cin >> n ;
        solve();

    }


    return 0;
}
