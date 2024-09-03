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
#define bitt 32
#define MAX 200200
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


int prefixbits[bitt][MAX];

void bitcount(int *arr)
{
   for (int j = 31; j >= 0; j--)
   {
      prefixbits[j][0] = ((arr[0] >> j) & 1);
      for (int i = 1; i < n; i++)
      {
         prefixbits[j][i] = arr[i] & (1LL << j);
         prefixbits[j][i] += prefixbits[j][i - 1];
      }
   }
   return;
}

int check(int l, int r)
{
   int ans = 0;
   for (int i = 0; i < 32; i++)
    {
          int x;
          if (l == 0) x = prefixbits[i][r];
          else x = prefixbits[i][r] - prefixbits[i][l - 1];
          if (x == r - l + 1) ans = ans | 1LL << i;
   }
   return ans;
}

void solve()
{
    cin >> n;
    int arr[n+2];
    arr[0]=0;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
    }
    int best = arr[1];
    arr[n+1] = 0;
    for (int i=1 ;i<=n ; i++) best &= arr[i];
    int ans = 1;
    if (best)
    {
        cout << 1 << endl;
        return;
    }
    int x=arr[1];
    int ptr = 1;
    ans = 0;
    while (ptr <= n)
    {
        x &= arr[ptr];
        if (x == 0)
        {
            ans ++;
            ptr++;
            x = arr[ptr];
        }
        else
        {
            ptr++;
        }
    }
    cout << ans << endl;
    return;
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
