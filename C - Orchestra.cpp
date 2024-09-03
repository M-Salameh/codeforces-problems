
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#define int long long
#define double long double
#define mid (l+r)/2
#define lc 2*node
#define rc lc+1
#define endl '\n'
#define fast  ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int tc=1;
int n;
int r,c;
int x,y;
int k;

void solve()
{
    int x, y;
    vector<vector<bool>>arr (r+1 , vector<bool>(c+1,false));
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y ;
        arr[x][y] = true;
    }
    int ans = 0;
    int cnt = 0;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            for(int z = i; z <= r; z++)
            {
                for(int m = j; m <= c; m++)
                {
                    cnt = 0;
                    for(int p = i; p <= z; p++)
                    {
                        for(int q = j; q <= m; q++)
                        {
                            cnt += arr[p][q];
                        }
                    }
                    ans += (cnt >= k);
                }
            }
        }
    }
    cout << ans <<endl;

    return;
}

signed main()
{
    fast;
  ///  cin >> tc ;
    while (tc--)
    {
        cin >>r >> c >> n >> k;
        solve();
    }

}
