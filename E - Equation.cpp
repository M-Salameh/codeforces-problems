#include <bits/stdc++.h>
#include <math.h>
#define endl '\n'
#define int long long
#define double long double
#define mid (l+r)/2.00
using namespace std;


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    double c;
    cin >> c;
    double l=0;
    double r = 1e15;
    for (int i=1 ; i<=200 ; i++)
    {
        double x = (double)mid;
        if (x*x + (double)sqrt(x) < c)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
       
    }
    cout << setprecision(15) << r << endl;

    return 0;
}
