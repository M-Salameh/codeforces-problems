#include <bits/stdc++.h>
#include <math.h>
#define int long long
#define double long double
#define endl '\n'
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define eps 1e-6
using namespace std;

int tc=1;
int n,x;

void solve_M()
{
    string big = "Congrats";
    string smal = "HaHa";
    string same = "Lazy";
    int b1,p1,b2,p2;
    cin >> b1 >> p1 >> b2 >> p2;
    if (b1==0)
    {
        if (b2>0)
        {
            cout << big <<endl;
            return;
        }
        cout << same << endl;
        return;
    }
    if (b2==0)
    {
        if (b1>0)
        {
            cout << smal <<endl;
            return;
        }
        cout << same << endl;
        return;
    }
    double a = p1*log2(b1);
    double b = p2*log2(b2);
    if (abs(a-b) <= eps)
    {
        cout << same << endl;
        return;
    }
    if (a > b ) cout << smal <<endl;
    else cout << big << endl;

    return;
}

signed main()
{

    fast;
    cin >> tc;
    while (tc--)
    {
        solve_M();
    }
    return 0;
}
