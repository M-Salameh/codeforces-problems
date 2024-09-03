#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int NN = 2e5+5;
const int MOD = 1000000000+7;
int tc = 1;
int n,m;

int pref[NN];
int st[NN] , en[NN];

signed main()
{
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> st[i] >> en[i];
            pref[1+en[i]] += st[i];
        }
        for (int i=1 ; i<=m ; i++)
        {
            pref[i] += pref[i-1];
        }
        int ans = 0;
        for (int i=1 ; i<=n ; i++)
        {
            ans = ((ans%MOD + (pref[st[i]] * (m-en[i]+1) %MOD)%MOD) + MOD )%MOD;
        }
        cout << ans << endl;
        for (int i=0 ; i<=m+1 ; i++) pref[i] = 0;
    }

    return 0;
}
