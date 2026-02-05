#include <bits/stdc++.h>
#define ll long long
#define inf int(1e7+5)
#define fori(n) for (ll i=1;i<=n ; i++)
#define NO cout <<"NO\n"
#define YES cout << "YES\n"
using namespace std;

ll n,x;
ll a[inf];
bool done[inf];
void solve ()
{
    memset(done , false , sizeof(done));
    fori (n)
    {
        cin >> a[i];
        done[a[i]]=true;
    }
    ll i=1;
    ll ans=0;
    while (x)
    {
        if (!done[i])
        {
            x--;
            ans++;
        }
        i++;
        ans++;
    }
    cout << ans <<endl;
}

int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> x ;
        solve();
    }
    return 0;
}
