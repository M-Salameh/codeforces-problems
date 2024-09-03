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

vector<int> edges_to_cut;

map <pair<int,int>,int> edge_number;

vector<int> adj[200200];

bool can = true;

void addEdge(int a, int b ,int r)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
    edge_number[{a,b}] = r;
    edge_number[{b,a}] = r;
    return;
}

int dfs(int src , int father)
{
    if (!can) return -1;
    int ans = 1;
    for (auto i : adj[src])
    {
        if (i == father) continue;
        ans += dfs(i , src);
    }
    if (ans == 3)
    {
        if (father)
        {
            edges_to_cut.push_back(edge_number[{father,src}]);
        }
        return 0;
    }
    if (ans > 3)
    {
        can = false;
    }
    return ans;
}


void solve()
{
    dfs(1,0);
    if (!can)
    {
        cout << -1 << endl;
        return;
    }
    int x = edges_to_cut.size();
    cout << x << endl;
    for (auto i : edges_to_cut ) cout << i << ' ';
    cout << endl;
    return;
}



signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        can = true;
        for (int i=1 ; i<=n; i++)
        {
            adj[i].clear();
            edges_to_cut.clear();
            edge_number.clear();
        }

        for (int i=1 ; i<=n-1; i++)
        {
            int u,v;
            cin >> u >> v ;
            addEdge(u , v , i);
        }
        if (n%3)
        {
            cout << -1 << endl;
            continue;
        }
        solve();



    }
    return 0;
}
