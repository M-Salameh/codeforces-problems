#include <bits/stdc++.h>
#include <math.h>
///#define int long long
#define endl '\n'
#include <string>

using namespace std;

int tc=1;
const int inf = 1e8;
int n;
int a;
int b;
vector<int> adj[200100];
vector<bool> visited;
vector<int> dist;

int valer=-1;
int portal;


void dfs(int node , int src)
{
    if(visited[node])
    {
        if(valer == -1)
        {
            valer = dist[node];
            portal = node;
        }
        return;
    }

    visited[node] = true;
    dist[node] = 1 + dist[src];

    for(auto v : adj[node])
    {
        if (v == src) continue;
        dfs(v , node);
    }
    return;
}


int bfs(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    dist[node] = 0;
    if (node == portal)
    {
        return dist[node];
    }
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for(auto v : adj[x])
		{
			if (visited[v]) continue;
			q.push(v);
			dist[v] = dist[x]+1;
			visited[v] = true;
			if (v == portal)
            {
                return dist[v];
            }
		}
	}
}

void solve()
{
    dist[0]=-1;
    dfs(b , 0);

////    cout << "Valer = " << valer <<endl;
////    cout << "Portal = " << portal <<endl;

    visited = vector<bool>(n+1,false);
    dist = vector<int>(n+1 , 0);

    int marc = bfs(a);

    if (marc > valer)
    {
        cout << "YES" << endl;
    }
    else cout << "NO" <<endl;
    return;
}

void read()
{
    cin >> n;
    cin >> a >> b;

    visited.resize(n+1);
    dist.resize(n+1);

    for (int i=1 ; i<=n ; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        visited[i] = false;
        dist[i] = 0;
    }

    return;
}

void reset()
{
    for (int i=1 ; i<=n ; i++)
    {
        adj[i].clear();
    }
    visited.clear();
    dist.clear();
    valer = -1;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> tc;

    while(tc--)
    {
        read();

        solve();

        reset();
    }

    return 0;
}
