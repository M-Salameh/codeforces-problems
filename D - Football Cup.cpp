#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int tc=1;
int n,k;
string bash = "Bashar";
string ham = "Hamada";
string isk = "Iskandar";


signed main()
{

    fast;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> k;
        if (n > k) cout << bash <<endl;
        else if (n  < k) cout << ham << endl;
        else cout << isk << endl;
    }
    return 0;
}
