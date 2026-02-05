#include <bits/stdc++.h>
///#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define M 1000000007
using namespace std;

int tc=1;

int n;


int fill_dp (int arr[] , int dp[][1000] , int i=0 , int j=0)
{
    if (i>=n or j>=n)return 0;
    if (dp[i][j] != -1 ) return dp[i][j];
    int p1=-1 ,p2=-1;
    if (arr[i] < arr[j])
    {
        p1 = (1 + (fill_dp(arr , dp , j , j+1))%M)%M;
    }
    p2 = (fill_dp(arr,dp , i , j+1))%M;
    return dp[i][j]= (max(p1,p2))%M;
}

void solve()
{
    int arr[n];
    for (int i=0 ; i<n ; i++) cin >> arr[i];
    int dp[n];
    dp[0]=1;
    int cnt_way[n];
    cnt_way[0]=0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        cnt_way[i]=0;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] and dp[i]< dp[j]+1)
            {
               dp[i] = (dp[j] + 1);
            }
        }
        if(dp[i]==1) cnt_way[i]=1;
        for (int j=0 ; j<i ; j++)
        {
            if (arr[i]>arr[j] and dp[i]==dp[j]+1)
            {
                cnt_way[i]+=cnt_way[j];
                cnt_way[i]%=M;
            }
        }

    }
    int len = *max_element(dp , dp+n);
    int freq=0;
    for (int i=0 ; i<n ;i++)
    {
        if (dp[i] == len)
        {
            freq+=cnt_way[i];
            freq%=M;
        }
    }
    cout << len << " " << freq << endl;
    return;

}

signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> n ;
        solve();
    }
    return 0;
}
