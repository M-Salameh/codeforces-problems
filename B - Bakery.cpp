#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll siz = 1e6+9;
ll maxx = 1e11+9;
ll ans=1e11+9;
ll n ,m , k;
ll x,y;
bool forbid [siz];
bool in_g[siz];
ll w;
vector < pair <ll, ll> > graph[siz];

pair <ll ,ll> p;

void read()
{
    memset(forbid , false , sizeof(forbid));
    memset(in_g , false , sizeof(in_g));
    cin >> n >> m >> k;
    for (ll i=1 ; i<=m ; i++)
    {
        cin >> x >> y >> w;
        p={w,y};
        graph[x].push_back(p);
        p={w,x};
        graph[y].push_back(p);
        in_g[x]=in_g[y]=true;
    }
    if (k>0)
    {
        for (ll i=1; i<=k ; i++)
        {
            cin >> x;
            forbid[x]=true;
        }
    }
}
void print()
{
    /* for (ll i=1 ;i<=n ; i++)
        {
            cout << i << "  -- >  ";
            for (auto j:graph[i])
                cout << "w = " << j.first << "  ,  " << "node = " << j.second << endl;
            cout << "\n\n\n\n";
        }*/
}

int main()
{
    read();
  for (int h=1 ; h<=n; h++)
    {
       if(forbid[h])
        {
            for(auto child:graph[h])
            {
                if(!forbid[child.second]){
                ans=min(ans,child.first);
            }
         }
       }
    }
    if (ans == maxx)cout << -1 <<endl;
    else cout << ans <<endl;
    return 0;
}
