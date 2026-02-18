#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define int int_fast64_t
#define pii pair<int,int>

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 2e18+1;
const int NN = 2e5+3;
const int mod = 1e9+7;
int tc=1;
int n, m;
vector<int> adj[NN] ,rev_adj;
map<int,int> dist_freq[NN];
int sub[NN], depth[NN];
int ans;

void dfs(int node = n , int parent = 0)
{
    if (sub[node]) return;
    depth[node] = depth[parent] + 1;
    for (int& child : adj[node])
    {
        if (child == parent) continue;
        dfs(child , node);
        if (dist_freq[child].size() > dist_freq[node].size())
        {
            swap(dist_freq[node] , dist_freq[child]);
            swap(sub[node] , sub[child]);
        }
        int overlap_child = 0 ;
        int overlap_node = 0;
        auto child_it = dist_freq[child].begin();
        auto node_it = dist_freq[node].begin();
        while (child_it != dist_freq[child].end() )
        {
            int dep_n = node_it -> first - depth[node];
            int dep_c = child_it -> first - depth[node];
            int freq_n = node_it -> second;
            int freq_c = child_it -> second;
            ans += dep_n * freq_n * (sub[child] - overlap_child);
            ans += dep_c * freq_c * (sub[node] - overlap_node);
            overlap_child += freq_c;
            overlap_node += freq_n;
            node_it->second += freq_c;
            node_it ++;
            child_it ++;
            
        }
        sub[node] += sub[child];
    }
    dist_freq[node][depth[node]] += 1;
    sub[node] += 1;
}

void solve()
{
    for (int i=1 ; i<n; i++)
    {
        adj[rev_adj[i]].push_back(i);
    }
    dfs();


    cout << ans << endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///freopen("test_input.txt" , "r" , stdin);
    ///freopen("test_output.txt" , "w" , stdout);
    auto time_start = clock();
    cin >> tc;
    while (tc--)
    {
        for (int i=0 ; i<=n+1 ; i++)
        {
            sub[i] = 0;
            adj[i].clear();
            depth[i] = 0;
            dist_freq[i].clear();
        }
        ans = 0;

        cin >> n >> m;
        rev_adj = vector<int> (n+1 , 0);

        for (int i=1 ; i<n ; i++) 
        {
            rev_adj[i] = i+1;
        }

        for (int i=1 , u , v ; i<=m ; i++)
        {
            cin >> u >> v;
            rev_adj[u] = max (rev_adj[u] , v);
        }

        solve();


    }
    
    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}