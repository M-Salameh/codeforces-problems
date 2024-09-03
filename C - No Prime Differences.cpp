#include <bits/stdc++.h>
#define int long long
#define double long double
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mid (l+r)/2
#define lc 2*node
#define rc 2*node+1
#define endl '\n'
#define inf LONG_LONG_MAX
using namespace std;

int tc=1;
int n , m;

vector<vector<int>> ans;

bool prime[1010];

void sieve()
{
    for (int i=0 ; i<1010 ; i++) prime[i]=true;

    for (int i=2 ; i<=1001 ; i++)
    {
        if (prime[i])
        {
            for (int j=i+i ; j<=1001 ; j+=i) prime[j] = false;
        }
    }
    return;
}


void solve()
{
    ans = vector<vector<int>>(n+1,vector<int>(m+1,0));
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=m ; j++)
        {
            ans[i][j] = (i-1)*m + j;
        }
    }
    if (!prime[m])
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=m ; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    else
    {
        for (int i=2 ; i<=n ; i+=2)
        {
            for (int j=1 ; j<=m ; j++)
            {
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
        for (int i=1 ; i<=n ; i+=2)
        {
            for (int j=1 ; j<=m ; j++)
            {
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return;
}

void reset()
{
    for (auto i : ans)
    {
        i.clear();
    }
}


signed main()
{
    fast;
    sieve();
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        solve();
        reset();
    }
    return 0;
}
