#include <bits/stdc++.h>
#include <math.h>
#include <string>
#define endl '\n'
//#define int long long
#define double long double
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536
#define ll long long

const int MOD = 1e9+7;

using namespace std;

int tc=1;
int n;
map <string , vector<string>> adj;
set <pair<int,string>> ans;
map <string,bool> visited;
map <string , int> rankk;

void read()
{
    for (int i=1 ;i<=n ; i++)
    {
        string s1 , s2 , s3;
        cin >> s1 >> s2 >> s3;
        adj[s1].push_back(s2);
        adj[s1].push_back(s3);

        adj[s2].push_back(s1);
        adj[s2].push_back(s3);

        adj[s3].push_back(s1);
        adj[s3].push_back(s2);

    }

}

void bfs()
{
    queue<string> q;
    q.push("Ahmad");
    rankk["Ahmad"] = 0;
    while (q.size())
    {
        string s = q.front();
        for (auto i : adj[s])
        {
            if (!visited[i])
            {
                visited[i]= true;
                rankk[i] = rankk[s]+1;
                ans.insert(make_pair(rankk[i],i));
                q.push(i);
            }
        }
        q.pop();
    }
}


void print()
{
    cout << adj.size() << endl;
    for (auto i : ans)
    {
        cout << i.second  << ' ' << i.first << endl;
    }
    for (auto i : adj)
    {
        if (!visited[i.first])
        {
            cout << i.first << ' ' << "undefined" << endl;
        }
    }
}

void reset()
{
    adj.clear();
    ans.clear();
    visited.clear();
    rankk.clear();
    ans.insert(make_pair(0,"Ahmad"));
    visited["Ahmad"]=true;
}

signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        reset();
        cin >> n;
        read();
        bfs();
        print();

    }
    return 0;
}
