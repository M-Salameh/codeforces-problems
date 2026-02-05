#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int tc;
int n , c;

void solve()
{
    int ans=0;
    int x;
    int arr[n+2];
    for (int i=1 ;i<=n ; i++)
    {
        cin >> arr[i];
        arr[i]+=i;
    }
    sort(arr+1 , arr+n+1);
    int i=1;
    while (arr[i]<=c &&i<=n)
    {
        c-=arr[i];
        i++;
        ans++;
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n >> c;
        solve();
    }
    return 0;
}
