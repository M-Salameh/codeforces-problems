#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int tc;
int n , m , q;

void bfs (vector<int> graph[] ,bool visited[],int parent[] , int src , int father)
{
    visited[src] = true;
    parent[src] = father;
    queue<int> nodes;
    nodes.push(src);
    while (nodes.size())
    {
        int child = nodes.front();
        nodes.pop();
        for (auto i : graph[child])
        {
            if (visited[i]) continue;
            visited[i] = true;
            parent[i] = father;
            nodes.push(i);
        }
    }
}


void solve(vector<int> graph[])
{
    int u , v;
    while(m--)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool visited[n+1] = {false};
    int father[n+1] = {0};
    for (int i=1 ; i<=n  ; i++)
    {
        if (!visited[i])
        {
            bfs(graph,visited,father,i,i);
        }
    }
    string ans="";
    int x,y;
    while(q--)
    {
        cin >> x >> y;
        if (father[x] == father[y])
        {
            ans+="1";
        }
        else ans+="0";
    }
    cout << ans << endl;
}


signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m >> q;
        vector<int> graph[n+2];
        solve(graph);
    }
    return 0;
}
