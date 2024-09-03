#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#include <string>
using namespace std;


vector <vector <ll>> dp (5050 , vector<ll>(5050,0));

ll n , m;
string A,B;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m ;
    cin >> A ;
    cin >> B;
    A="?"+A;
    B="1"+B;
    ll ans = -1;
    ll temp; ll zero=0;
    for (ll i=1 ; i<=n; i++)
    {
        for (ll j=1 ; j<=m ; j++)
        {
            temp = max(dp[i][j-1], dp[i-1][j]) - 1 ;
            if (A[i]==B[j])
            {
                dp[i][j] = dp[i-1][j-1] + 2;

            }
            else
            {
                dp[i][j] = temp ;
            }
            dp[i][j] = max (zero , dp[i][j]);
            ans = max(ans , dp[i][j]);
        }
    }

    ans = max (ans , zero);
    cout << ans << endl;

    return 0;
}

