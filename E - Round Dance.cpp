#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int NN = 200500;

int tc=1;
int n;
vector<int> adj[NN];
bool visited [NN];
bool visited2 [NN];
int arr[NN];


void reset()
{
    for (int i=1 ; i<=n ; i++)
    {
        adj[i].clear();
        visited[i]= false;
        visited2[i]= false;
        arr[i] = 0;
    }
}


void read()
{
    cin >> n;
    for (int i=1 ;i<=n ;  i++)
    {
        cin >> arr[i];
        adj[i].push_back(arr[i]);
        adj[arr[i]].push_back(i);
    }
}


bool dfs(int src , int father = 0)
{
   if (visited2[src]) return true;

    visited2[src] = visited[src] = true;
    bool ans = false;
    for (auto i : adj[src])
    {
        if (i != father)
        {
            ans |= dfs (i , src);
        }
    }
    visited2[src] = false;
    return ans;
}


void solve()
{
    int closed = 0 , open = 0;
    for (int i=1 ; i<=n ; i++)
    {
        if (!visited[i])
        {
            if (dfs(i))
            {
                closed++;
            }
            else open++;
        }
    }
    int maxi = open + closed;
    int mini = closed + (open>0);
    cout << mini <<  ' ' << maxi << endl;

}


int main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        read();
        solve();
        reset();
    }
    return 0;
}
