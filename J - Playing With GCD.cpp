#include <bits/stdc++.h>
#define int long long
#include <math.h>
#define endl '\n'
using namespace std;

int tc;
int n;

int LCM(int x , int y)
{
    int a = __gcd(x,y);
    return (x*y)/a;
}

void solve()
{
    vector<int> a(n+5,1);
    vector<int> b(n+5,0);

    ///vector<int> gcd (n+2);
    for (int i=1 ;i<=n ; i++)
    {
        cin>>a[i];
        b[i] = LCM(a[i],a[i-1]);
    }
    b[n+1] = LCM(a[n+1] , a[n]);
    for (int i=1 ;i<=n ; i++)
    {
        if (__gcd(b[i],b[i+1])-a[i])
        {
            cout << "NO" <<endl;
            return;
        }
    }
   /** for(int i=1; i<=n+1 ; i++)
    {
        cout << b[i]<<',';
    }*/
    cout <<"YES" <<endl;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc ;
    while (tc--)
    {
        cin >> n ;
        solve();
    }
    return 0;
}
