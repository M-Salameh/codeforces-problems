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
        string s;
        cin >> s;
        if(s=="++X" or s=="X++") ans++;
        else ans--;

    }
    cout<<ans<<endl;
    return 0;
}
