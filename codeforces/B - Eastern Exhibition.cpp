#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll tc;
    cin >> tc ;
    ll n;
    ll rng_x;
    ll rng_y;
    ll ans;
    while (tc--)
    {
        cin >> n;
        vector<ll> x(n),y(n);
        for (ll i=0 ; i<n ; i++)
        {
            cin >> x[i] >> y[i];
        }
        sort(x.begin() , x.end());
        sort(y.begin() , y.end());
        rng_x = x[n/2]-x[(n-1)/2] + 1 ;
        rng_y = y[n/2] - y[(n-1)/2] + 1;
        ans = rng_x * rng_y;
        cout << ans << endl;
    }
    return 0;
}
