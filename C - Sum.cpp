#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#include <string>
using namespace std;

int tc;
int arr[3];

void solve()
{
    sort(arr , arr+3);
    if (arr[2] == (arr[1]+arr[0]))
    {
        cout <<"YES\n";
        return;
    }
    cout << "NO\n";
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> tc ;
    while(tc--)
    {
        cin >> arr[0] >> arr[1] >> arr[2];
        solve();
    }


    return 0;
}
