#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int inf = 1e17+8;
const int NN = 1e5+5;
int n , tc=1;
int m;
vector<vector<int>> arr , pref;

void solve()
{
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=m ; j++)
        {
            pref[i][j] = 1;
            if (arr[i][j] >= arr[i-1][j]) pref[i][j] += pref[i-1][j];
        }
    }
    vector<int> rows (n+1 , 0);

    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=m ; j++)
        {
            rows[i] = max(rows[i] ,  pref[i][j]);
        }
    }

    int k;
    cin >> k;
    while (k--)
    {
        int l , r;
        cin >> l >> r;

        int yes = r-l+1;
        if (rows[r] >= yes)
        {
            cout << "Yes" <<endl;
        }
        else cout <<"No" << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ///cin >> tc;

    while(tc--)
    {
        cin >> n >> m;
        arr = vector<vector<int>> (n+1 , vector<int>(m+1 , 0));
        pref = vector<vector<int>> (n+1 , vector<int>(m+1 , 0));
        for (int i=1 ; i<=n ; i++)
        {
            for (int j=1 ; j<=m ; j++)
            {
                cin >> arr[i][j];
            }
        }
        solve();
    }

    return 0;
}
