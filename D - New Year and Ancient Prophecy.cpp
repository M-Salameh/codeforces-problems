#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define all(x) x.begin()+1,x.end()
#define all0(x) x.begin(),x.end()
#define double long double
#pragma once
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
///#define int long long
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

int tc = 1;
///const int inf = 1e15+7;
const int mod = 1e9+7;
int n;
string s;

int dp[5005][5005];
int pref_dp[5005][5005];
int lcp[5005][5005];

int add(int& a , int& b)
{
    while (b >= mod) b-=mod;
    while (a >= mod) a-=mod;

    int z = a+b;

    while(z >= mod ) z-=mod;

    z += mod*(z<0);
    return z;
}


bool check(int& x,int& y)
{
	if(lcp[x][y] >= y-x) return false;

	return s[x+lcp[x][y]]<s[y+lcp[x][y]];
}

void solve()
{
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=1 ; j<=i ; j++)
        {
            if (s[j] == '0')
            {
                dp[j][i] = 0;
                pref_dp[j][i] = pref_dp[j-1][i];
                continue;
            }

            int le = max(2*j-i, 1);

            int x = (pref_dp[j-1][j-1] - pref_dp[le-1][j-1]);

            dp[j][i] = add(dp[j][i] , x);

            le--;

            if (le>=0 and check(le,j))
            {
                dp[j][i] = add (dp[j][i],dp[le][j-1]);
            }

            pref_dp[j][i] = add (dp[j][i] , pref_dp[j-1][i]);        }
    }

    cout << pref_dp[n][n] << endl;
}

void LCP()
{
    for(int i=n;i>=1;i--)
        for(int j=n;j>=1;j--) if(s[i]==s[j]) lcp[i][j]=lcp[i+1][j+1]+1;
}

signed main()
{
    fast;
    ///cin >> tc;
    while(tc--)
    {
        cin >> n;
        cin >> s;
        s = "0"+s;
        for (int i=1 ; i <= n ; i++) dp[1][i] =1;
        LCP();
        solve();
    }

    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
