#include <bits/stdc++.h>
#include <string>
#define endl '\n'
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define ll long long
//#define double long double

using namespace std;

int tc=1;

int n , k ,m;


int power(int a , int b)
{
    if (b==0) return 1;
    if (b==1) return a;
    int res = power(a,b/2) % MOD;
    res = (res*res) % MOD;
    if (b&1) res = (a*res)%MOD;
    return res%MOD;
}

int power3(int a , int b)
{
    if (b==0) return 1;
    if (b==1) return a;
    int res = power(a,b/2);
    res = (res*res);
    if (b&1) res = (a*res);
    return res;
}

int get_minutes(string s)
{
    int x = 0;
    x = (s[0]-'0')*10;
    x += (s[1] - '0');
    x *= 60;

}


void solve()
{
    cin >> n >> k >> m;
    int pref[m+1] = {0};
    for (int i=1 ; i<=m  ; i++)
    {

    }
}



signed main()
{
    fast;
    cin >> tc;
    while (tc--)
    {
        //solve();
        ll n,m;
        cin>>n>>m;
        if(abs(n+m)%2==0){
          if(n!=m)  cout<<2<<" "<<(n+m)/2<<" "<<(n-m)/2<<endl;
          else if(n != 0) cout<<1<<" "<<n<<endl;
          else cout << 0 << endl;
        }
        else cout<<-1<<endl;
    }
    return 0;

}
