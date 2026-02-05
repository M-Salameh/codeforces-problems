#include <bits/stdc++.h>
#define int unsigned long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int dp[5000005];
int tc;
int n;

void solve()
{
    dp[1]=1;
    for (int i=2 ; i <= 2023 ; i++)
    {
        int st,en;
        st = (((i-1)*i)/2) +1;
        en = st + i - 1;
        for (int j=st ; j<=en ; j++)
        {
            if (j==st)
            {
                dp[j] = dp[j-i+1] + j*j;
            }
            else if (j==en)
            {
                dp[j] = dp[j-i] + j*j;
            }
            else
            {
                dp[j]= dp[j-i] + dp[j-i+1] + j*j - dp[(j-2*i+2)];
            }
        }
    }
}
signed main()
{
    fast;
    solve();
    tc=1;
    cin >> tc;
    while(tc--)
    {
        cin >> n ;
        cout << dp[n]<<endl;
    }

    return 0;
}
