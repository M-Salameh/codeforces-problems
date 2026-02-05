#include <bits/stdc++.h>
#include <math.h>
///#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
using namespace std;

int tc=1;
///const int inf = 1e8;
int n;

long long pw(long long a,long long b)
{
    if(b==0)return 1;
    long long res=pw(a,b/2)%MOD;
    res=(res*res)%MOD;
    if(b&1)res=(res*a)%MOD;
    return res%MOD;
}

unordered_map<int,int> mp;

void process(int x)
{
    for(int i=2 ; i*i <= x ; i++)
    {
        while(x%i==0)
        {
            mp[i]++;
            x/=i;
        }

    }
    if (x>1) mp[x]++;
}

void solve()
{
    mp.clear();
    cin >> n;
    for (int i=1 ; i<=n ; i++)
    {
        int x;
        cin >> x;
        process(x);
    }

    for (auto i : mp)
    {
        if(i.second % n)
        {
            cout << "NO" <<endl;
            return;
        }
        ///cout << i.first << " : " << i.second << endl;
    }
    cout << "YES" <<endl;
    return;
}

signed main()
{
    fast

    cin >> tc;

    while(tc--)
    {
        solve();
    }

    return 0;
}
