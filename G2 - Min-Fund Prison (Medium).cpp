#include <bits/stdc++.h>
#define int long long
//#define endl '\n'

using namespace std;

const int inf = 2e18+8;
const int NN = 1e3+5;
int n , tc=1;
int m,c;
int ans;
vector<int> adj[NN];
int subtree_size[NN];
map<int,bool> vis;
map<pair<int,int> , bool> edge;


int ans33;
void dfs(int node=1 , int parent=0)
{
    if (vis[node]) return;
    vis[node] = true;
    subtree_size[node] = 1;
    for (int& child : adj[node])
    {
        if (not edge[{child,node}]) continue;
        if (child == parent) continue;
        if (vis[child]) continue;
        dfs(child , node);
        subtree_size[node] += subtree_size[child];
    }
    int temp = subtree_size[node]*subtree_size[node];
    temp += (n-subtree_size[node])*(n-subtree_size[node]);
    ans33 = min (ans33 , temp);
}

vector<pair<int,int>> bridges;

void IS_BRIDGE(int v,int to)
{
    bridges.push_back({v,to});
}

vector<int> tin, low;
int timer;

void dfs2(int node, int parent = 0)
{
    vis[node] = true;
    tin[node] = low[node] = ++timer;
    bool parent_skipped = false;
    for (int to : adj[node])
    {
        if (to == parent and !parent_skipped)
        {
            parent_skipped = true;
            continue;
        }
        if (vis[to])
        {
            low[node] = min(low[node], tin[to]);
        }
        else
        {
            dfs2(to, node);
            low[node] = min(low[node], low[to]);
            if (low[to] > tin[node])
            {
                IS_BRIDGE(node, to);
            }
        }
    }
}

void find_bridges()
{
    timer = 0;
    tin.assign(n+1, -1);
    low.assign(n+1, -1);
    vis.clear();
    for (int i = 1 ; i <= n; i++)
    {
        if (!vis[i]) dfs2(i);
    }
}


void solve_connected()
{
    if (m == n-1)
    {
        cout << ans33 << endl;
        return;
    }
    bridges.clear();
    find_bridges();

    int ans = inf;
    for(auto& [v , to] : bridges)
    {
        edge[{v,to}] = false;
        edge[{to,v}] = false;
        vis.clear();
        dfs(v);
        int x = subtree_size[v];
        vis.clear();
        dfs(to);
        int y = subtree_size[to];
        edge[{v,to}] = true;
        edge[{to,v}] = true;
        ans = min(ans , x*x + y*y);
    }

    if (ans == inf )
    {
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
}

void solve()
{
    vis.clear();
    int compo = 0;
    ans33 = inf;
    for (int i=1 ; i<=n ; i++)
    {
        if (! vis[i])
        {
            compo++;
            dfs(i);
        }
    }

    if (compo == 1)
    {
        solve_connected();
        return;
    }

    bridges.clear();
    find_bridges();

    int res = inf;
    for(auto& [v , to] : bridges)
    {
        edge[{v,to}] = false;
        edge[{to,v}] = false;

        vis.clear();

        vector<int> sizes = {0};

        for (int i=1 ; i<=n ; i++)
        {
            if (not vis[i])
            {
                dfs(i);
                sizes.push_back(subtree_size[i]);
            }
        }

        int sum = n;
        ans  = (compo - 1)*c;
        ///cout << "compo = " << compo << endl;
        vector<vector<int>> dp (sizes.size()+1 , vector<int>(sum , 0));
        for (int i=1 ; i<sizes.size() ; i++)
        {
            for (int j=0 ; j<=(1+sum)/2 ; j++)
            {
                dp[i][j] = dp[i-1][j];
                if (sizes[i] <= j)
                dp[i][j] = max (dp[i-1][j] , dp[i-1][j-sizes[i]] + sizes[i]);
            }
        }

        int x1 = dp[sizes.size()-1][(1+sum)/2];
        int y1 = sum - x1;
        ans += x1*x1 + y1*y1;
        res = min(res , ans);
        edge[{v,to}] = true;
        edge[{to,v}] = true;
    }
    vis.clear();




    vector<int> sizes = {0};

    for (int i=1 ; i<=n ; i++)
    {
        if (not vis[i])
        {
            dfs(i);
            sizes.push_back(subtree_size[i]);
        }
    }

    int sum = n;
    ans  = (compo - 1)*c;
    vector<vector<int>> dp (sizes.size()+1 , vector<int>(sum , 0));
    for (int i=1 ; i<sizes.size() ; i++)
    {
        for (int j=0 ; j<=(1+sum)/2 ; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (sizes[i] <= j)
            dp[i][j] = max (dp[i-1][j] , dp[i-1][j-sizes[i]] + sizes[i]);
        }
    }

    int x1 = dp[sizes.size()-1][(1+sum)/2];
    int y1 = sum - x1;
    ans += x1*x1 + y1*y1;
    res = min(res , ans);

    cout <<  res << endl;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        edge.clear();
        cin >> n >> m >> c;
        for (int i=0 ; i<=n ; i++)
        {
            adj[i].clear();
        }
        for (int i=1 ; i<=m ;i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edge[{u,v}] = true;
            edge[{v,u}] = true;
        }
        ans = inf;
        solve();
    }

    return 0;
}
