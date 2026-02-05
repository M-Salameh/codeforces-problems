#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int tc=1;

signed main()
{

    fast;
    //cin >> tc;
    while (tc--)
    {
        string s;
        getline(cin,s);
        bool f=false;
        for (auto i : s)
        {
            if (i=='9')
            {
                f=true;
                break;
            }
        }
        if (f) cout <<"F"<<endl;
        else cout << "S" <<endl;
    }
    return 0;
}
