#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
int MOD = 1e9+7;

int power(signed a,signed b)
{
    if(b==0)return 1;
    int res = power(a,b/2);
    res = (res*res) % MOD;
    if (b&1) res = (a*res) % MOD;
    return res;
}

int fact[100100];

void factor()
{
    fact[0] = 1;
    for(int i=1 ; i <= 100002 ; i++)
    {
        fact[i] = i*fact[i-1];
        fact[i] %= (MOD-1);
    }
}

int tc=1;


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    factor();
    while(tc--)
    {
        signed a,b,n;
        cin >> a >> b >> n;
        int p = min(a,b);
        int ans = power(n,fact[p]);
        cout << ans <<endl;
    }
    return 0;
}
