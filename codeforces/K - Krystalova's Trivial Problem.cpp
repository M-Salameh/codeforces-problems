#include <bits/stdc++.h>
#define int long long
#define double long double
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mid (l+r)/2
#define lc 2*node
#define rc 2*node+1
#define endl '\n'
#define MOD 1000000007

using namespace std;

int tc = 1;
int n;
int q;
struct snode
{
    int sum = 0;
    int square = 0;
    int pushX = 0;
};

snode segt[500500];
int arr[100100];

snode merg(snode& a , snode& b)
{
    snode ans;
    ans.pushX = 0;
    ans.square=((a.square%MOD+b.square%MOD)%MOD+MOD)%MOD;
    ans.sum=(((a.sum%MOD)+(b.sum%MOD))%MOD+MOD)%MOD;
    return ans;
}

void build (int node = 1 , int l = 1 , int r = n)
{
    if (l>r or r>n) return;
    if (l == r)
    {
        segt[node].pushX = 0;
        segt[node].square=(((arr[r]%MOD)*(arr[r]%MOD))%MOD+MOD)%MOD;
        segt[node].sum = (arr[r]%MOD);
        return;
    }
    build (lc , l , mid);
    build (rc , mid+1 , r);
    segt[node] = merg(segt[lc] , segt[rc]);
    return;
}

void propagate(int node , int l , int r)
{
    if (segt[node].pushX == 0) return;
    int temp = segt[node].pushX;
    segt[node].square%=MOD;
    temp%=MOD;
    segt[node].square=((segt[node].square+(((temp*temp)%MOD)*(r-l+1))%MOD)%MOD+MOD)%MOD;
    segt[node].sum%=MOD;
    segt[node].square=((segt[node].square+(((temp*2)%MOD)*segt[node].sum)%MOD)%MOD+MOD)%MOD;
    segt[node].sum=((segt[node].sum+(temp*(r-l+1))%MOD)%MOD+MOD)%MOD;

    if (l<r)
    {
        segt[lc].pushX += (segt[node].pushX);
        segt[rc].pushX += (segt[node].pushX);
    }

    segt[node].pushX = 0;
}




int get_square (int node , int l , int r , int st , int en)
{
    propagate(node , l , r);
    if (st>en or st>r or en<l) return 0;
    if (st<=l && r<=en)
    {
        return (segt[node].square)%MOD;
    }
    int p1 = get_square(lc , l , mid , st , en) ;
    int p2 =  get_square (rc , mid+1 , r , st , en);
    p1 = ((p1)%MOD+MOD)%MOD;
    p2 = ((p2)%MOD+MOD)%MOD;
    return ((p1+p2)%MOD+MOD)%MOD;
}

void update(int node , int l , int r , int st , int en , int val)
{
    propagate(node,l,r);
    if (en<l or st>r or st>en) return;
    if (st<=l and r<=en)
    {
        segt[node].pushX += val;
        propagate(node,l,r);
        return;
    }
    update(lc , l , mid ,  st , en , val);
    update(rc , mid+1 , r , st , en , val);
    segt[node] = merg(segt[lc],segt[rc]);
    return;
}


signed main()
{
    fast;
    //cin >> tc;
    while (tc--)
    {
        cin >> n >> q ;
        for (int i=1 ; i<=n ;i++) cin >> arr[i] ;
        int n1=1 ;
        while(n1 < n) n1*=2;
        n = n1;
        build();
        while(q--)
        {
            char a;
            int l,r,x;
            cin >> a ;
            if (a == 'u')
            {
                cin >> l >> r >> x ;
                update(1,1,n,l,r,x);
            }
            else
            {
                cin >> l >> r;
                cout << get_square(1,1,n,l,r) << endl;
            }
        }
    }

    return 0;
}