#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define MOD 1000000007
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define all(x) x.begin()+1,x.end()
#define all0(x) x.begin(),x.end()
#define double long double
#pragma once
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
///#define int long long
#define endl '\n'


using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 1e9+7;
const int SQRTN = 750; ///sqrt for 5*10^5
int n,q;
const int NN = 5e5+3;
struct query
{
    int l , r ;
    int block_idx;
    int query_idx;
    query () {}
    query (int _l , int _r , int _q_idx)
    {
        l = _l;
        r = _r;
        query_idx = _q_idx;
        block_idx = l / SQRTN;
    }
    bool operator < (const query& q) const
    {
        if (block_idx != q.block_idx)
        {
            return block_idx < q.block_idx;
        }
        return r < q.r;
    }
};

int arr[NN];
query qu[NN];
int ans[NN];
int freq [NN];
int res;


void add(int idx)
{
    freq[arr[idx]]++;
    res += (freq[arr[idx]]==1) ;
}

void removee (int idx)
{
    freq[arr[idx]]--;
    res -= (freq[arr[idx]]==0);
}

void MO ()
{
    sort(qu , qu+q);
    int l=1 , r=0;
    for (int i=0 ; i<q ; i++)
    {
        while (l < qu[i].l ) removee(l++);
        while (l > qu[i].l ) add(--l);
        while (r < qu[i].r ) add(++r);
        while (r > qu[i].r ) removee(r--);
        ans[qu[i].query_idx] = res;
    }
}

void solve()
{
    MO ();

    for (int i=1 ; i<=q ; i++)
        cout << ans[i] << endl;

}

void compress ()
{
    vector<pair<int,int>> tes;
    for (int i=0 ; i<n ; i++)
    {
        tes.push_back({arr[i],i});
    }
    sort(all0(tes));
    map<int,int> mp;
    int nxt=0;
    for (auto& [val , idx] : tes)
    {
        int x = mp.count(val) ? mp[val] : mp[val] = ++nxt;
        arr[idx] = x;
    }
}

signed main()
{
    ///fast;
    ///cin >> tc;
    while(tc--)
    {
        scanf("%d", &n);
        scanf("%d", &q);
        map<int,int> mp;
        for (int i=0 ; i<n ; i++) scanf("%d", &arr[i]);
        compress();

        for (int i=1 ; i<=q ; i++)
        {
            int l , r;
            scanf("%d%d", &l , &r);
            qu[i-1] = query(--l , --r , i);
        }
        solve();

    }
    return 0;
}





///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);