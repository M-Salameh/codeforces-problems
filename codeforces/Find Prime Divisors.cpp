#include <bits/stdc++.h>
#define ll long long

using namespace std;

set <ll> divisors;
ll n;
void find_divisors(ll a)
{
    if (a<=1)
    {
        cout << a << endl;
        return;
    }
    else
    {
        ll i=2;
        ll b=a;
        for (ll j=2 ; j<=b/j ; j++)
        {
            if (b%j == 0)
            {
                divisors.insert(j);
                divisors.insert(b/j);

            }
        }
    }
}

int main()
{
    cin >> n ;
    find_divisors(n);
    for (auto i=divisors.begin() ; i!=divisors.end() ; i++)
    {
        cout << *i << " , ";
    }
    return 0;
}
