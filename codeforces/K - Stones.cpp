#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n,k;
int arr[100005];

vector<int> dp(100006,-1);

bool wins(int rest)
{
    if (dp[rest] != -1) return dp[rest]>0;

    for (int i=1 ;i<=n ; i++)
    {
        if (rest-arr[i]>=0)
        {
            bool x = wins(rest-arr[i]);
            if (!x)
            {
                return dp[rest] = true;
            }
        }
    }
    return dp[rest]=false;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
    }
    bool first = wins(k);
    if (first) cout << "First" <<endl;
    else cout << "Second" <<endl;

    for(int i=0 ; i<=k ; i++)
    {
        bool cur = true;
        for (int j=1; j<=n ; j++)
        {
            if (i-arr[j]<0)continue;
            cur &= dp[i-arr[j]];
        }
        dp[i] = !cur;

    }
    return 0;
}
