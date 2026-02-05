#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#define lc 2*node
#define rc lc+1
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
///#define int int_fast64_t
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 2e12+1;
const int NN = 2e5+4;
const int MM = 1e3+1;
const int mod = 1e9+7;
int tc=1;
int n , q;
vector<int> adj[NN];
int arr[NN] , sub[NN];
bool processed[NN];
vector<pair<int,int>> modified[NN];

void dfs(int node=1 , int father = 0)
{
    sub[node] = 1;
    for (int child : adj[node])
    {
        if (child == father or processed[child]) continue;
        dfs(child , node);
        sub[node] += sub[child];
    }
}

int centroid (int node , int new_max , int par=0)
{
    for (int child : adj[node])
    {
        if (not processed[child] and child!=par and sub[child]>=new_max)
        {
            return centroid(child , new_max , node);
        }
    }
    return node;
}

void prop (int node , int par , int centr , int depth=0)
{
    modified[node].push_back({centr , depth});
    for (int child : adj[node])
    {
        if (child != par and not processed[child])
        {
            prop(child , node , centr , depth+1);
        }
    }
}

void centroid_decomp(int node = 1)
{
    cout << "from node : " << node << " we found centroid : " ;
    dfs(node , 0);
    int centr = centroid(node , sub[node]/2);
    processed[centr] = true;
    cout << centr << endl;
    prop(centr , 0 , centr);
    for (int child : adj[centr])
    {
        if (not processed[child]) centroid_decomp(child);
    }
}

int ans[NN];
set<int> red;

void update(int node)
{
    ans[node] = 0;
    red.insert(node);
    for (auto[centr , depth] : modified[node])
    {
        ans[centr] = min (ans[centr] , depth);
    }
}

int query(int node)
{
    if (red.count(node)) return 0;
    int dis = n+5;
    for (auto[centr , depth] : modified[node])
    {
        dis = min (dis , depth + ans[centr]);
    }
    return dis;
}

void solve()
{
    for (int i=0 ; i<=n+1 ; i++) ans[i] = NN;
    centroid_decomp();

    for (int i=1 ; i<=n ; i++)
    {
        cout << "node = " << i << " has : " << endl;
        for (auto [cen , dep] : modified[i])
        {
            cout << "centeroid = " << cen << " with depth = " << dep << endl;
        }
        cout <<"***********" << endl;
    }

    update(1);
    int a , b;
    while(q--)
    {
        cout << "q=" << q << endl;
        cin >> a >> b;
        if (a == 2)
        {
            cout << query(b) << endl;
        }
        else update(b);
    }
}

signed main()
{

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    auto time_start = clock();
    ///cin >> tc;
    while (tc--)
    {
        freopen("test_input.txt" , "r" , stdin);
        freopen("test_output.txt" , "w" , stdout);
        cin >> n >> q;
        for (int i=2 , u , v ; i<=n ; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve();

    }

    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
