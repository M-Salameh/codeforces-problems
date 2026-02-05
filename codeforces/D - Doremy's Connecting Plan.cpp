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
const int inf = 1e11;
int n;
int c;

bool good(string& a)
{
    if (a.size()&1) return false;
    for(int i=0 ; i<a.size()/2 ; i++)
    {
        if (a[i]==a[a.size()-1-i]) return false;
    }
    return true;
}


void solve()
{
    vector<int> arr(n+1 , 0);
   /// vector<int> v(n+1 , 0);
    set<pair<int,int>> ms;

    int sum = 0;

    for (int i=1 ; i <=n ; i++)
    {
        cin >> arr[i];
        if(i>1) ms.insert({i*c - arr[i] , i});
    }
    sum = arr[1];
    while(ms.size())
    {
        int x = (*ms.begin()).first;
        int pos = (*ms.begin()).second;
        if (sum < x)
        {
            cout << "No" << endl;
            return;
        }
        sum += arr[pos];
        ms.erase(ms.begin());
    }
    cout << "Yes" <<endl;
    return;
}


signed main()
{
    fast;

    cin >> tc;

    while(tc--)
    {
        cin >> n >> c;

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
