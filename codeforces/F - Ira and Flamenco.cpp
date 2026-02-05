#include <bits/stdc++.h>
#include <math.h>
#include <string>
#define endl '\n'
#define double long double
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536
#define ll long long
#define int long long

using namespace std;

const int NN = 200200;
const int MOD = 1000000007;

int tc=1;

int n,m;
vector<int>arr;
map<int,int> freq;
vector<int> diff;


int power(int a ,int b)
{
   if (b==0) return 1;
   if (b==1) return a;
   int res = power(a,b/2)%MOD;
   res = res*res;
   res %= MOD;
   if (b&1) res = (res * a) %MOD;
   return res%MOD;
}


void reset()
{
    freq.clear();
    diff.clear();
    arr.clear();
}

void read()
{
    cin >> n  >> m;
    arr.push_back(0);
    for (int i=1 ; i<=n  ; i++)
    {
        int x;
        cin >> x;
        if (freq[x] == 0)
        {
            arr.push_back(x);
        }
        freq[x]++;
    }
    sort(arr.begin() , arr.end());

    diff.push_back(0);
    for(int i=1 ; i<arr.size() ; i++)
    {
        diff.push_back(arr[i]-arr[1]);
    }
}


void solve()
{
    int ans = 0;
    int multy = 1;
    int xxx = arr.size();
    for (int i=1 ; i < min(m,xxx) ; i++)
    {
        multy*=freq[arr[i]];
        multy %= MOD;
        if (multy >= MOD) multy-=MOD;
    }

    for (int i=m ; i<xxx ;i++)
    {
        multy *= (freq[arr[i]]);
        multy %= MOD;
        if (multy >= MOD) multy-=MOD;

        if (diff[i]-diff[i-m+1] < m)
        {
            ans = (ans + multy) % MOD;
            if (ans >= MOD) ans-=MOD;
        }
        multy = (multy * power(freq[arr[i-m+1]],MOD-2))%MOD;
        if (multy >= MOD) multy-=MOD;
    }

    cout << ans << endl;
}


signed main()
{
    fast;
    cin >> tc;
    while (tc--)
    {
        read();
        solve();
        reset();
    }
    return 0;
}




