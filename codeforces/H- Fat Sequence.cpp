#include <bits/stdc++.h>
#define ll long long
#define NN int(1e6+9)
#define MOD 1000000007
using namespace std;

ll fib[NN];

void init ()
{
    fib[0]=0;
    fib[1]=1;
    for (ll i=2 ; i< NN ; i++)
    {
        fib[i] = ((fib[i-1]%MOD) + fib[i-2]%MOD)%MOD;
    }
}

ll s[NN];

void solve()
{
    s[0]=0;
    s[1]=1;
    s[2]=2;
    for (ll i=3 ;i <NN ; i++)
    {
        s[i] = (s[i-1]%MOD+fib[i]%MOD)%MOD;
    }
}
ll t , n;
int main()
{
    init();
    solve();
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << s[n]<<endl;
    }
    return 0;
}
