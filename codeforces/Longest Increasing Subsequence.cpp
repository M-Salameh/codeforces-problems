#include <bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

vector <long int> v;
vector <vector <long int> > dp (10000 , vector<long int>(10000 , -1));

long int n;
long int lis (int i, long int comp)
{
    if (i>=n )return 0;
    if (v[i]<comp)return 0;
    if (dp[i][comp] != -1 ) return dp[i][comp];
    long int p1 = 1 + lis (i+1 , v[i]);
    long int p2 = lis (i+1 , v[i+1]);
    return dp[i][comp] = max (p1,p2);
}

int main()
{
    //
    cin >> n ;
    long int x;
    for (int i=0 ;i<n ; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    long int ans = lis(0,v[0]);
    cout << ans <<endl;
    return 0;
}


/**
8
10 9 2 5 3 7 101 18
*/
