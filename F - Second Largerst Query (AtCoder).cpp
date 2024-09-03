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
#define endl '\n'
#define ll unsigned long long
#define int long long
#define double long double
#pragma once

using namespace std;
using namespace __gnu_pbds;


int tc=1;
const int inf = 5e18;
int n ,q;


struct vertex
{
    pair<int,int> maxi; /// <value , freq>

    pair<int,int> sec_maxi;  /// <value , freq>
};

vector<int> arr;

vertex segt[8008008];

vertex merger(vertex a , vertex b)
{
    vertex ans;
    vector<pi> temp;
    temp.pb(a.maxi);
    temp.pb(a.sec_maxi);
    temp.pb(b.maxi);
    temp.pb(b.sec_maxi);
    sort(all0(temp));
    int cnt = 0;
    reverse(all0(temp));
    ans.maxi = temp[0];
    int pos = 0;
    for (int i=1 ; i<4 ; i++)
    {
        if (ans.maxi.first == temp[i].first)
        {
            ans.maxi.second += temp[i].second;
            pos = i;
        }
    }
    if (pos == 3) ans.sec_maxi = ans.maxi;
    else
    {
        ans.sec_maxi = temp[pos+1];
        for (int i= pos+2 ; i<4 ; i++)
        {
            if (ans.sec_maxi.first == temp[i].first)
            {
                ans.sec_maxi.second += temp[i].second;
            }
        }
    }
    return ans;

}


void build(int node=1 , int l=1 , int r=n)
{
    if (l>r) return;
    if (l==r)
    {
        segt[node].maxi = {arr[r],1};
        segt[node].sec_maxi = {-inf , 0};
        return;
    }
    build(lc , l , mid);
    build(rc , mid+1 , r);
    segt[node] = merger(segt[lc] , segt[rc]);
    return;
}


void update(int node , int l , int r , int val , int idx)
{
    if (l>r or idx>r or idx<l) return;
    if (l==r)
    {
        arr[idx] = val;
        segt[node].maxi = {arr[r],1};
        segt[node].sec_maxi = {-inf , 0};
        return;
    }
    update(lc , l , mid , val , idx);
    update(rc , mid+1 , r , val , idx);
    segt[node] = merger(segt[lc] , segt[rc]);
    return;
}

vertex query(int node , int l ,int r , int st , int en)
{
    if (st>en or st>r or en<l or r>n) return {make_pair(-inf,0),make_pair(-inf,0)};
    if (st<= l and r<=en) return segt[node];
    vertex a = query(lc , l , mid , st , en);
    vertex b = query (rc , mid+1 , r , st , en);
    vertex c = merger(a,b);
    return c;
}


void solve()
{

   build();

    while(q--)
    {
        int op , a , b;
        cin >>  op >> a >> b;
        if (op == 1)
        {
            update(1,1,n,b,a);
        }
        else
        {
            vertex ans = query(1,1,n,a,b);
            ///cout <<  ans.sec_maxi.first << ' ' ;
            cout <<ans.sec_maxi.second << endl;
        }
    }

}

void test_merger()
{
    vertex a,b;
    pair<int,int> x = {2,3};
    pair<int,int> y = x;
    a.maxi = x;
    a.sec_maxi = y;
    x = {5, 10};
    y = {4,1};
    b.maxi = x;
    b.sec_maxi = y;
    vertex ans = merger(a , b);
    x = ans.maxi;
    y = ans.sec_maxi;
    cout << x.first << ' ' << x.second << endl;
    cout << y.first << ' ' << y.second << endl;
}

signed main()
{
    fast;

   /// cin >> tc;


    while(tc--)
    {
        cin >> n >> q;
        arr = vector<int>(n+1,0);
        for (int i=1 ; i<=n ; i++) cin >>  arr[i];
        solve();
    }

    return 0;
}



/**
int gcd(int x , int y)
{
    return __gcd(x,y);
}
void solve()
{
    arr = vector<int> (n+1 ,0);
    for (int i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
    }

    sort(all(arr));

    int ans = 0;

    for (int i=1 ; i<=n ; i++)
    {
        for (int j=i+1 ; j<=n ; j++)
        {
            ans += (gcd(arr[i],arr[j]))*(n-j);
        }
    }
    cout << ans << endl;
}
**/




