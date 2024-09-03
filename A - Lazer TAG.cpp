#include <bits/stdc++.h>
#define int long long
#define double long double
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mid (l+r)/2
#define lc 2*node
#define rc 2*node+1
#define endl '\n'
using namespace std;

int tc;
int n;
int q;
struct snode
{
    int val=0;
    int No_OP=-1;
};


snode segt[800800];

void propagate(int node , int l , int r)
{
    if (segt[node].No_OP == -1) return;
    segt[node].val = segt[node].No_OP * (r-l+1);
    if (l<r)
    {
        segt[rc].No_OP = segt[node].No_OP;
        segt[lc].No_OP = segt[node].No_OP;
    }
    segt[node].No_OP = -1;
}

int beam (int node , int l , int r , int st , int en)
{
    propagate(node , l , r);
    if (st>en || st>r || en<l) return 0;
    if (st<= l && r<=en) return segt[node].val;
    return beam(lc , l , mid , st , en) + beam (rc , mid+1 , r , st , en);
}

void update(int node , int l , int r , int st , int en , int val)
{
    propagate(node,l,r);
    if (en<l || st>r || st>en) return;
    if (st<=l && r<=en)
    {
        segt[node].No_OP = val;
        propagate(node,l,r);
        return;
    }
    update(lc , l , mid ,  st , en , val);
    update(rc , mid+1 , r , st , en , val);
    segt[node].val = segt[lc].val+segt[rc].val;
    return;
}

void print()
{
    for (int i=1 ; i<4*n+3 ; i++)
        cout << segt[i].val<<','<<segt[i].No_OP<< endl;
}

void solve()
{
    vector<pair<int,pair<int,int>>> walls;
    int st,en,y;
    for (int i=1 ;i<=q;i++)
    {
        cin >> st >> en >> y ;
        walls.push_back({y,{st,en}});
    }
    update(1,1,n,1,n,1);
    sort(walls.begin() , walls.end());
    for (int i=0 ; i<q ; i++)
    {
        st = walls[i].second.first;
        en = walls[i].second.second;
        if (beam(1,1,n,st,en)>0)
        {
            if (st == en) continue;
            update(1,1,n,st+1,en-1,0);
            update(1,1,n,st,st,1);
            update(1,1,n,en,en,1);
        }
        ///cout<<endl; print();
    }

    cout << segt[1].val <<endl;
}


void reset()
{
    snode stand;
    stand.No_OP = -1;
    stand.val = 0;
    for (int i=1 ; i<=4*n+3; i++)
    {
        segt[i] = stand;
    }
}

signed main()
{
    fast;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> q ;
        reset();
        solve();
    }
    return 0;
}
