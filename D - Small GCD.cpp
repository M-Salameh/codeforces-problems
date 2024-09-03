#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int inf = 2e18+5;
const int NN = 1e5;
int tc=1;
int n;
int arr[NN+2];
vector<int> divs[NN+2];
vector<int> cnt, dp;

void pre_calc()
{
    for (int i=1 ; i<=NN ; i++)
    {
        for (int j=i ; j<=NN ; j+=i)
        {
            divs[j].push_back(i);
        }
    }
}

void solve()
{
    sort(arr+1 , arr + n + 1);
    cnt = dp = vector<int>(NN+1 , 0);
    for (int i=1 ; i<=n ; i++)
    {
        for (int& div : divs[arr[i]])
        {
            //cout << dp[div] << endl; 
            dp[div] += (n-i)*(cnt[div]++);
            //cout << dp[div] << endl;
        }
    }

    int ans = 0;
    for (int i=NN ; i>0 ; i--)
    {
        for (int j=i+i ; j<=NN ; j+=i)
        {
            dp[i] -= dp[j];
        }
        ans += i*dp[i];
    }

    
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    pre_calc();
    cin >> tc ;

    while (tc--)
    {
        cin >> n;

        for (int i=1 ; i<=n ;i++) cin >> arr[i];

        solve();
    }
    return 0;
}