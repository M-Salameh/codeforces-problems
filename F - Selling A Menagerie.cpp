#include <bits/stdc++.h>
#include <math.h>
#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
using namespace std;

typedef pair<int,int> pi;

int tc;
int n;

vector<int> importance;
vector<int> afraid;
vector<int> price;

void read()
{
    importance = vector<int>(n+1 , 0);
    afraid = vector<int>(n+1 , 0);
    price = vector<int>(n+1 , 0);

    for (int i=1 ; i<=n ; i++)
    {
        cin >> afraid[i];
    }
    for (int i=1 ; i<=n ; i++)
    {
        cin >> price[i];
        importance[afraid[i]] += price[i];
    }
//    for (int i=1 ; i<=n ; i++)
//    {
//        cout << i <<" : " << importance[i] << endl;
//    }
    return;
}


void solve()
{
    vector<bool> taken(n+1,false);
    priority_queue<pi> q;
    for(int i=1 ; i<=n  ; i++)
    {
        q.push({-importance[i],i});
    }
    while(q.size())
    {
        pi x = q.top();
        q.pop();
        if (taken[x.second]) continue;

        cout << x.second << ' ';
        importance[afraid[x.second]] -= price[x.second];
        q.push({-importance[afraid[x.second]] , afraid[x.second]});
        taken[x.second] = true;
    }

    cout << endl;
    return;
}

signed main()
{
    fast;
    cin >> tc;

    while(tc--)
    {
        cin >> n;

        read();
        solve();
    }

    return 0;
}
