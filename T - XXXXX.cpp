#include <bits/stdc++.h>
#define int long long
#include <math.h>
#define endl '\n'
using namespace std;

int tc=1;
int n , x;


void solve()
{
    int c;
    int pos=-1;
    int sum=0;
    for (int i=1 ;i<=n ; i++)
    {
        cin >> c ;
        sum+=c;
        if (sum%x)
        {
            pos = max(pos , max (i , n-i));
        }
    }
    cout << pos << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc ;
    while (tc--)
    {
        cin >>n >> x;
        solve();
    }
    return 0;
}
