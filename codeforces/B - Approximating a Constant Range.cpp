#include <bits/stdc++.h>
///#define int long long
#define double long double
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mid (l+r)/2
#define lc 2*node
#define rc 2*node+1
#define endl '\n'
#define MOD 1000000007
using namespace std;

int tc = 1;
int n;

vector<int> arr;

void solve()
{
    multiset<int> ms;
    int l=1 , r=1;
    int ans = 1;
    ms.insert(arr[l]);
    while(l<=r and r<=n)
    {
        if (abs(*--ms.end() - *ms.begin()) < 2)
        {
            ans = max (ans , r-l+1);
            r++;
            ms.insert(arr[r]);
        }
        else
        {
            ms.erase(ms.find(arr[l]));
            l++;
        }
    }
    cout << ans << endl;
    return;
}

signed main()
{
    cin >> n;
    arr = vector<int> (n+1,0);
    for (int i = 1 ; i<=n ; i++)
    {
        cin >> arr[i];
    }
    solve();


    /*int l=1 , r=1;
    int ans = 0;
    int diff = 0;
    int mx = 0 , mn = 1e6;
    int posl;
    while( l<=r and r<=n)
    {
        mx = max (mx , arr[r]);
        if (arr[r] <= mn)
        {
            posl = r;
            mn = arr[r];
        }
        diff = abs (mx - mn);
        if (diff < 2)
        {
            ans = max (ans , r-l+1);
            r++;
        }
        else
        {
            l = posl+1;
        }
    }
    cout << ans << endl;*/
    return 0;
}
