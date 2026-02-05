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
    if (gcd_sum(n) != 1)
    {
        cout << n << endl;
    }
    else if(gcd_sum(n+1) != 1)
    {
        cout << n+1 <<endl;
    }
    else cout <<n+2 <<endl;
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
