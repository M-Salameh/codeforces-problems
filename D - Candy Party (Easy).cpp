#include <bits/stdc++.h>
#include <math.h>
#define int unsigned long long
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
int sum;

unordered_map<int,pair<int,int>> pows;

unordered_map<int,int> freqs;

vector<int> arr;

void set_sols()
{
    for (int i=0 ; i<=31 ; i++)
    {
        int x = (1 << i);
        for (int j=0 ; j<=31 ; j++)
        {
            int y = (1 << j);
            pows[x-y] = {x,y};
        }
    }
}

void solve()
{
    if (sum%n)
    {
        cout << "No" <<endl;
        return;
    }
    int s = sum/n;
    for (int i=1 ; i<=n ; i++)
    {
        int x = arr[i] - s;
        if (pows.find(x) == pows.end())
        {
            cout << "No" <<endl;
            return;
        }
        pair<int,int> sol = pows[x];
        freqs[sol.first]++;
        freqs[sol.second]--;
    }

    for (auto pr : freqs)
    {
        if(pr.second != 0)
        {
            cout << "No" <<endl;
            return;
        }
    }
    cout << "Yes" <<endl;
    return;
}


signed main()
{
    fast;

    set_sols();

    cin >> tc;

    /*cout << pows[0].first << " " << pows[0].second <<endl;

    cout << pows[1].first << " " << pows[1].second <<endl;*/
    while(tc--)
    {
        cin >> n;
        freqs.clear();
        arr = vector<int>(n+1,0);
        sum = 0;
        for (int i=1 ; i<=n ;i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
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
