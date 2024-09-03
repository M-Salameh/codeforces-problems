#include <bits/stdc++.h>
#include <math.h>
#define int long long
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int maxn = 2e5+5;
int arr[maxn];
int n,tc;

void solve()
{
    sort(arr+1,arr+n+1);
    int ans = floor (n/2);
    int curpair=0;
    for (int i=1 ;i<=n ;i++)
    {
        if (arr[i]<arr[i+1])
        {
            curpair = i*(n-i);
            ans = max (ans , curpair);
        }
    }
    cout << ans << endl;
}
signed main()
{
    //fast_io;
  /* cin >>tc;
    while(tc--)
    {
        cin >> n;
        for(int i=1 ;i<=n ; i++)
        {
            cin >> arr[i];
        }
        arr[n+1]=-INT_MAX;
        solve();
    }*/
    long long p;

long long inv[MAXN + 5], pro[MAXN + 5], pin[MAXN + 5];

long long Ans = 0;

int main()
{
    scanf("%d%lld", &n, &p);

    inv[1] = 1;
    for (int i = 2; i <= n; ++i) inv[i] = (p - p / i) * inv[p % i] % p;
    pro[0] = 1, pin[0] = 1;
    for (int i = 1; i <= n; ++i) pro[i] = pro[i - 1] * i % p, pin[i] = pin[i - 1] * inv[i] % p;

    for (int i = 1; (i << 1) < n; ++i)
        for (int j = 0; j < i; ++j)
            Ans = (Ans + pro[i - 1] * pin[i - 1 - j] % p * pin[j] % p * pro[n - 3 - j] % p * ((n >> 1 << 1) - (n - i - 1)) % p * n) % p;
    if (!(n & 1)) Ans = (Ans + pro[n - 2] * n) % p;

    printf("%lld\n", Ans);
    return 0;
}
