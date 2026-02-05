#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int NN = 1e5+5;
const int inf = 1e17+9;
int tc=1;
int n;
int x,y;
vector<int> pos;

void solve()
{
    if (pos.size() == 0)
    {
        cout << 0 << endl;
        return;
    }
    n = pos.size();

    if(x >= y)
    {
        if (n > 2)
        {
            cout << n*y/2 << endl;
            return;
        }
        if (pos[1]-pos[0] == 1)
        {
            cout << min (2*y , x) << endl;
            return;
        }
        cout << y << endl;
        return;
    }
    vector<int> dp (n+1 , inf);

    dp[0]=0;
    dp[1] = min(y , x*(pos[1]-pos[0]));

    for (int i=2 ; i<n; i++)
    {
        int d = dp[i-2] + x*(pos[i] - pos[i-1]);
        dp[i] = min (dp[i-1] + y*(i&1) , d);
    }

    cout << dp[n-1] << endl;
    return;
}


signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        cin >> x >> y;
        string a,b;
        pos.clear();
        cin >> a >> b;
        for (int i=0 ; i<n ; i++)
        {
            if (a[i] != b[i])
            {
                pos.push_back(i);
            }
        }
        if (pos.size() & 1)
        {
            cout << -1 << endl;
            continue;
        }
        solve();
    }
    return 0;
}


