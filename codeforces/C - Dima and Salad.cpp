#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n,k;
vector<int> a(102);
vector<int> b(102);
vector<vector<int>> dp(102,vector<int>(99999 , -1));
int zah = 999;
int inf = INT_MAX;
map <pair<int,int>,int> dp2;
map<pair<int,int>,bool> pre_cal;
int solve(int i , int balance_need)
{
    if (dp[i][balance_need] != -1 ) return dp[i][balance_need];
    if (i > n)
    {
        if (balance_need == zah*n)
        {
            return dp[i][balance_need] = 0;
        }
        else
        {
            return dp[i][balance_need] = -inf;
        }
    }
    int diff = a[i] - k*b[i] + zah;
    int p1 = a[i] + solve(i+1,diff+balance_need);
    int p2 = solve(i+1,balance_need+zah);
    return dp[i][balance_need] = max (p1,p2);

}

int solve2(int i , int balance)
{
    pair<int,int> p = make_pair(i,balance);
    if (pre_cal[p])
    {
        return dp2[p];
    }
    if (i > n)
    {
        if (balance == 0)
        {
            pre_cal[p]=true;
            return dp2[p]=0;
        }
        else
        {
            pre_cal[p]=true;
            return dp2[p]=-inf;
        }
    }
    int p1 = a[i] + solve2(i+1 , a[i]-k*b[i]+balance);
    int p2 = solve2(i+1,balance);
    dp2[p] = max(p1,p2);
    pre_cal[p]=true;
    return dp2[p];
}

void read()
{
    cin >> n >> k ;
    for (int i=1 ;i<=n ; i++)
    {
        cin >> a[i];
    }

    for (int i=1 ;i<=n ; i++)
    {
        cin >> b[i];
    }
    int ans = solve2(1,0);
    if(ans <= 0) ans = -1;
    cout << ans << endl;
    return;
}

signed main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    read();
    return 0;
}

