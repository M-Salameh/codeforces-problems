#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define myfor(i,a,b) for(int i=a;i<=b;i++)
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

vector<vector<int>> arr (205 , vector<int>(205,0));

int n;
int ans;
const int inf = 1e15+3;
signed main()
{
    fast_io;
    int ignore=1e16;
    cin >> n;
    myfor(i,1,n)
    myfor(j,1,n)
    {
        cin >> arr[i][j] ;
        ans+=arr[i][j];
        if (i+j==n+1)
        {
            ignore = min (ignore , arr[i][j]);
        }
    }
    cout << ans-ignore << endl;
    return 0;
}
