#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define s second
#define f first
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

map<int,vector<int>> requst,reciv;
map<int,vector<pair<int,char>>> ans;
vector<int> ids;
int vis[10000007]={0};
int main()
{
    fastio;
    int tt=1;
    //cin>>tt;
    while(tt--)
    {
   int n,m;
   cin>>n>>m;
   int erro=0,miss=0,notre=0;
   for(int i=1;i<=n;i++)
   {
       int id;
       cin>>id;
       ids.pb(id);
       vis[id]=1;
       int num;
       cin>>num;
       while(num--)
       {
           int x;
           cin>>x;
           requst[id].pb(x);
       }
   }
   for(int i=1;i<=m;i++)
   {
       int id;
       cin>>id;
       if(!vis[id])
       ids.pb(id);
       int num;
       cin>>num;
       while(num--)
       {
           int x;
           cin>>x;
           reciv[id].pb(x);
       }
   }

   for(auto u:ids)
   {
     bool chk1=false , chk2 = false;
     for(int i=0;i<requst[u].size();i++)
     {
         auto it=find(reciv[u].begin(),reciv[u].end(),requst[u][i]);
         if(it==reciv[u].end())
         {
             chk1=true;
         ans[u].pb({requst[u][i],'e'});
         miss++;
         }
     }
     for(int i=0;i<reciv[u].size();i++)
     {
         auto it=find(requst[u].begin(),requst[u].end(),reciv[u][i]);
         if(it==requst[u].end())
         {
             chk2 = true;
         ans[u].pb({reciv[u][i],'c'});
         notre++;
         }
     }
     erro += (chk1 | chk2);
   }
   if(!erro)cout<<"GREAT WORK! NO MISTAKES FOUND!"<<endl;
   else{
        sort(ids.begin(),ids.end());
     for(auto u:ids)
     {
         if(ans[u].size()>0){
         cout<<u<<" ";
         sort(ans[u].begin(),ans[u].end());
         for(auto k:ans[u])
         {
             if(k.second=='e')cout<<"+";
             else cout<<"-";
             cout<<k.first<< " ";
         }
         cout<<endl;
    }
     }
    cout<<"MISTAKES IN "<<erro<<" STUDENTS: "<<notre<<" NOT REQUESTED, "<<miss<<" MISSED"<<endl;
    }
    }
    return 0;
}
 