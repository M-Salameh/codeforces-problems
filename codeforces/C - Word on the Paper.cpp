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
    vector<char> ans;
    for (int i=1 ; i<=8 ; i++)
    {
        for (int j=1 ; j<=8 ; j++)
        {
            char x;
            cin >> x;
            if (x != '.')
            {
                ans.push_back(x);
            }
        }
    }
    for (auto i : ans ) cout << i;
    cout  << endl;
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
