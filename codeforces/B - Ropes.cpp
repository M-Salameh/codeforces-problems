#include <bits/stdc++.h>
#include <math.h>
#define endl '\n'
#define int long long
#define double long double
#define mid (l+r)/2
using namespace std;

int n,k;
vector<int> arr;

void read()
{
    arr.clear();
    cin >> n >> k;
    for (int i=1 ; i<=n  ; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
}

bool enough(double x)
{
    int sum = 0;
    for (auto i : arr) sum += floor(i/x);
    return sum >= k;
}

void solve()
{
    double l = 0.0;
    double r = 1e8;

    int precis = 100;

    while ( precis-- )
    {
        if (enough(mid)) l = mid;
        else r = mid;
    }
    cout << setprecision(10) << l << endl;

}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    read();

    solve();

    return 0;
}
