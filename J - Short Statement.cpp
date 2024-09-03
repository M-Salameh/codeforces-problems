///https://codeforces.com/gym/105190/problem/J
#include <bits/stdc++.h>
///#define int long long
#define endl '\n'
using namespace std;

const int inf = 1e8;
const int NN = 4e5+3;
int tc=1;
int n,k;
int arr[NN+5];
vector<int> divs[NN+5];
int last[NN+5];
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
    vector<long long> dp (n+1,0LL);
    
    for (int div : divs[arr[1]])
    {
        last[div] = 1;
    }

    for (int i=2 ; i<=n ; i++)
    {
        for (int div : divs[arr[i]])
        {
            if (i-last[div] <= k)
            {
                dp[i] = max(dp[i], dp[last[div]] + div);
            }
            last[div] = i;
        }
    }

    cout << dp[n] << endl;

}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    pre_calc();
    cin >> tc ;

    while (tc--)
    {
        cin >> n >> k;

        for (int i=1 ; i<=n ;i++) cin >> arr[i];
        for (int i=0 ; i <= NN  ; i++) last[i] = -NN;

        solve();
    }
    return 0;
}