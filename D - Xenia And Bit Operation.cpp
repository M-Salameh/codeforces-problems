#include <bits/stdc++.h>
#define endl '\n'
#define mid (l+r)/2
#define lc 2*node
#define rc lc+1
//#define int long long

using namespace std;

int n,q;
int segt[8008000];
int arr[2002000];

void build (int node, int l , int r, bool oper)
{
    if (l==r)
    {
        segt[node]=arr[r];
        return;
    }
    build (lc , l , mid , !oper );
    build (rc , mid+1 , r , !oper );
    if (oper)
    {
        segt[node] = (segt[lc] | segt[rc]);
        return;
    }
    segt[node] = (segt[lc]^segt[rc]);
    return;
}
void update (int node , int l , int r , int idx , int val , bool oper)
{
    if (idx<l or idx>r) return ;
    if (l==r)
    {
        segt[node] = val;
        return;
    }
    update ( lc , l , mid , idx , val , !oper);
    update ( rc , mid+1 , r , idx , val , !oper);
    if (oper)
    {
        segt[node] = (segt[lc] | segt[rc]);
        return;
    }
    segt[node] = (segt[lc] ^ segt[rc]);
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int val , idx , d;
    cin >> n >> q;
    bool flag = n&1;
    d = pow (2,n);

    n = d;
    for (int i = 1; i<=n ; i++)
    {
        cin >> arr[i];
    }

    build(1,1,n,flag);

    while (q--)
    {
       cin >> idx >> val;
       update (1 , 1 , n , idx , val , flag);
       cout << segt[1] << endl;
    }
    return 0;
}
