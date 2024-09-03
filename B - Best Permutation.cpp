#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e6+9;

ll ans;
ll tc;
ll n;
ll col;
ll cmp;

void solve()
{
    ll m=n%3;
    if (m == 2)
    {
        for (ll i=1 ; i<=n ; i++)
        {
            cout << i << " ";
        }
        cout <<endl;
        return;
    }
    if (m==1)
    {
        for (ll i=1 ; i<=n ; i++)
        {
            if (i==1)cout << "2 ";
          else  if (i==2)cout << "1 ";
            else cout << i << " ";
        }
        cout << endl;
        return;
    }
    if (m==0)
    {
        for (ll i=1 ; i<=n ; i++)
        {
            if (i==3)cout << "4 ";
            else if (i==4)cout << "3 ";
            else cout <<i<<" ";
        }
        cout << endl;
        return;
    }
}


int main()
{
    cin >> tc;
    while (tc--)
    {
        cin >> n ;
        solve();
    }

    return 0;
}
