#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int tc;
int n;

int arr[202020];

void solve()
{
    if (n&1)
    {
        cout << -1 << endl;
        return;
    }
    vector<pair<int,int>> ans;
    for (int i=1 ;i<=n ; i+=2)
    {
        if (arr[i]==arr[i+1])
        {
            ans.push_back({i,i+1});
        }
        else
        {
            ans.push_back({i,i});
            ans.push_back({i+1,i+1});
        }
    }
    cout << ans.size() <<endl;
    for (auto i : ans)
    {
        cout << i.first << ' ' << i.second <<endl;
    }
}

signed main()
{
    fast_io;
    cin >> tc;
    while(tc--)
    {
        cin >> n ;
        for (int i=1; i<=n ; i++)
        {
            cin >> arr[i];
        }
        arr[n+1]=0;
        solve();
    }
    return 0;
}
