#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
using namespace std;

int tc=1;
int n;

void solve()
{
    int arr[n+1];
    for (int i=1 ;i<=n ; i++) cin >> arr[i];
    int ascend = 1e8+1, descend=0;
    for (int i=1 ; i < n ; i++)
    {
        if (arr[i]<arr[i+1])
        {
            ascend = min (ascend , (arr[i]+arr[i+1])/2);
        }
        if (arr[i]>arr[i+1])
        {
            descend = max (descend , (1+arr[i]+arr[i+1])/2);
        }
    }
    if (descend <= ascend)
    {
        cout << descend << endl;
    }
    else cout <<-1<<endl;
    return;

}

signed main()
{
    fast;
    cin >> tc;
    while (tc--)
    {
        cin >> n ;
        solve();
    }
    return 0;
}
