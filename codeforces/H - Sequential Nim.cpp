#include <bits/stdc++.h>
#define endl '\n'
#define mid (l+r)/2
#define lc 2*node
#define rc lc+1
using namespace std;

struct Node
{
    int pos;
    bool all_ones=false;
};

const int inf = 1e6+9;

int arr[100100];

Node segt[400400];

Node combine(Node n1 , Node n2)
{
    Node d;
    d.all_ones = n1.all_ones&n2.all_ones;
    if (d.all_ones)
    {
        d.pos = max (n1.pos , n2.pos);
    }
    else
    {
        if (n1.all_ones)
        {
            d.pos = n2.pos;
        }
        else if (n2.all_ones)
        {
            d.pos = n1.pos;
        }
        else
        {
            d.pos = min (n1.pos , n2.pos);
        }
    }
    return d;
}

int n,q;

void build(int node , int l , int r)
{
    if (l > r) return;
    if (l == r)
    {
        segt[node].pos = r;
        segt[node].all_ones = (arr[r]==1);
        return;
    }
    build (lc , l , mid);
    build (rc , mid+1 , r);
    segt[node] = combine(segt[lc] , segt[rc]);
    return;
}

void update (int node , int l , int r , int idx , int val)
{
    if (l>r) return;
    if (l==r)
    {
        segt[node].pos = idx;
        segt[node].all_ones = (val==1);
        return;
    }
    if (idx <= mid) update(lc , l ,mid , idx , val);
    if (idx > mid) update(rc , mid+1 , r , idx , val);
    segt[node] = combine(segt[lc] , segt[rc]);
    return;
}

Node query (int node , int l , int r , int st , int en)
{
    if (l>r || en < st) return {0,1};
    if (st <= l && r <= en)
    {
        return segt[node];
    }
    Node ln = query(lc , l , mid , st , min(mid,en));
    Node rn = query(rc , mid+1 , r , max(mid+1,st) , en);
    return combine(ln , rn);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i=1 ; i<=n ; i++) cin >> arr[i];
    build(1,1,n);
    int x,l,r;
    while (q--)
    {
        cin >> x >> l >> r;
        if (x==1)
        {
            update(1,1,n,l,r);
        }
        else
        {
            int y = query(1,1,n,l,r).pos;
            int ones = y-l;
            if (ones&1)
            {
                cout << "Second" << endl;
            }
            else cout << "First" <<endl;

        }
    }
    return 0;
}

