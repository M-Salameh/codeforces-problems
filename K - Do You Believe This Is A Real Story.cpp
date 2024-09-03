#include <bits/stdc++.h>
#include <string>
#define endl '\n'
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define ll long long
//#define double long double

using namespace std;

int tc=1;

vector<int>path;
vector<int>adj[200100];
bool visited[200100];


void bfs()
{
    priority_queue<int>q;
    q.push(-1);
    while(q.size()){
        int x=q.top();
        q.pop();
        visited[-x]=true;
        path.push_back(-x);
        for(auto i:adj[-x]){
            if(!visited[i])q.push(-i);
        }
    }
}

signed main()
{
    //fast;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)adj[i].clear();
        for(int i=1;i<=n;i++)visited[i]=false;
        path.clear();
        for(int i=1;i<=n;i++){
            int x=i+3;
            if(x>n)x-=n;
            int y=i-3;
            if(y<=0)y+=n;
            if(x<y){
                adj[i].push_back(x);
                adj[i].push_back(y);
            }
            else{
                adj[i].push_back(y);
                adj[i].push_back(x);
            }
        }
        bfs();
        if(path.size()>=n-1){
            cout<<"YES"<<endl;
            for(int i=0;i<n-1;i++)cout<<path[i]<<" ";cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}