/**
int bs(int i)
{
    int l = i;
    int r = n;
    int ans = 0;
    int tim = tasks;

    while (l<=r)
    {
        if (pref[mid]-pref[i-1]<tim)
        {
            ans = mid-i+1;
            l = mid+1;
        }
        else if (pref[mid]-pref[i-1] > tim)
        {
            r=mid-1;
        }
        else
        {
            return mid-i+1;
        }
    }
    return ans;
}
*/

/**
struct MaximumSumSegment
{
struct vertex
{
    int seg , pref , suf , sum;
};


vertex merg (vertex h,vertex g)
{
    vertex ans;
    ans.seg = max (h.seg , max(g.seg , h.suf+g.pref));
    ans.pref = max (h.pref , h.sum+g.pref);
    ans.suf = max (g.suf , g.sum+h.suf);
    ans.sum = h.sum + g.sum;
    return ans;
}


vector<int> arr;
vector<vertex> segt;



void reset (vertex& h , int x)
{
    h.seg=h.pref=h.suf=h.sum=x;
}

void build(int node=1 , int l=1 , int r = n)
{
    if (l==r)
    {
        reset(segt[node] , arr[r]);
        return;
    }

    build (2*node , l , mid);
    build (2*node+1 , mid+1 , r);
    segt[node]=merg(segt[2*node] , segt[2*node+1]);
}

void update(int node , int l , int r , int val , int idx)
{
    if (l>r or idx>r or idx<l) return;
    if (l==r)
    {
        arr[idx] = val;
        reset(segt[node] , arr[r]);
        return;
    }
    update(lc , l , mid , val , idx);
    update(rc , mid+1 , r , val , idx);
    segt[node] = merg(segt[lc] , segt[rc]);
    return;
}

void read()
{
    segt = vector<vertex> (4*n+1 , {0,0,0,0});
    arr = vector<int> (n+1 , 0);
    for(int i=1 ; i<=n ; i++) cin >> arr[i];

}

void print()
{
    int x = max (max(segt[1].seg,segt[1].pref) , max (segt[1].suf,segt[1].sum));
    cout << (x>0? x : 0) <<endl;
}
signed main()
{
    fast;

    ///cin >> tc;

    while(tc--)
    {
        cin >> n >> q;
        read();
        build();
        print();
        while(q--)
        {
            int idx , val;
            cin >> idx >> val;
            idx++;
            update(1,1,n,val,idx);
            print();
        }
    }
    return 0;
}


};
*/


/**
struct MAXimumsegment
{
    int arr[2002002];

vector<int> locs[2002002];

vector<pair<int,int>> quest;

int segt[8008008];

int merger(int a , int b)
{
    return max(a,b);
}

void build(int node=1 , int l=1 , int r=n)
{
    if (l>r) return;
    if (l==r)
    {
        segt[node] = arr[r];
        return;
    }
    build(lc , l , mid);
    build(rc , mid+1 , r);
    segt[node] = merger(segt[lc] , segt[rc]);
    return;
}


int query(int node , int l ,int r , int st , int en)
{
    if (st>en or st>r or en<l or r>n) return -1e15-1;
    if (st<= l and r<=en) return segt[node];
    int a = query(lc , l , mid , st , en);
    int b = query (rc , mid+1 , r , st , en);
    return merger(a,b);
}

};
*/

/**
bool prime[2002002] = {true};

int MaxPrimeDiv[2002002];

void sieve()
{
    memset(prime , true , sizeof(prime));
    for (int i=2 ; i < 2e6+5 ; i++)
    {
        if(prime[i])
        {
            MaxPrimeDiv[i] = i;
            for (int j=i+i ; j<2e6+5 ; j+=i)
            {
                prime[j] = false;
                MaxPrimeDiv[j] = i;
            }
        }
    }
    return;
}
*/






/**
struct LazyAdd
{
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
    }
    return 0;
}
};



*/
