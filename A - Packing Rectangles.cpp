#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define mid (l+r)/2
using namespace std;

int n ,h ,w ;

bool enough (int side)
{
    int x = side/h;
    int y = side/w;
    if (x*y >= n) return true;
    return false;
}

signed main()
{
   /// ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> w >> h >> n;

    int l = 0;
    int r = 1;

    while(!enough(r)) r*=2;

    while (l < r)
    {
        if (enough(mid)) r = mid;
        else l = mid+1;
    }

    cout << r  << endl;

    return 0;
}
