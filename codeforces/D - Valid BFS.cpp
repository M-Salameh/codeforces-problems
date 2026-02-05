#include <bits/stdc++.h>
#include <map>
#define ll long long
using namespace std;
const int NN=200005;
vector<int>adj[NN];
set<int>s[NN];
int arr[NN];
void dfs(int node=1,int parent=-1){
  for(auto child:adj[node]){
    if(child==parent)continue;
    s[node].insert(child);
    dfs(child,node);
  }
  return;
}
int main()
{
    int n,u,v;
    cin >> n ;
    for(int i=1;i<=n-1;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    int ptr2=1;
    dfs(1,-1);
    if(arr[1]!=1){
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=1;i<n;i++){
        //cout<<i<< ' ' <<ptr2<<endl;
        if(s[arr[i]].size()==0)continue;
        for(int j=1;j<s[arr[i]].size()+1;j++){
            if(s[arr[i]].find(arr[ptr2+j])==s[arr[i]].end()){
                cout<<"No"<<endl;
                return 0;
            }
        }
        ptr2+=s[arr[i]].size();
    }
   /* cout<<s[5].size()<<endl;
    cout<<*s[5].begin()<<endl;*/
    cout<<"Yes"<<endl;
    return 0;
}
