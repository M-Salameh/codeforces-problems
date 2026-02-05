#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
using namespace std;

int tc;
int n;
vector<int> adj[200200];
bool visited[200200];
int parent[200200];
map <pair<int,int>,int> pos;
map <pair<int,int>,int> dep;

void bfs(int src=1)
{
    queue<int> q;
    q.push(src);
    while(q.size())
    {
        int node = q.front();
        q.pop();
        for (int i : adj[node])
        {
            if (visited[i]) continue;
            visited[i] = true;
            parent[i] = node;
            q.push(i);
            if (node == 1)
            {
                dep[{node,i}] = 1;
            }
            else
            {
                dep[{node,i}] = dep[{parent[node],node}];
                if (pos[{node,i}] < pos[{parent[node],node}])
                {
                    dep[{node,i}]++;
                }
            }
        }
    }
    return;
}


void solve()
{
    for (int i=1 ; i<=n-1 ; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        pos[{x,y}]=i;
        pos[{y,x}]=i;
    }

    parent[1]=1;

    bfs();

    int ans = 0;

    for (auto i : dep)
    {
        ans = max (ans , i.second);
    }
    cout << ans << endl;

}

void reset()
{
    for (int i=0 ;i<=n ; i++)
    {
        adj[i].clear();
        visited[i] = false;
        parent[i]=0;
    }
    pos.clear();
    dep.clear();
}



signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> tc;
    while(tc--)
    {
        cin >> n;
        reset();
        solve();


    }

    return 0;
}
