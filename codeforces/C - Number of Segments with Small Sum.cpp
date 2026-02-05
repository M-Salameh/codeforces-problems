#include <bits/stdc++.h>
#define endl '\n'
#define mid (l+r)/2
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define int long long
using namespace std;

int n,s;



void solve(vector<int>& arr)
{
    int sum=0,l=1;
    int ans=0;
    int pref[n+1] ={0};

    for (int r=1; r<=n ; r++)
    {
        pref[r]=arr[r]+pref[r-1];
    }

    for (int i=1 ;i<=n ; i++)
    {
        int l=1;
        int r=i;

    }
    cout << ans <<endl;
    return;
}


signed main()
{
    fast;
    cin >> n >> s;
    vector<int> arr(n+1,0);
    for (int i=1  ;i<=n ; i++)
    {
        cin >> arr[i];
    }
    solve(arr);
    return 0;
}
