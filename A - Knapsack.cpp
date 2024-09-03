#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n;
int W;
int tc;
int x;

void solve()
{
    cin >> n >> W ;
    vector <pair<int,int>> w;
    vector<int> ans;
    int sum = 0;
    for (int i=1 ; i <= n ; i++)
    {
        cin >> x;
        if (x<=W)
        {
            w.push_back({x,i});
        }
    }
    sort (w.begin() , w.end());
    if (w.size() == 0)
    {
        cout << -1 << endl ;
        return;
    }
    x = (W+1)/2;
    for (int i = w.size()-1 ; i>=0 ; i--)
    {
        sum += w[i].first;
        ans.push_back(w[i].second);
        if (sum >= x)
        {
            sort(ans.begin() , ans.end());
            cout << ans.size() << endl;
            for (auto i : ans)
            {
                cout << i << ' ';
            }
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;

}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
