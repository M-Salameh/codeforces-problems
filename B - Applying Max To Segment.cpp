#include <bits/stdc++.h>
#define int long long
#define mid (l+r)/2
#define lc 2*node
#define rc lc+1
#define endl '\n'

using namespace std;

int n,m;

int segt[301010];
int arr[301010];

void reset ()
{
    memset(segt , 0 , sizeof(segt));
    memset(arr , 0 , sizeof(arr));
}

 void max_op(int node , int l , int r , int st , int en , int val)
{
    if (st<l || en>r )
    {
        return;
    }
    if (l == st && r == en)
    {
        segt[node] = max(val,segt[node]);
        return;
    }
    if (st > mid )
    {
        max_op (rc , mid+1 , r , st , en , val);
        return;
    }
    if (en <= mid)
    {
        max_op (lc , l , mid , st, en , val);
        return;
    }
    if (st <= mid && en >= mid)
    {
        max_op (lc , l , mid , st ,mid, val);
        max_op (rc , mid+1 , r , mid+1 , en , val);
        return;
    }
}


int get(int node , int l , int r , int idx)
{
    if(l<0 || idx > r || idx < l ) return 0;
    if (l==r && l==idx) return segt[node];
    if (idx <= mid)
    {
        return max(segt[node],get(lc , l , mid , idx));
    }
    if (idx > mid )
    {
        return max(segt[node],get(rc , mid+1 , r , idx));
    }
}
 void read()
{
    cin >> n >> m ;
    reset();
    n = pow(2,ceil(log2(n)));
    while (m--)
    {
        int l , r , v ,x ;
        cin >> x ;
        if (x==1)
        {
            cin >> l >> r >> v ;
            l++;
            max_op(1,1,n,l,r,v);
        }
        if (x==2)
        {
            cin >> l ;
            l++;
            cout << get(1,1,n,l)<<endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    read();
    return 0;
}
