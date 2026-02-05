#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define mid (l+r)/2
using namespace std;

int tc;
int n,q;
int hs,wsw,hb,wb;
void solve()
{
    vector<vector<int>> area (2010 , vector<int>(2010 , 0));
    vector<vector<int>> dp (2010 , vector<int>(2010 , 0));
    int a,b;
    for (int i=1 ;i<=n ; i++)
    {
        cin >> a >> b ;
        area[a][b] += (a*b);
    }
    for (int i=1 ;i<=1010 ; i++)
    {
        for (int j=1 ; j<=1010; j++)
        {
            dp[i][j] = area[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    int ans;
    while(q--)
    {
        cin >> hs >> wsw >> hb >> wb;
        ans = dp[hb-1][wb-1] - dp[hb-1][wsw] - dp[hs][wb-1] + dp[hs][wsw];
        cout << ans << endl;
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc ;
    while (tc--)
    {
        cin >> n >> q;
        solve();
    }
    return 0;
}
