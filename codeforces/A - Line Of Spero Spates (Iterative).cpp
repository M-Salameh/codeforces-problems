#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
int n;
const int NN = 5050;
int arr[NN];
int dp[NN][NN];


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i=1;i<=n ; i++)
    {
        cin >> arr[i];
        dp[i][i] = arr[i]*n;
    }

    for (int r=1 ; r<=n ; r++)
    {
        for (int l=r ; l>=1; l--)
        {
            int temp = n - (r-l);
            dp[l][r] = max (temp*arr[l]+dp[l+1][r], dp[l][r-1]+temp*arr[r]);
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}
