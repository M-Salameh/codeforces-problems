#include <bits/stdc++.h>
#include <string>
#define endl '\n'
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
///#define int long long
#define ll long long
//#define double long double

using namespace std;

int tc=1;

int n;


int power(int a , int b)
{
    if (b==0) return 1;
    if (b==1) return a;
    int res = power(a,b/2) % MOD;
    res = (res*res) % MOD;
    if (b&1) res = (a*res)%MOD;
    return res%MOD;
}

int power3(int a , int b)
{
    if (b==0) return 1;
    if (b==1) return a;
    int res = power(a,b/2);
    res = (res*res);
    if (b&1) res = (a*res);
    return res;
}


vector<int> adj[200200];
int color[200200];
int children[200200];
int parent[200200];
bool taken[200200];

int dfs(int src , int father)
{
    parent[src] = father;
    int ans = 1;

    for (auto i : adj[src])
    {
        if (i == father) continue;
        ans += dfs(i , src);
    }

    children[src] = ans;
    return ans;
}

void dfs2(int src , vector<int>& v)
{
    taken[src] = true;
    v.push_back(color[src]);

    for (auto i : adj[src])
    {
        if (i == parent[src] ) continue;

        dfs2(i , v);
    }
    return;
}

void solve()
{
    if (n&1)
    {
        cout << -1 << endl;
        return;
    }
    dfs(1,-1);

    int  root1=0 , root2=0;

    bool casn = true;
    for (int i=1 ; i<=n ; i++)
    {
        if (children[i] == n/2)
        {
            root1 = i;
            root2 = parent[i];
            casn = false;
        }
    }

    if (casn)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> A;
    vector<int> B;

    dfs2(root1 , A);

    for (int i=1 ; i<=n ; i++)
    {
        if (!taken[i])
        {
            B.push_back(color[i]);
        }
    }

    vector<int> freqA (n+1 , 0);
    vector<int> freqB (n+1 , 0);

    for (auto i : A)
    {
        freqA[i]++;
    }


    for (auto i : B)
    {
        freqB[i]++;
    }

    for (int i=1 ;i<=n ; i++)
    {
        int x = freqA[i] + freqB[i];
        if (x&1)
        {
            cout << -1 << endl;
            return;
        }
    }

    long long ans = 0;

    for (int i=1 ; i<=n  ; i++)
    {
        ans += abs (freqA[i] - freqB[i]);
    }

    cout << ans/4 << endl;

}



signed main()
{
    fast;
    cin >> tc;
    while (tc--)
    {
        cin >> n ;
        for (int i=1 ; i<=n ;i++)
        {
            cin >> color[i];
        }
        for (int i=1 ;i<n ; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        solve();

        for (int i=1 ;i<=n ;i++)
        {
            adj[i].clear();
            parent[i] = -1;
            children[i] = 0;
            taken[i] = false;
        }
    }
    return 0;

}
