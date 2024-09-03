#include <bits/stdc++.h>
#include <math.h>
#define int long long
#define endl '\n'
#include <string>
using namespace std;

int tc;
int n;
void solve()
{
    int x;
    vector<int> idx(1001,-1);
    for (int i=1 ; i<=n ; i++)
    {
        cin >> x;
        idx[x] = max(i,idx[x]);
    }
    vector<vector<int>> gcd (1001 , vector<int>(1001,-1));
    for (int i=1 ;i<=1000;i++)
    {
        for (int j = 1 ; j<=1000 ; j++)
        {
            if (gcd[i][j] == -1)
            {
                x = __gcd(i,j);
                gcd[i][j] = gcd[j][i] = x;
            }
        }
    }
    int ans = -1;
    for (int i=1 ; i<=1000 ; i++)
    {
        for (int j=1 ;j<=1000 ; j++)
        {
            if (idx[j]>0 && idx[i]>0)
            {
                if (gcd[i][j]==1)
                {
                    ans = max (ans , idx[i]+idx[j]);
                }
            }
        }
    }
    cout << ans << endl;

    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> tc ;
    while(tc--)
    {
        cin >> n;
        solve();
    }


    return 0;
}
