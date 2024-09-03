#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int tc , n;
int a[101010];
int yasser; /// all values


void solve()
{
    if (a[n] <= 0 || a[1] <= 0)
    {
        cout << "NO" <<endl;
        return;
    }
    int r=2;
    int sum=a[1];
    while (r<=n)
    {
        if (sum >= yasser)
        {
            cout << "NO" <<endl;
            return;
        }
        if (sum + a[r] <= 0)
        {
            cout << "NO" <<endl;
            return;
        }
        if (sum + a[r] > 0)
        {
            sum+=a[r];
            r++;
        }
    }
    cout << "YES" <<endl;
    return;
}

signed main()
{
    fast_io;
    cin >> tc ;
    while (tc--)
    {
        cin >> n ;
        yasser = 0;
        a[n+1]=0;
        for (int i=1 ;i<=n ; i++)
        {
            cin >> a[i];
            yasser+=a[i];
        }
        solve();
    }
    return 0;
}
