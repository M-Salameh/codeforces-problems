#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n;

void solve()
{
    vector<int> arr(n+1 , 0);
    int sum = 0;
    int part_sum=0;
    for (int i=1; i<=n ; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int ans=0;
    for(int i=1 ; i<n ; i++)
    {
        part_sum+=arr[i];
        if(sum-part_sum==part_sum)
        ans++;
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n ;
    solve();
    return 0;
}
