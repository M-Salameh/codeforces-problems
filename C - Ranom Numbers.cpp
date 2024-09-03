#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int dp[202020][6][2];
int val[5] = {1,10,100,1000,10000};
string s;
int tc;
int n;

void reset()
{
    for (int i=0 ; i<=n ; i++)
    {
        for (int j=0 ; j<6 ; j++)
        {
            dp[i][j][0]=dp[i][j][1] = -1;
        }
    }
}


int indx (char c)
{
    return (int)(c-'A');
}


int solve(int i , int biggest , bool changed)
{
    if (i < 0) return 0;
    if (dp[i][biggest][changed] != -1 ) return dp[i][biggest][changed];

    int& ans = dp[i][biggest][changed];

    if (changed)
    {
        int p1 = val[indx(s[i])];
        if (indx(s[i]) < biggest) p1*=-1;
        ans = solve(i-1 , max(indx(s[i]),biggest) , true ) + p1;
    }
    else
    {
        int p1 = val[indx(s[i])];
        if (indx(s[i]) < biggest) p1*=-1;
        ans = solve(i-1 , max(indx(s[i]) , biggest) , true)+ p1;
        for(int k=0 ; k<5 ; k++)
        {
            p1 = val[k];
            if(k < biggest) p1*=-1;
            ans = max ( ans , p1 +
                             solve (i-1 , max(biggest,k) , indx(s[i])!=k)
                       );
        }
    }
    return ans;
}



signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> tc;
    while (tc--)
    {
        cin >> s;
        n = s.size();
        reset();
        int ans = solve(n-1 , 0 , false);
        cout << ans << endl;
    }
    return 0;
}
