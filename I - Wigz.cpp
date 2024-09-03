///https://codeforces.com/gym/104147/problem/I
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#include <math.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define pi pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin()+1,x.end()
#define all0(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define ll unsigned long long
#define int long long
#define double long double
#define endl '\n'
#pragma once
using namespace std;
using namespace __gnu_pbds;

int tc = 1;
int n , m , k;


int arr[505][505];
int b[505][505];
int SumCols[505];
int SumRows[505];

void sum_rows()
{
    for (int i=1 ; i<=n ; i++)
    {
        SumRows[i] = 0;
        for (int j=1 ; j<=m ; j++)
        {
            SumRows[i] += arr[i][j];
        }
    }
}


void sum_cols()
{
    for (int j=1 ; j<=m ; j++)
    {
        SumCols[j] = 0;
        for (int i=1 ; i<=n ; i++)
        {
            SumCols[j] += arr[i][j];
        }
    }
}


int inclusion_execlusion()
{
    int limit = (1LL << m);
    int ans = 0;
    for (int lim=0 ; lim < limit ; lim++)
    {
        vector<int> cols;
        for (int j=0 ; j<m ; j++)
        {
            if (lim & (1LL<<(j))) cols.push_back(j+1);

            if (cols.size() == k) break;
        }

        vector<int> v;
        for (int i=1 ; i<=n  ; i++)
        {
            int sum = SumRows[i];
            for (auto col : cols)
            {
                sum -= arr[i][col];
            }
            v.push_back(sum);
        }
        sort(all0(v));
        int tot = 0;
        for(auto col : cols) tot += SumCols[col];

        int num = k  - cols.size();
        for (int idx = v.size()-num ; idx < v.size() ; idx++)
        {
            tot += v[idx];
        }
        ans = max(ans , tot);
    }
    return ans;
}

void solve()
{
    if (n < m)
    {
        for (int i=1 ; i<=n ; i++) for (int j=1 ; j<=m ; j++) arr[j][i] = b[i][j];
        swap(n,m);
    }

    sum_rows();
    sum_cols();

    int ans = 0;
    ans = inclusion_execlusion();
    cout << ans << endl;
}

signed main()
{
    freopen("wigz.in", "r", stdin);
    ///freopen("library.out", "w", stdout);
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m >> k;
        for (int i=1 ; i<=n ; i++)
        {
            for (int j=1 ; j<=m ; j++)
            {
                cin >> b[i][j];
                arr[i][j] = b[i][j];
            }
        }
        solve();
    }
    return 0;
}
