#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int tc=1;
int n;

void solve()
{
    int arr[n+2];
    map<int,int> hits;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
        hits[arr[i]]=0;
        hits[arr[i]+1]=0;
    }

    int ans=0;
    for (int i=1 ; i<=n ;i++)
    {
        if(hits[arr[i]+1] > 0)
        {
            hits[arr[i]+1]--;
            hits[arr[i]]++;
        }
        else
        {
            hits[arr[i]]++;
            ans++;
        }
    }
    cout << ans <<endl;
}

signed main()
{

    fast;
   // cin >> tc;
    while (tc--)
    {
        cin >> n;
        solve();
    }
    return 0;
}
