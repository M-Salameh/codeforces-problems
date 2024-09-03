#include <bits/stdc++.h>
#define ll long long
#define inf int(1e7+5)
#define fori(n) for (ll i=1;i<=n ; i++)
#define NO cout <<"NO\n"
#define YES cout << "YES\n"
using namespace std;

ll a[inf];
ll b[inf];
ll one;
ll mone;
ll n;
ll tc;
void solve()
{
    one=mone=0;
    fori(n)
    {
        cin >> a[i];
        if (a[i]==1 && one==0)
        {
            one=i;
        }
        if (a[i]==-1 && mone==0)
        {
            mone=i;
        }
    }
    fori(n)
    {
        cin >> b[i];
    }
    for (ll i=1 ; i <= n ;i++)
    {
        if (b[i]>a[i])
        {
            if (one>=i || !one )
            {
                NO;
                return;
            }
        }
        if (b[i]<a[i] )
        {
            if (mone>=i || !mone)
            {
                NO;
                return;
            }
        }
    }
    YES;
    return;
}

int main()
{
    cin >>tc;
    while (tc--)
    {
        cin >> n ;
        solve();
    }
    return 0;
}
