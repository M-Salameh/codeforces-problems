#include <bits/stdc++.h>
#include <math.h>
#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2

using namespace std;

int tc=1;
const int inf = 1e16;
int n;

vector<bool> take;
vector<int> freq;
vector<int> dp;
int mex;


void read()
{
    freq = vector<int> (n+1 , 0);
    dp = vector<int> (n+1 , inf);
    mex = 0;

    for (int i=1 ,x ; i<=n ; i++)
    {
        cin >> x;
        if (x<n) freq[x]++;
    }

    for(int i=0 ; i<=n ; i++)
    {
        if (freq[i] == 0)
        {
            mex = i;
            ///cout << "Mex = " << mex << endl;
            return;
        }
    }
}


void solve()
{
    read();
    dp[0] = 0;

    for (int i = 0 ; i<=mex ; i++)
    {
        for (int j=0 ; j<i ; j++)
        {
            int temp = i*freq[j]-i+j;
            dp[i] = min(dp[i] , dp[j] + temp);
        }
    }

    cout << dp[mex] << endl;
    return;

}


signed main()
{
    fast;

    cin >> tc;

    while(tc--)
    {
        cin >> n;

        solve();
    }

    return 0;
}











/*
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
