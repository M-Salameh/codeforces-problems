#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int tc=1;
int n;

void solveF()
{
    for (int i=1 ; i<=n ; i++)
    {
        cout << i << ' ';
    }
    cout << endl;
    return;
}
signed main()
{

    fast;
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        solveF();
    }
    return 0;
}
