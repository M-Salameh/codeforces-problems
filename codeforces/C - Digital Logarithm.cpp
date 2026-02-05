#include <bits/stdc++.h>
#define ll long long
#include <math.h>
using namespace std;

const int inf = 1e6+9;

ll tc;
ll n;
ll ans;

ll f (ll x)
{
    if (x==1)return x;
    ll j=ceil(log10(x));
    if (j == floor (log10(x)))
    {
        return j+1;
    }
    else return j;
}

void solve()
{
    priority_queue <ll> a;
    priority_queue <ll> b;
    ll x;
    for (ll i=1 ; i<=n ; i++)
    {
        cin >> x;
        a.push(x);
    }
    for (ll i=1 ; i<=n ; i++)
    {
        cin >> x;
        b.push(x);
    }
    while (a.size() != 0)
    {
        if (a.top() == b.top())
        {
            a.pop();
            b.pop();
        }
        else
        {
            if (a.top() > b.top())
            {
                a.push(f(a.top()));
                a.pop();
                ans++;
            }
            else
            {
                b.push(f(b.top()));
                b.pop();
                ans++;
            }
        }
    }
}

int main()
{
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        solve();
        cout << ans <<endl;
        ans=0;
    }
    return 0;
}
