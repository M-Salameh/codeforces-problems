#include <bits/stdc++.h>
///#define int long long
#define endl '\n'
using namespace std;

const int N=5e5+10;

vector<int> divs[N];

int a,b,m1,m2;
int tc=1;

void sieve()
{
    for(int i=1 ; i<=5e5 ; i++)
    {
        for(int j=i ; j<=5e5 ; j+=i)
        {
            divs[j].push_back(i);
        }
    }
}

void solve()
{
    cin >> a >> b >> m1 >> m2;
    int x = a-m1;
    int y = b-m2;
    if(x<0 || y<0)
    {
        cout<< -1 <<endl;
        return;
    }
    if(x==0 && y==0)
    {
        cout << max(a,b)+1 <<endl;
        return;
    }
    x = __gcd(x,y);
    int ans = INT_MAX;
    for(auto i : divs[x])
    {
        if ( (a%i == m1) && (b%i == m2) )
        {
            ans=min(ans,i);
        }
    }
    if(ans == INT_MAX ) ans=-1;
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sieve();
    cin >> tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
