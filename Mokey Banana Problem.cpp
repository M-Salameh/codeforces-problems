#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);using namespace std;
#define int long long
#define endl '\n'
using namespace std;

const int NN = 105;

int arr[2 * NN][NN];
int dp[2 * NN][NN];
int tc, n;
int shift;
void Read()
{
    shift = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = n; i < (n * 2) - 1; i++)
    {
        for (int j = shift; j < n; j++)
        {
            cin >> arr[i][j];
        }
        shift++;
    }
}

void solve()
{
    dp[0][0] = arr[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + arr[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
            }
        }
    }
    shift = 1;
    for (int i = n; i < (n * 2) - 1; i++)
    {
        for (int j = shift; j < n; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
        }
        shift++;
    }
}

signed main()
{
    fast;
    cin >> tc;
    int kkk= 1;
    while(tc--)
    {
        cin >> n;
        memset(dp, 0, sizeof(dp));
        memset(arr, 0, sizeof(arr));
        Read();
        solve();
        cout << "Case " << kkk << ": " << dp[2*(n-1)][n-1]<<endl;
        kkk++;
    }

    return 0;
}
