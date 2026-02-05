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

int mypow (int a , int b)
{
    if (b == 1) return a;
    if (b == 0) return 1;
    if (b&1) return b * mypow(a,b/2) *mypow(a,b/2);
    else return mypow(a,b/2) *mypow(a,b/2);
}

void solve()
{
    int arr[n+1];
    for (int i=1 ; i<=n ;i++) cin >> arr[i];

    int p1 = 1;
    int p2 = 1;
    int ans = 0;
    int acc=arr[1];
    while (p1 <= p2 && p2 <= n)
    {
        if (arr[p2] < x) ans++;
        if (arr[p2] >= x)
        {
            p1 = p2+1;
            p2 = p1;
            acc = 0;
            if (p1<=n) acc = arr[p1];
            continue;
        }
        if (p1 != p2)
        {
            acc += arr[p2];
            if (acc < x) ans+=(p2-p1);
            else
            {
                while (acc >= x and p1<=n and p1<=p2)
                {
                    acc-=arr[p1];
                    p1++;
                }
                if (acc < x) ans+=(p2-p1);
            }
        }
        p2++;
    }

    cout <<ans << endl;
    return;
}

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
       /// cin >> n >> x;
        solve_M();
    }
    return 0;
}
