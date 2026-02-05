#include <bits/stdc++.h>
#include <math.h>
#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define ll unsigned long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin()+1,x.end()


using namespace std;

int tc=1;
const int inf = 1e16;
int n,k;
int m;

void solve2()
{
    cin >> n >> m;
    vector<int> arr(n+1,0),b(m+1,0);

    for (int i=1 ; i<=n ; i++) cin >> arr[i];
    for (int i=1 ; i<=m ; i++) cin >> b[i];

    sort(all(b));

    reverse(all(b));

    vector<int> ans ;

    int i=1 ; int j=1;

    while(i<=n and j<=m)
    {
        while(arr[i]>=b[j] and i<=n)
        {
            ans.push_back(arr[i]);
            i++;
        }
        ans.push_back(b[j]);
        j++;
    }
    if (i>=n)
    {
        while(j<=m)
        {
            ans.push_back(b[j++]);
        }
    }
    if (j>=m)
    {
        while(i<=n)
        {
            ans.push_back(arr[i++]);
        }
    }

    for (auto i : ans ) cout << i << ' ';
    cout << endl;

}

void solve()
{
     cin >> n >> m;
    vector<int> arr(n), b(m), c(n + m);
    for (auto& i : a) cin >> i;

    for (auto& i : b) cin >> i; 
    
    sort(all(b));
    reverse(all(b));
    merge(all(a), all(b), c.begin(), greater<int>());

    for (auto i : c) 
    {
        cout << i << ' ';
    }
    cout << endl;

}


signed main()
{
    fast;
    
    
    cin >> tc;

    while(tc--)
    {
        solve();
    }


    return 0;
}



