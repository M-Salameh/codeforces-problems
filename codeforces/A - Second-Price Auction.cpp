#include <bits/stdc++.h>
#include <math.h>
#include <string>
#define int long long
#define double long double
#define mid (l+r)/2
#define lc 2*node
#define rc lc+1
#define endl '\n'
#define fast  ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int tc=1;
int n;

void solve()
{
    int mx=-1,smx=0,ind=0;
    int arr[n];
    for (int i = 0 ;i<n ; i++)
    {
        cin >>arr[i];
        if(arr[i]>mx)
        {
            mx = arr[i];
            ind = i+1;
        }
    }
    for (int i=0 ;i<n ; i++)
    {
        if(arr[i]>smx && arr[i] < mx)
        {
            smx = arr[i];
        }
    }
        cout<<ind<<' '<<smx<<endl;
    return;
}

signed main()
{
    fast;
    ///cin >> tc ;
    while (tc--)
    {
        cin >> n;
        solve();
    }

}
