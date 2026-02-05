#include <bits/stdc++.h>
#include<string>
#define endl '\n'
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
//#define double long double

using namespace std;
int tc=1;
int n;
int k;

int power(int a , int b)
{
    if (b==0) return 1;
    if (b==1) return a;
    int res = power(a,b/2) % MOD;
    res = (res*res) % MOD;
    if (b&1) res = (a*res)%MOD;
    return res%MOD;
}

void solve()
{
    cin >> n >> k;
    vector<int> arr(n+2,0);
    vector<int> diff;
    for (int i=1 ;i<=n ; i++)
    {
        cin >> arr[i];
    }
    for (int i=1 ;i<n; i++) diff.push_back(abs(arr[i+1] - arr[i]));

    sort(diff.begin() , diff.end());

    int ans = 0;
    if (diff.size()-k < 0)
    {
        cout << 0 << endl;
        return;
    }
    for (int i=0 ; i <= diff.size()-k; i++)
    {
        ans += diff[i];
    }
    cout << ans << endl;
}

signed main()
{
    fast;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
