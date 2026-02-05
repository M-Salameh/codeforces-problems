#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n,m;
string s;
int dp[101010];
int l ,r;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s;
    for (int i=1 ; i< s.size();i++)
    {
        dp[i]=dp[i-1];
        if (s[i]==s[i-1])
        {
            dp[i] = dp[i-1]+1;
        }

    }
    cin >> m ;
    while (m--)
    {
        cin >> l >> r ;
        cout << dp[r-1] - dp[l-1] << endl;

    }
    return 0;
}
