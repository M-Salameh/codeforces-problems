#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int tc=1;
int n,k;
string bash = "Bashar";
string ham = "Hamada";
string isk = "Iskandar";

int mypow (int a , int b)
{
    if (b == 1) return a;
    if (b == 0) return 1;
    if (b&1) return b * mypow(a,b/2) *mypow(a,b/2);
    else return mypow(a,b/2) *mypow(a,b/2);
}

void solve()
{
    int arr[n+1];
    for (int i=1 ; i<=n ;i++) cin >> arr[i];
    vector<int> ans;
    int x=0;
    for (int i=1 ; i<=n ; i++)
    {
        x=0;
        while (arr[i]>0)
        {
            x += (arr[i]&1);
            arr[i]/=2;
        }
        ans.push_back(x);
    }
    
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return;
}

signed main()
{

    fast;
    cin >> tc;
    while (tc--)
    {
        cin >> n ;
        solve();
    }
    return 0;
}
