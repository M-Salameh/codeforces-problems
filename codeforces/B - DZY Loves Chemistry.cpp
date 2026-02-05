#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <ll> graph[100100];
vector <ll> parent;
vector <bool> visited (100100,false);
ll n , m;
ll x , y;
ll max_sz;
ll rr=0;
ll sz[100100];
ll ans = 1;

void dfs (ll src)
{
    if (!visited[src])
    {
        visited[src]=true;
       // cout << src << endl;
        for (auto i:graph[src])
        {
            if (!visited[i])
            {
                //cout << i <<endl;
                ans*=2;
                dfs(i);
            }

        }
    }
}

int main()
{
   cin >> n >> m ;
        for (ll i=1 ; i<= m ;i++)
        {
            cin >> x >> y ;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
         if (m<=1)
    {
        cout << m+1<<endl;
        return 0;
    }
    for (ll i=1 ; i<=n ; i++)
    {
        dfs(i);
    }
    cout << ans <<endl;
    return 0;
}
