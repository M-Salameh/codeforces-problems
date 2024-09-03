#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int tc=1;
int n;
const int NN = 1e6+5;

int cnt[NN];

void solve(vector<int>& arr)
{
    int ans=0;
    for (int i=1 ; i<=n ; i++)
    {
        if (cnt[arr[i]] > 2)
        {
            ans+=((cnt[arr[i]]-1)*(cnt[arr[i]]-2));
        }
        for (int b=2 ; arr[i]*b*b <= NN ; b++)
        {
            ans +=(cnt[b*arr[i]] * cnt[b*b*arr[i]]);
        }
    }
    cout << ans << endl;
}

signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> n ;
        vector<int> arr(n+1);
        for (int i=1 ;i<=n ; i++)
        {
            cin >> arr[i];
            cnt[arr[i]]++;
        }
        solve(arr);
        for (int i=1 ; i<=n ; i++)
        {
            cnt[arr[i]]=0;
        }
    }

    return 0;
}
