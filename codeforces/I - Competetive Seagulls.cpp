#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
using namespace std;

int tc=1;
int n;
int ans;

signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        if (n==2 or n==3) cout <<"second"<<endl;
        else cout << "first" <<endl;

    }
    return 0;
}
