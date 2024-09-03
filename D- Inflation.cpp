#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'

using namespace std;

int tc ;
int n , k;

void solve()
{
    int p[n+1];
    p[0] = 0;
    int sum[n+1];
    sum[0]=0;
    for (int i=1;i<=n ; i++)
    {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i-1];
    }
    int ans=0;
    int x;
    double c;
    for (int i=n ;i>1 ; i--)
    {
        if (p[i]*100 > k*sum[i])
        {
            c = p[i]*100*1.0;
            x = ceil(c/k);
            ans+= abs(x-sum[i]);
        }
        sum[i-1]+=ans;
    }
    cout << ans << endl;

}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while (tc--)
    {
        cin >> n >> k ;
        solve();
    }
    return 0;
}


