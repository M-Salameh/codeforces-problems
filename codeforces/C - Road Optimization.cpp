#include <bits/stdc++.h>
#define endl  '\n'
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,l,k;

    cin >> n >> l  >> k;
    vector<int> pos(n+5,0);
    vector<int> speed (n+5,0);
    for (int i=1 ; i<=n ; i++) cin >> pos[i];
    for (int i=1 ; i<=n ; i++) cin >> speed[i];

    n++;
    pos[n] = l;

    vector<vector<int>> dp (n+5 , vector<int>(n+5 , 1e10+8));

    int ans=3e10+7;

    dp[1][1]=0;


    for (int i=2 ; i<=n ; i++)
    {
        for (int j=2 ; j<=i ; j++)
        {
            for (int itr = j-1 ; itr<i ; itr++)
            {
                int t = (pos[i]-pos[itr])*speed[itr];
                dp[i][j] = min (dp[i][j] , dp[itr][j-1] + t);
            }
        }
    }


    for (int i=0 ; i<=k ; i++)ans = min (ans , dp[n][n-i]);
    cout << ans << endl;
    return 0;
}
