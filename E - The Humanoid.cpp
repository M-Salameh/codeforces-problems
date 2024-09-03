/**
https://codeforces.com/problemset/problem/1759/E
*/

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int tc;
int n;
int h;
int green = 4;
int blue = 1;
int ans=0;


int solve(int i , int val , int g , int b , vector<vector<int>> &dp , vector<int> &v)
{
    if (i<n && g==0 && b==0 && val<v[i])return 0;
    if (i>=n || g<0 || b<0 )return 0;
    if (dp[i][g+b] != -1)
    {
        if (val <= dp[i][g+b])
        {
            return dp[i][g+b];
        }
        dp[i][g+b] = -1;
        return solve (i , val , g , b , dp , v);
    }
    if (val > v[i])
    {
        return dp[i][g+b] = 1 + solve(i+1 , val+v[i]/2 , g , b , dp , v);
    }
    int p1 = solve(i , 2*val , g-2 , b   , dp , v);
    int p2 = solve(i , 3*val , g   , b-1 , dp , v);
    return dp[i][g+b] = max(dp[i][g+b] , max(p1,p2));

}

void read()
{
    cin >> n >> h ;
    vector<int>v;
    int x;
    for(int i=0; i<n ; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin() , v.end());
    vector<vector<int>> dp(n,vector<int>(6,-1));
    ans = solve(0 , h , green , blue , dp , v);
    cout << ans <<endl;
}

signed main()
{
    fast_io;
    cin >> tc;
    while (tc--)
    {
        read();
        green = 4;
        blue = 1;
    }
    return 0;
}
