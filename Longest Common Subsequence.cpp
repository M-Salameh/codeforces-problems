#include <bits/stdc++.h>
using namespace std;

string A,B;
int m,n;



void dp_(vector<vector<int>>& dp)
{
    for (int i=1 ;i<=n ; i++)
    {
        for (int j=1 ; j<=m ; j++)
        {
            if (A[i]==B[j])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max (dp[i][j-1],dp[i-1][j]);
            }
        }
    }
}


void read()
{
    cin >> A;
    cin >> B;
    n = A.size();
    m = B.size();
    B = "?" + B;
    A = "?" + A;
    if (m < n)
    {
        swap(n,m);
        swap(A,B);
    }
}


string LCS(vector<vector<int>>& dp)
{
    string ans;
    int i = n, j = m;
    while (i > 0 and j > 0)
    {
        if (A[i] == B[j])
        {
            ans += A[i];
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])i--;
        else j--;
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    read();
    vector<vector<int>> dp (n+2 , vector<int>(m+2,0));
    dp_(dp);
    string ans = LCS (dp);
    cout << ans << endl;
	return 0;
}
