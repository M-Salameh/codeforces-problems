#include <bits/stdc++.h>
#include <math.h>
#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define ll unsigned long long
#define pi pair<int,int>
#define pll pair<ll,ll>

using namespace std;

int tc=1;
const int inf = 1e16;
int n;


map<pi,int> mp;
vector<int> pref;

void solve()
{
    pref = vector<int>(n+1,0);
    vector<string> s(n+1,"");
    mp.clear();

    for(int i=1 ; i<=n  ; i++)
    {
        cin >> s[i];
        int sum = 0;
        for(auto& j : s[i]) sum += (j-'0');
        pref[i] = sum;
      ///  cout << "sum = " << sum << endl;
        mp[{s[i].size() , sum}]++;
       /// cout << mp[{s[i].size() , sum}] << endl;
    }

    int ans = 0;
    for (int i=1 ; i<=n ; i++)
    {
        int sumx = 0;
        int sumy = 0;
        int y = 0;
        int x = 0;

        int sz = s[i].size();

        for (int j=0 ; j<sz ;j++)
        {
            x = j+1;
            y = 2*x - sz;
            sumx += s[i][j]-'0';
            sumy = 2*sumx - pref[i];

            int anspref = mp[{y , sumy}];
            int anssuf = mp[{-y , -sumy}];

            ans += anspref+anssuf;
        }
    }
    cout << ans << endl;
    return;
}


signed main()
{
    fast;

    ///cin >> tc;

    while(tc--)
    {
        cin >> n;
        solve();
    }


    return 0;
}











/**
struct segment
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
