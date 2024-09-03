#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#include <math.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define pi pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin()+1,x.end()
#define all0(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define ll unsigned long long
#define int long long
#define double long double
#pragma once

#define endl '\n'
using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 5e10+6;
int n , m;

vector<pair<int,int>> adj[500500];
vector<int> parent;
vector<int> parent2;
vector<int> dist;
vector<int> dist2;


void Dijkstra(vector<int>& my_dist , vector<int>& my_parent ,int src )
{
    my_dist = vector<int> (n+1 , inf);
    my_parent = vector<int> (n+1 , 0);
    my_dist[src] = 0;

    priority_queue<pair<int,int>> dijkstra;

    dijkstra.push ({-my_dist[src] , src}) ;

    while (dijkstra.size())
    {
        int cost = -dijkstra.top().first;
        int node = dijkstra.top().second;
        dijkstra.pop();

        for (auto e : adj[node])
        {
            int v = e.first;
            int w = e.second;

            int new_dist = my_dist[node] + w;
            if (my_dist[v] > new_dist)
            {
                my_dist[v] = new_dist;
                my_parent[v] = node;
                ///nxt[node] = v;
                dijkstra.push({-new_dist , v});
            }

        }
    }
}

void getPath(vector<int>& path)
{
    int u = n ;
    while (u > 1)
    {
        path.push_back(u) ;
        u = parent[u];
    }
    path.push_back(1) ;
    reverse (path.begin() , path.end()) ;
}

void solve()
{
    Dijkstra(dist , parent , 1);
    Dijkstra(dist2 , parent2 , n);

    vector<int> p1;

    getPath(p1);

    map<pair<int,int> , bool> vis;

    int temp = inf;

    for (int i=1 ; i<p1.size() ; i++)
    {
        vis[{p1[i],p1[i-1]}] = true;
        vis[{p1[i-1],p1[i]}] = true;
    }


    for (int src=1 ; src<=n ; src++)
    {

        for (auto& [dest , cost] : adj[src])
        {
            if (vis[{src,dest}]) continue;
            temp = min (temp , dist[src] + cost +dist2[dest]);
            vis[{src,dest}] = true;
            vis[{dest,src}] = true;
        }
    }
    temp += dist[n];

    temp = temp >= inf ? -1 : temp;
    cout << temp << endl;
}

signed main()
{
    fast;
    ///cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        for(int i=0 ; i<=n  ; i++) adj[i].clear();
        parent = vector<int> (n+1 , 0);
        for (int i = 1 ; i <= m ; i ++)
        {
            int u,v,w;
            cin >> u >> v >> w ;
            adj[u].push_back ({v , w}) ;
            adj[v].push_back ({u , w}) ;
        }

        solve();
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
