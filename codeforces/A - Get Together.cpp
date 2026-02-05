#include <bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define double long double
#define endl '\n'
using namespace std;
const int MOD = 1e9+7;


signed main()
{
    fast;
    int n;
    cin >> n;
    int x[n], v[n];

    for(int i=0;i<n;i++)
    {
        cin >> x[i] >> v[i];
    }


    double low = -1e9, high = 1e9, ans = (double)1e9, mid;

    for(int j=1 ; j <= 200 ; j++)
    {
        mid = (double)(low+high)/(double)2.00;

        double a = mid, a1 = mid + 1e-6;

        double tt = 0, tt1 = 0;

        for(int i=0 ; i<n ; i++)
        {
            tt = max(tt, (double)abs(x[i]-a)/(double)v[i]);
        }

        for(int i=0 ; i<n ; i++)
        {
            tt1 = max(tt1, (double)abs(x[i]-a1)/(double)v[i]);
        }

        if( tt > tt1)
        {
            ans = min(ans, tt1);
            low = mid;
        }
        else
        {
            ans = min(ans, tt);
            high = mid;
        }
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;

    return 0;
}
