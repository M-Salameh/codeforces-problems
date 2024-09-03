#include <bits/stdc++.h>
#define int long long
#include <math.h>
#define endl '\n'
using namespace std;

int tc=1;
int n;
int a,b;

int LCM(int x , int y)
{
    int a = __gcd(x,y);
    return (x*y)/a;
}

int gcd_sum (int x)
{
    int ans=0;
    int y=x;
    while (x>0)
    {
        ans += x%10;
        x/=10;
    }
    ans = __gcd(y,ans);
    return ans;
}



void solve()
{
    int ans=1;
    for (int i=2 ; i*i <= n ; i++)
    {
        if (!(n%i))
        {
            if (LCM(i , n/i) == n)
                ans = i;
        }
    }
    cout << ans << ' ' << n/ans <<endl;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ///cin >> tc ;
    while (tc--)
    {
        cin >> n ;
        solve();
    }
    return 0;
}
