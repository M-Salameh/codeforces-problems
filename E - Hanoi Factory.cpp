#include <bits/stdc++.h>
#define int long long
#define mid (l+r)/2
#define lc 2*node
#define rc 2*node+1

using namespace std;
const int NN = 1e5 + 6;
const int inf = 2e18;
int tc = 1;
int n;
int arr[NN] , brr[NN] , h[NN];
int dp[NN];
int segt[8*NN];

void build (int node=1 , int l=1 , int r=n)
{
    if (l==r)
    {
        segt[node] = 0;
        return;
    }
    build(lc , l , mid);
    build(rc , mid+1 , r);
    segt[node] = 0;
}

void update(int node , int l , int r , int idx, int val)
{
    if (l>idx or r<idx) return;
    if (l==r)
    {
        segt[node] = val;
        return;
    }
    update(lc , l , mid , idx , val);
    update(rc , mid+1 , r , idx , val);
    segt[node] = max (segt[lc] , segt[rc]);
    return;
}

int get(int node , int l , int r , int st , int en , bool pr = false)
{
    if (st>en or st>r or en<l) return 0;

    if (st<=l and r<=en) return segt[node];

    int p1 = get(lc , l , mid , st , en);
    int p2 = get(rc , mid+1 , r , st , en);

    return max (p1 , p2);
}

void solve()
{
    vector<pair<int,pair<int,int>>> v;
    for (int i=1 ; i<=n ; i++)
    {
        v.push_back({brr[i] , {arr[i] , h[i]}});
    }
    sort(v.rbegin() , v.rend());
    int m = n;
    n = 2*n+1;
    build();

    for (int i = 0 ; i<m ; i++)
    {
        int b = v[i].first;
        int a = v[i].second.first;
        int h = v[i].second.second;

        ///cout << "a = " << a << " , b = " << b << " , h = " << h << endl;

        int y = get(1,1,n,1,b-1);
        dp[i+1] = h + y;

        int x = get (1,1,n,a,a);

        if (x <= dp[i+1])
        {
            update (1,1,n,a,dp[i+1]);
        }
    }

    int ans = 0;
    for (int i=1 ; i<=m ; i++)
    {
        ans = max (ans , dp[i]);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //cin>>tc
    while(tc--)
    {
        cin >> n ;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i] >> brr[i] >> h[i];
            dp[i] = dp[i-1] = 0;
        }

        map<int,int> dc;
        int cnt = 0;
        for (int i=1 ; i<=n ; i++)
        {
            dc[brr[i]];
            dc[arr[i]];
        }
        for (auto& [valu , id] : dc)
        {
            dc[valu] = ++cnt;
        }
        for (int i=1 ; i<=n ; i++)
        {
            arr[i] = dc[arr[i]];
            brr[i] = dc[brr[i]];
        }
        solve();
    }
    return 0;
}
