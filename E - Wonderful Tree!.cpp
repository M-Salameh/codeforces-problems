#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int inf = 2e18+8;
const int NN = 5e3+5;
int n , tc=1;
int arr[NN] , ans;
int brr[NN];
int depth[NN];
bool leaf[NN];
vector<int> adj[NN];


void bfs(int node , int need)
{
    queue<int> pq ; pq.push(node);

    while(pq.size() and need>0)
    {
        int u = pq.front(); pq.pop();

        if (leaf[u])
        {
            ans += need * (depth[u] - depth[node]);
            return;
        }
        int temp = min (brr[u] , need);

        ans += temp * (depth[u] - depth[node]);

        need -= brr[u];

        brr[u] -= temp;

        if (brr[u]) return;

        for (int child : adj[u]) pq.push(child);

    }
}

void dfs(int node = 1)
{
    if (adj[node].size() == 0)
    {
        leaf[node] = true;
        return;
    }
    int sum = 0;
    for (int child : adj[node])
    {
        dfs(child);
        sum += arr[child];
    }

    if (sum >= arr[node])
    {
        brr[node] = sum - arr[node];
        return;
    }

    bfs(node , arr[node] - sum);

}

void solve()
{
    ans = 0;

    dfs();

    cout << ans << endl;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
            adj[i].clear();
            depth[i] = 0;
            leaf[i] = false;
            brr[i] = 0;
        }
        for (int i=2 ; i<=n ; i++)
        {
            int parent; cin >> parent;
            adj[parent].push_back(i);
            depth[i] = depth[parent] + 1;
        }
        solve();
    }

    return 0;
}
