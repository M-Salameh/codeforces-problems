#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#define lc node*2
#define rc lc+1
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
///#define int int_fast64_t
//#define pii pair<int,int>

using namespace std;
using namespace __gnu_pbds;

//const int_fast64_t inf = 2e18+1;
const int inf = 2e8+1;
const int NN = 2e5+2;
//const int mod = 1e9+7;
const int mod = 998244353;
int tc=1;
int n , q;
int segt[NN * 4] , arr[NN];

int merg(int&b , int& c)
{
    return min (b , c);
}

void build(int node = 1  , int l = 1 , int r = n)
{
    if (r < l)return;
    if (l == r)
    {
        segt[node] = arr[r];
        return;
    }
    build(lc , l , mid);
    build(rc , mid+1 , r);
    segt[node] = merg(segt[lc] , segt[rc]);
}

void update(int node , int l , int r , int idx , int val)
{
    if (idx<l or idx>r) return;
    if (l == r)
    {
        segt[node] = val;
        arr[idx] = val;
        return;
    }
    if (idx <= mid) update(lc , l , mid , idx , val);
    else update(rc , mid+1 , r , idx , val);
    segt[node] = merg(segt[lc] , segt[rc]);
}

int get(int node , int l , int r , int st , int en)
{
    if (st>en or l>r or st>r or en<l) return inf;
    if (st<=l and en>=r) return segt[node];
    int x1 = get(lc , l , mid , st , en);
    int x2 = get(rc , mid+1, r , st , en);
    return merg(x1 , x2);
}

void update(int idx , int val)
{
    update(1 , 1, n , idx , val);
}

int get(int st , int en)
{
    //cout << "getting" << endl;
    int l = 0 ;
    int r = en-st;
    while (l <= r)
    {
        int temp = get(1 , 1 , n , st, st+mid);
        if (temp >= mid) l = mid+1;
        else r = mid-1;
    }
    return (get(1,1,n,st,st+r) == r) and (r>=0 and r<=en-st);
}
 

void solve()
{
    build();
    int op , idx , l , r , x;
    while (q--)
    {
        //cout << "op" << endl;
        cin >> op;
        if (op == 1)
        {
            //cout << "updating" << endl;
            cin >> idx >> x ;
            update(idx , x);
        }
        else
        {
            cin >> l >> r;
            cout << get(l , r) << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///freopen("test_input.txt" , "r" , stdin);
    ///freopen("test_output.txt" , "w" , stdout);
    auto time_start = clock();
    cin >> tc;
    while (tc--)
    {
        cin >> n >> q;
        // for (int i=1 ; i<=n ; i++) arr[i] = inf;
        // build();
        for (int i=1 ; i<=n ; i++) cin >> arr[i];
        solve();
    }
    
    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
