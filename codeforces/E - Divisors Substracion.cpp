#include <bits/stdc++.h>
#include <math.h>
#define int long long
#define endl '\n'
#include <string>
using namespace std;

int tc=1;



void solve(int n)
{
    if (n<=2)
    {cout<<1<<endl;return ;}
    if (n&1)
    {
        int m = sqrt(n)+1;
        bool f = false;
        for (int i=3 ;i<=m; i++)
        {
            if (!(n%i))
            {
                m = i;
                f= true;
                break;
            }
        }
        if (!f)
        {
            cout << 1 << endl;
            return;
        }
        int ans = 1 + (n-m)/2;
        cout << ans << endl;
        return;
    }
    else
    {
        cout<<n/2<<endl;
        return;
    }

}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  ///  cin >> tc ;
    while(tc--)
    {
        int n;
        cin >> n;
        solve(n);
    }


    return 0;
}
