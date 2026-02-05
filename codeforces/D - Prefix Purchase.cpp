#include <bits/stdc++.h>
#include <math.h>
#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
using namespace std;

int tc=1;
int n;
int k;
const int inf = 1e11;
vector<int> suffix;
vector<int> arr;


void solve()
{
    suffix = vector<int>(n+1, inf);
    suffix[n] = arr[n];

    for (int i=n-1 ; i>0 ; i--)
    {
        suffix[i] = min (arr[i] , suffix[i+1]);
    }

    for (int i=n-1 ;i>0; i--)
    {
        suffix[i+1] -= suffix[i];
    }

    int pos=1;
    int val=1e15;

    while (pos <= n)
    {
        if (suffix[pos])
        {
            val = min(val , k/suffix[pos]);
        }
        cout << val << ' ';
        pos++;
        k-= val*suffix[pos-1];
    }

    cout << endl;
    return;

}

signed main()
{
    fast

    cin >> tc;
    while(tc--)
    {
        cin >> n;
        arr = vector<int>(n+1 , 0);
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
        }
        cin >> k;
        solve();

    }


    return 0;
}
