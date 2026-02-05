#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int tc;
int n ;
int small , most;
bool check(int x)
{
    if (x == most || x==small)
    {
        return false;
    }
    return true;
}
void update(pair<int,int> x , pair<int,int> y)
{
    small = min (x.first , y.first);
    most = max (x.second , y.second);
    return;
}

void solve()
{
    vector<int> arr(n+1);
    for (int i=1 ;i<=n ; i++)
    {
        cin >> arr[i];
    }
    most = n , small = 1;
    int p1=1 , p2 = n;
    pair<int,int> ans = {0,0};

    while(p1 < p2)
    {
        if (arr[p2]==small) small++,p2--;
        else if (arr[p2]==most) p2-- , most--;
        else if (arr[p1] == small) small++,p1++;
        else if (arr[p1]==most) most--,p1++;
        else
        {
            if (p1<p2) cout << p1 << ' ' << p2 << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;

    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n ;
        solve();
    }
    return 0;
}
