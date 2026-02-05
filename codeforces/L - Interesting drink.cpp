#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n;
int q,x;
void solve()
{
    vector<int> arr(n);
    for (int i = 0 ; i < n ; i++ )
    {
        cin >> arr[i];
    }
    sort (arr.begin() , arr.end());
    cin >> q;
    while (q--)
    {
        cin >> x;
        cout << (upper_bound(arr.begin(),arr.end(),x)- arr.begin()) << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n ;
    solve();
    return 0;
}
