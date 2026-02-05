#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int tc;
int n;

void solve()
{
    vector<int> arr;
    int x;
    for(int i=1 ;i<=n ;i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin() , arr.end());
    int ans = arr[0];
    if (n==1)
    {
        cout << arr[0] << endl;
        return;
    }

    for (int i=1 ;i<n;i++)
    {
        ans = max (ans , arr[i] - arr[i-1]);
    }
    cout << ans << endl;

}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while (tc--)
    {
        cin >> n ;
        solve();
    }

    return 0;
}
