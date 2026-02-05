#include <bits/stdc++.h>
///#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define push_back pb
using namespace std;
/**
not solved !
*/
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


void read(set<int> graph[],set<int> sus[])
{
    while(m--)
    int x,y;
    {
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
        bool flag = true;

    }
    return;
}



signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        set<int> graph[n+2];
        set<int> sus[n+2];
        read (graph , sus);
        solve(graph , sus);
    }
    return 0;
}
