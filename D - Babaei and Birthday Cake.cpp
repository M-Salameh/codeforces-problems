#include <bits/stdc++.h>
#define int long long
#define double long double
#define M_PI 3.14159265358979323846
#define mid (l+r)/2
#define lc 2*node
#define rc 2*node+1
#define endl '\n'

using namespace std;

const int inf = 2e18+7;
int tc = 1;
const int NN = 1e5+6;
int n;

pair<int , int> volume[NN];

int segt[5*NN+5];

int dp[NN];

void update(int node , int l, int r, int idx, int val)
{
    if(l>idx or r<idx) return;
    if(l == r)
    {
        segt[node] = val;
        return;
    }
    update (lc , l , mid, idx, val);
    update (rc , mid+1 ,r , idx, val);
    segt[node] = max(segt[lc], segt[rc]);
    return;
}

int query (int node , int l , int r , int st , int en)
{
    if (st>en or st>r or en<l) return 0;
    if (st<=l and r<=en) return segt[node];

    return max (query(lc , l ,mid , st , en) , query(rc , mid+1 , r, st , en));
}
void solve()
{
    sort(volume+1 , volume+n+1);

    int temp = -inf;
    for (int i=1 ; i<=n ; i++)
    {
        int idx = - volume[i].second;
        if (dp[idx]) continue;

        dp[idx] = volume[i].first + query(1,1,n,1,idx);

        update(1,1,n,idx , dp[idx]);

        temp = max (temp , dp[idx]);
    }

    double ans = M_PI * temp;
    cout << ans << endl;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ///cin >> tc;
    while(tc--)
    {
        cin >> n ;
        for (int i=1 ; i<=n ; i++)
        {
            int r,h;
            cin >> r >> h;
            volume[i].first = r*r*h;
            volume[i].second = -i;
        }
        cout << fixed << setprecision(7);
        solve();
    }
    return 0;
}
