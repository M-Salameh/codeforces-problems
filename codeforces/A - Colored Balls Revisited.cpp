#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e6+9;

ll ans=-inf;
ll tc;
ll n;
ll col;
ll cmp;
int main()
{
    cin >> tc;
    while (tc--)
    {
        cin >> n ;
        for (ll i=1 ; i<=n ; i++)
        {
            cin>>col;
            if (col>ans)
            {
                ans = col;
                cmp=i;
            }
        }
        cout << cmp <<endl;
        ans=-inf;
    }
    return 0;
}
