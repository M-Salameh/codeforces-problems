#include <bits/stdc++.h>
#define int long long
#define double long double
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mid (l+r)/2
#define lc 2*node
#define rc 2*node+1
#define endl '\n'
#define MOD 1000000007
///#define long __int128

using namespace std;

int tc = 1;

int n , k;
int c;

void solve()
{
    cin >> n;
    vector<pair<int,int>> v;
    for (int i=1 ; i<=n ; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > 10) continue;
        v.push_back({b,i});
    }
    sort(v.begin() , v.end());
    cout << v[v.size()-1].second << endl;
}


signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
