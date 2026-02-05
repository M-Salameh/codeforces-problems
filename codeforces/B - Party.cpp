#include <bits/stdc++.h>
#define ll long long
#define NN int(1e6+5)
using namespace std;

const ll inf = 1e9+5;

ll arr[NN];

bool pr[NN] ;

ll adj[NN];
ll n,m;
ll x,y;
ll t;
ll minn = inf;
ll deg;
void Read()
{
    cin >> n >> m ;
    fill (adj , adj+n+2 , 0);
    fill (arr , arr+n+2 , 0);
    fill (pr , pr+n+2 , false);
    for (ll i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
    }

    for (ll i=1 ; i<=m ; i++)
    {
        cin >> x >> y ;
        minn = min (minn ,arr[x]+arr[y]);
        adj[x]++;
        adj[y]++;
        pr[x]=true;
        pr[y]=true;
    }
}

void solve()
{
    if (m%2==0)
    {
        cout << 0 << endl;
        return;
    }
    ll ans = minn;
    for (ll i=1 ; i<=n ; i++)
    {
        if (pr[i])
        {
           // cout << " i = " << i << "  , adj[i] = " << adj[i]<<endl;
            if ((m-adj[i])%2 == 0)
            {
                ans = min (ans , arr[i]);
            }
        }
    }
    cout << ans <<endl;
}

int main()
{
    cin >> t ;
    while (t--)
    {
        Read();
        solve();
        minn=inf;
    }
    return 0;
}

