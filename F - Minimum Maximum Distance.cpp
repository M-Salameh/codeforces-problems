#include <bits/stdc++.h>
#include <math.h>
///#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
using namespace std;

int tc=1;
const int inf = 1e8;
int n;
vector<int> adj[200100];
vector<int> dist;
vector<bool> marked;
vector<bool> visited;
int _first;
int k;

void reset()
{
    for (int i=1 ; i<=n ; i++)
    {
        adj[i].clear();
    }
    marked = vector<bool> (n+1, false);
    visited = vector<bool> (n+1, false);
    dist = vector<int> (n+1 , 0);
    _first = 0;
    return;
}

void read()
{
    for (int i=1 ; i<=k ; i++)
    {
        int x;
        cin >> x;
        marked[x] = true;
        if(_first) continue;
        _first = x;
    }

    for (int i=1 ; i<n ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return;
}
/**
1
5 3
1 2 5
1 2
1 3
2 4
3 5

///2

*/
pair<int,int> bfs(int node)
{
    queue<int> q;
    q.push(node);
    dist[node] = 0;
    pair<int,int> ans = {node,0};
    visited[node] = true;
    while (q.size())
    {
        int parent = q.front();
        q.pop();
        for (auto child : adj[parent])
        {
            if (visited[child]) continue;
            visited[child] = true;
            q.push(child);
            dist[child] = dist[parent]+1;
            if (marked[child])
            {
                if(ans.second >= dist[child]) continue;
                ans.first = child;
                ans.second = dist[child];
            }
        }
    }
    return ans;
}

void solve()
{
    if (k==1)
    {
        cout << 0 << endl;
        return;
    }

    pair<int,int> ans1 = bfs(_first);

    dist = vector<int>(n+1,0);
    visited = vector<bool>(n+1,false);

    ///cout << ans1.first <<" , " << ans1.second << endl;

    pair<int,int> ans2 = bfs(ans1.first);

    int ans = (ans2.second+1)/2;

    cout << ans << endl;

    return;

}

signed main()
{
    fast

    cin >> tc;

    while(tc--)
    {
        cin >> n >> k;
        reset();
        read();
        solve();
    }

    return 0;
}
