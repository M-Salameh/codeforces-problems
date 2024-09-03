#include<bits/stdc++.h>
using namespace std;
int parent[150087],n,m,x,y,i;
vector<int>v[150087];

int dfs(int x)

{
    for(auto p:v[x])
        {
            parent[p]=x;
        }
        for(int p:v[x])
        {
            for(int q:v[p])
            {
                if( q !=x && parent[q]!=x ) return 0;
            }

    }
        return 1;
}
int main()

{
    cin>>n>>m;
    for(i=0;i<m;i++)
        {
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
    for(i=1;i<=n;i++)
        {
            x=dfs(i);
            if(!x)
            {
                cout<<"NO\n";
                return 0;
            }

        }
         cout<<"YES\n";
return 0;
}
