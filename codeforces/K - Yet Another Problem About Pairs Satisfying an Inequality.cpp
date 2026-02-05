#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define mid (l+r)/2
using namespace std;

int tc;
int n;

void solve()
{
    vector<pair<int,int>>arr;
    int a;
    for (int i=1;i<=n ; i++)
    {
        cin >> a;
        if (a<i) arr.push_back(make_pair(a,i));
    }
    sort(arr.begin() , arr.end());
    n = arr.size();
    vector<int> val;
    vector<int> pos;
    for (int i=0 ;i<n; i++)
    {
        val.push_back(arr[i].first);
        pos.push_back(arr[i].second);
    }
    int ans=0;
    int x;
    for (int i=0 ;i<n ; i++)
    {
        x = upper_bound(val.begin() , val.end() , pos[i])- val.begin();
        ///cout <<"x = " <<  x <<endl;
        ans += (n-x);
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc ;
    while (tc--)
    {
        cin >> n ;
        solve();
    }
    return 0;
}
