#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int inf = 2e18+8;
const int NN = 2e5+5;
int n , tc=1;
int m;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        string a , b;
        cin >> a >> b;
        n = b.size();
        m = a.size();
        b = "*" + b;
        a = "&" + a;
        int com = 0;
        for (int i=1 ; i<=n ; i++)
        {
            int temp = 0;
            int x = i;
            for (int j=1 ; j<=m ; j++)
            {
                if (a[j] == b[x] and x<=n)
                {
                    temp ++;
                    x++;
                }
            }
            com = max (com , temp);
        }
        int ans = n+m-com;
        cout << ans << endl;
    }

    return 0;
}
