#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int inf = 2e18+8;
const int NN = 2e5+5;
int n , tc=1;
int arr[NN] , brr[NN];


map<int,bool> visited;
map<int,int> pos;

void solve()
{
    int loops = 0;
    visited.clear();
    for (int i=1 ; i <=n ; i++)
    {
        if (visited[i]) continue;

        visited[i] = true;

        int nxt = i;
        loops++;

        while (true)
        {
            nxt = pos[arr[nxt]];

            if (visited[nxt]) break;

            visited[nxt] = true;
        }

      }

    n -= loops;

    if (n&1)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
        }
        pos.clear();
        for (int i=1 ; i<=n ; i++)
        {
            cin >> brr[i];
            pos[brr[i]] = i;
        }

        bool ok = true;
        for (int i=1 ; i<=n ; i++)
        {
            if (pos.find(arr[i]) == pos.end())
            {
                cout << "NO" << endl;
                ok = false;
                break;
            }
        }

        if (ok) solve();
    }

    return 0;
}
