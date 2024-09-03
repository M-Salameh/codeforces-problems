#include <bits/stdc++.h>
#include <math.h>
#include <string>
#define endl '\n'
#define double long double
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536
#define ll long long
///#define int long long

using namespace std;

int tc=1;

int n;

int arr[2050];
int pos[2050];


void read()
{
    cin >> n ;
    for (int i=1 ; i<=n  ; i++)
    {
        cin >> arr[i];
        pos[arr[i]]=i;
    }
}


void solve()
{
    vector<int> ans;
    if (n==1)
    {
         cout << 1 << endl;
         return;
    }

    if (pos[n]==1) pos[n]=pos[n-1];

    if (true)
    {
        for (int i = pos[n] ; i<=n ; i++ ) ans.push_back(arr[i]);
        int r = pos[n] - 1;
        r += (pos[n]==n);
        int l = r;
        while (l>1 and arr[l-1]>arr[1])
        {
            l--;
        }

        for (int i = pos[n]-1 ; i>=l; i--)ans.push_back(arr[i]);
        for (int i=1 ; i<l ; i++) ans.push_back(arr[i]);

        for (auto i : ans ) cout << i << ' ';
        cout << endl;
        return;
    }
}


void reset()
{
    for (int i=1 ;i<=n ; i++)
    {
        arr[i]=0;
        pos[i]=0;
    }
}




signed main()
{
    fast;
    cin >> tc;
    while (tc--)
    {
        read();
        solve();
        reset();
    }
    return 0;
}
