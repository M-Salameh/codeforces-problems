#include <bits/stdc++.h>
#include <math.h>
#define endl '\n'
#define int long long
#define double long double
#define mid (l+r)/2
using namespace std;

int n,x,y;


void solve()
{

}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n  >> x >> y;

    int l = 0 ;
    int r = 2e9;
    int ans = 0;
    int total = 1;
    int tim , cp1 , cp2;

    while (l<r)
    {
        tim = mid;
        cp1 = tim/x;
        cp2 = tim/y;

        if (cp1+cp2 >= n-1)
        {
            ans = tim;
            r = tim;
        }
        else l = mid+1;
    }

    cout << ans + min(x,y) << endl;

    return 0;
}
