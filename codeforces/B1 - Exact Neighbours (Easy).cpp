#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int inf = 2e18+8;
const int NN = 2e5+5;
int n , tc=1;
int arr[NN];

void solve()
{
    cout << "YES" << endl;

    for (int i=1 ; i<=n ; i++)
    {
        cout << i << " " << i << endl;
    }
    for (int i=1 ; i<=n ; i++)
    {
        if (i > arr[i])
        {
            cout << i - arr[i] << " ";
        }
        else
        {
            cout << i + arr[i] << " ";
        }
    }
    cout << endl;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ///cin >> tc;
    while(tc--)
    {
        cin >> n;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
            arr[i] /= 2;
        }
        solve();
    }

    return 0;
}
