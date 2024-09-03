#include<bits/stdc++.h>
#define endl '\n'
#define MOD 10000007
#define int long long
using namespace std;

int tc=1;
int n,m;
string s1,s2;

int get_TotalString(vector<vector<int>>& ShortestTotalString)
{
    for (int i=0 ; i<=n ; i++)
    {
        ShortestTotalString[i][0] = i;
    }
    for (int i=0 ; i<=m ; i++)
    {
        ShortestTotalString[0][i] = i;
    }
    for (int i=1 ;i<=n;i++)
    {
       for (int j=1 ; j<=m; j++)
       {
           if (s1[i-1]==s2[j-1])
           {
               ShortestTotalString[i][j] = 1 + ShortestTotalString[i-1][j-1];
           }
           else
           {
               ShortestTotalString[i][j] = 1 + min(ShortestTotalString[i-1][j] , ShortestTotalString[i][j-1]);
           }
       }
    }

    return ShortestTotalString[n][m];

}


int find_unique(vector<vector<int>>& uniq,vector<vector<int>>& ShortestTotalString)
{
    for (int i=0 ;i<=n;i++)
    {
        uniq[i][0] = 1;
    }
    for (int i=0 ;i<=m;i++)
    {
        uniq[0][i] = 1;
    }
    for (int i=1 ;i<=n;i++)
    {
       for (int j=1 ; j<=m; j++)
       {
           if (s1[i-1]==s2[j-1])
           {
               uniq[i][j] = uniq[i-1][j-1];
           }
           else if (ShortestTotalString[i-1][j]==ShortestTotalString[i][j-1])
           {
               uniq[i][j] =(uniq[i-1][j] + uniq[i][j-1]);
           }
           else if (ShortestTotalString[i-1][j]!=ShortestTotalString[i][j-1])
           {
               uniq[i][j] = min (uniq[i-1][j] , uniq[i][j-1]);
           }
       }
    }
    return uniq[n][m];
}


void solve(int Case)
{
    vector<vector<int>> ShortestTotalString (n+1,vector<int>(m+1,0));

    int x = get_TotalString(ShortestTotalString);

    vector<vector<int>> uniq (n+1,vector<int>(m+1,0));

    int y = find_unique(uniq , ShortestTotalString);

    cout << "Case "<< Case <<": " << x << ' ' << y << endl;


}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    int k=1;
    while(tc--)
    {
        s1="";
        s2="";
        cin >> s1;
        cin >> s2;
        n = s1.size();
        m = s2.size();
        solve(k);
        k++;
    }
    return 0;
}
