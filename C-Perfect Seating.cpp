#include <bits/stdc++.h>
#define NN int(1e4+3)
#define ll long long
using namespace std;

ll arr[NN];
ll n , t;

void solve()
{
    bool fl=false;
    for (ll i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
        if (arr[i]<arr[i-1])
        {
            fl = true;
        }
    }
    if (fl)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    return;
}

int main()
{
    cin >>t ;
    while (t--)
    {
        cin >> n ;
        solve();
    }
    return 0;
}
