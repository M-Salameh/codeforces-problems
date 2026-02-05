#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#include <string>
using namespace std;

int tc;
int n,k;

void solve()
{
    string s;
    cin >> s ;
    if (s.size() == 1)
    {
        if (s=="W")
        {
            cout << 1 << endl;
        }
        else cout << 0 << endl;
        return;
    }
    vector<int> W_freq (n+5 , 0);
    for (int i=1 ; i<=n ;i++)
    {
        W_freq[i] = W_freq[i-1];
        if (s[i-1]=='W') W_freq[i]++;
    }

    int ans = 1e10;
    for (int i=k ; i<=n ; i++)
    {
        ans = min(ans , W_freq[i] - W_freq[i-k]);
    }
    cout << ans << endl;
    return;

}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> tc ;
    while(tc--)
    {
        cin >> n >> k;
        solve();
    }


    return 0;
}
