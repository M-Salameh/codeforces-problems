#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define M 1000000007
///#define int long long /**bad for Time!*/
using namespace std;
int sum;
int r,g;
int h=1;
int k=1;

void solve_no_Optimization()
{
    int dp_no_opt[h+1][r+1];
    memset(dp_no_opt , 0 , sizeof(dp_no_opt));
    int gi;
    int u;
    int f;
    dp_no_opt[0][0] = 1;
    for (int hi=1 ; hi <= h ; hi++)
    {
        u = (hi*(hi-1))/2;
        for (int ri = 0 ; ri <= r  ; ri++)
        {
            gi = u - ri;
            f=0;
            if (gi>g or g<0) continue;
            if (g-gi >= hi)
            {
                dp_no_opt[hi][ri] += dp_no_opt[hi-1][ri];
                dp_no_opt[hi][ri] %= M;
            }
            if (ri>=hi)
            {
               dp_no_opt[hi][ri] += dp_no_opt[hi-1][ri-hi];
               dp_no_opt[hi][ri] %= M;
            }
        }
    }
    f=0;
    for (int j=0 ; j<= r ; j++)
    {
        f += dp_no_opt[h][j];
        f %=M;
    }
    cout << f << endl;
    return;
}

void solve_Optimized()
{
    int dp[2][r+1];
    memset(dp , 0 , sizeof(dp));
    dp[0][0] = 1;
    int gi;
    int u;
    int f=0;
    int cur = 1;
    int old = 0;
    for (int hi=1 ; hi <= h ; hi++)
    {
        u = (hi*(hi-1))/2;
        for (int j=0 ; j<=r ; j++) dp[cur][j] = 0;
        for (int ri = 0 ; ri <= r  ; ri++)
        {
            gi = u - ri;
            if (gi>g or g<0) continue;
            if (g-gi >= hi)
            {
                dp[cur][ri] += dp[old][ri];
                dp[cur][ri] %= M;
            }
            if (ri>=hi)
            {
               dp[cur][ri] += dp[old][ri-hi];
               dp[cur][ri] %= M;

            }
        }
        cur = 1 - cur;
        old = 1 - old;
    }
    f=0;
    for (int j=0 ; j <= r ; j++)
    {
        f += dp[old][j];
        f %=M;
    }
    cout << f << endl;

}

signed main()
{
    fast;
    cin >> r >> g;
    sum = r+g;
    for (int i=0;i<900;i++)
    {
        k = i*(i+1);
        k /= 2;
        if (k>sum)
        {
            h = i-1;
            break;
        }
    }
    solve_Optimized();
    return 0;
}
