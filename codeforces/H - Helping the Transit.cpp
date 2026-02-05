#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int>adj[100005];
vector<int>rev_adj[100005];
int parent[100005];
int rev_parent[100005];
bool rev_visited[100005];
bool visited[100005];
bool parent_src[100005];
bool rev_parent_src[100005];
int srcs , rev_srcs;
int isol,rev_isol;

bool isolated (int v)
{
    return (adj[v].size()==0) ;
}

bool rev_isolated (int v)
{
    return (rev_adj[v].size()==0) ;
}

void dfs (int src , int root)
{
    if (visited[src]) return;
    visited[src] = true;
    if (isolated(src))
    {
        isol++;
        return;
    }
    for (auto v : adj[src])
    {
        if (v==parent[src]) continue;
        dfs(v,root);
    }
}

void rev_dfs (int src , int root)
{
    if (rev_visited[src]) return;
    rev_visited[src] = true;
    if(rev_isolated(src))
    {
        rev_isol++;
        return;
    }
    for (auto v : rev_adj[src])
    {
        if (v==rev_parent[src]) continue;
        rev_dfs(v,root);
    }
}


int get_parent(int v)
{
    if(parent_src[v] or parent[v]==0)return v;
    parent_src[v] = true;
    return parent[v] = get_parent(parent[v]);
}

int rev_get_parent(int v)
{
    if(rev_parent_src[v] or rev_parent[v]==0)return v;
    rev_parent_src[v] = true;
    return rev_parent[v] = rev_get_parent(rev_parent[v]);
}


int n,m;

void Read()
{
    for (int i=1 ; i<=m ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        parent[v]=u;
        rev_adj[v].push_back(u);
        rev_parent[u]=v;
    }
}

int ans (int a, int b , int c , int d)
{
    return max(max(a,b),max(c,d));
}


void solve()
{
    for (int i=1 ; i<=n ; i++)
    {
        if (!visited[i])
        {
            srcs++;
            int root = get_parent(i);
            dfs(root,root);
        }
        if (!rev_visited[i])
        {
            rev_srcs++;
            int root = rev_get_parent(i);
            rev_dfs(root,root);
        }
    }
   ///cout << isol <<" , " << rev_isol <<" , " << srcs <<" , " << rev_srcs <<endl;
   if (isol)
   {
       cout << ans(isol , rev_isol , srcs , rev_srcs) <<endl;
   }
   else cout << 0 << endl;

}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m ;
    Read();
    solve();
    return 0;
}


/**
9 7
1 2
2 3
3 1
6 1
6 4
4 5
7 6
**/
