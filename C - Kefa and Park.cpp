#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <ll> graph[100100];
vector <ll> parent;
vector <bool> visited (100100,false);
ll w[900900];
ll n , m;
ll x , y;
ll max_sz;
ll rr=0;
ll sz[100100];
ll ans;


void dfs (ll src , ll waz)
{
    if (waz > m )return;
    if (!visited[src])
    {
        /*cout << src <<endl;
        for (auto i:graph[src])cout <<i<<"   ";
        cout << endl;*/
            //cout<<src<<endl;
        if (graph[src].size()==1 && visited[graph[src][0]])
        {
            ans++;
            return;
        }
        visited[src]=true;
        for (auto i:graph[src])
        {
            if (!visited[i])
            {
                dfs(i, waz*w[i]+w[i]);
            }
        }
    }
}


void read()
{
    cin >> n >> m;
    for (ll i=1;i<=n ; i++)
    {
        cin >> w[i];
    }
    for (ll i=1 ; i<n ; i++)
    {
        cin >> x >> y ;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

int main()
{
    read();
    dfs(1 , w[1]);
    cout << ans <<endl;
    return 0;
}
