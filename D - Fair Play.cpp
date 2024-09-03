#include <bits/stdc++.h>
#define ll long long
#define MOD int(1e9+7)
#define NN int(1e6+6)
#include <math.h>
using namespace std;


ll arr[NN];
ll ans=0;
ll cnt=0;
ll n,t;
ll x,y;

void solve()
{
    x = ceil(sqrt(n));
    y = floor(sqrt(n));
    if (x!=y)
    {
        cout << -1 <<endl;
        return;
    }
    y--;
    cout << y <<endl;
    for ( ll i=1 ; i<=y ; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    cin >> t ;
    while (t--)
    {
        cin >> n ;
        n++;
        solve();
    }
    return 0;
}
