#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#include <math.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define pi pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin()+1,x.end()
#define all0(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define ll unsigned long long
#define int long long
#define double long double
#pragma once
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 1e18+6;
int n,q;
vector<int> adj[500500];
vector<int> sizes;
stack<int> vertx;
vector<int> orr;
vector<int> leftt;
vector<int> rightt;
vector<int> arr;

struct task
{
    int u;
    int v;
    int x;
};

vector<task> tasks;
int tot_size;

struct snode
{
    int val = 0;
    int No_OP = 0;
    bool op = false;
};

snode segt[8008000];


void build(int node=1 , int l=1 , int r=n)
{
    if (l>r) return;
    if (l==r)
    {
        segt[node].val = arr[r];
        return;
    }
    build(lc , l , mid);
    build(rc , mid+1 , r);
    segt[node].val = (segt[lc].val + segt[rc].val);
    return;
}



void propagate(int node , int l , int r)
{
    if (!segt[node].op) return;


    segt[node].val += segt[node].No_OP;

    if (l<r)
    {
        segt[rc].No_OP += segt[node].No_OP;
        segt[lc].No_OP += segt[node].No_OP;
        segt[rc].op = segt[lc].op = true;
    }

    segt[node].No_OP = 0;
    segt[node].op = false;
}


int query(int node , int l , int r , int st , int en)
{
    propagate(node , l , r);
    if (st>en or st>r or en<l) return 0;
    if (st<= l and r<=en) return segt[node].val;
    int p1 = query(lc , l , mid , st , en);
    int p2 = query(rc , mid+1 , r , st , en);
    return  p1+p2;

}

void update(int node , int l , int r , int st , int en , int val)
{
    propagate(node,l,r);
    if (en<l or st>r or st>en) return;
    if (st<=l && r<=en)
    {
        segt[node].No_OP += val;
        segt[node].op = true;
        propagate(node,l,r);
        return;
    }
    update(lc , l , mid ,  st , en , val);
    update(rc , mid+1 , r , st , en , val);
    ///segt[node].val = segt[lc].val + segt[rc].val;
    return;
}

void print()
{
    for (int i=1 ; i<4*n+3 ; i++)
        cout << segt[i].val<<','<<segt[i].No_OP<< endl;
}

void reset()
{
    snode stand;
    stand.No_OP = 0;
    stand.val = 0;
    stand.op = false;
    for (int i=1 ; i<=4*n+3; i++)
    {
        segt[i] = stand;
    }
    vertx = stack<int>();
    sizes = vector<int> (n+1,0);
    tot_size = 1;
}


void dfs(int node)
{
    sizes[node] = 0;

    for (auto child : adj[node])
    {
       /// cout << "child = " << child <<endl;
        dfs(child);
        sizes[node] += 1+sizes[child];
    }

   /// cout << "now at node : " << node << endl;
    vertx.push(node);
    return;
}


void solve()
{
    dfs(1);

    while(vertx.size())
    {
        orr.push_back(vertx.top());
        vertx.pop();
    }

    /**for (auto i : orr) cout << i << ' ';
        cout << endl;*/

    for (int i=1 ; i<=n ; i++)
    {
        leftt[orr[i]] = i;
        rightt[orr[i]] = i+sizes[orr[i]];
        //cout << "size["<<i<<"] = " << sizes[i] << endl;
        //cout << "right["<<i<<"] = " << sizes[i] << endl;
    }

    ///build();
    for (auto tsk : tasks)
    {
        if (tsk.x == 0)
        {
            //cout << "adding vertex : " << tsk.u << endl;
            int temp = query(1,1,n,leftt[tsk.u],leftt[tsk.u]);
            //cout << "temp = " << temp << endl;
            update(1,1,n,leftt[tsk.u],leftt[tsk.u] , -temp);
            ///cout << "left["<<tsk.u<<"] = " << leftt[tsk.u] <<endl;
           /// cout << "right["<<tsk.u<<"] = " << rightt[tsk.u] <<endl;
        }
        else
        {
            //cout << "updating " << endl;

            update(1,1,n,leftt[tsk.v],rightt[tsk.v],tsk.x);
        }
        //cout << "printing status" << endl;

       /// cout << "***************************************" << endl;
    }

    ///print();

    vector<int> ans(n+1 , 0);
    for (int i=1 ; i<=n ; i++)
    {
        ans[orr[i]] = query(1,1,n,i ,i);
    }

    for (int i=1 ; i<=n ; i++)
        cout << ans[i] << ' ';
    cout << endl;
}


signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        cin >> q;
        tot_size =1;
        for (int i=1 ; i<=q ; i++)
        {
            int t ,v , x;
            task tsk;
            cin >> t >> v ;
            tsk.u = t;
            tsk.v = v;
            if (t == 1)
            {
                adj[v].push_back(++tot_size);
                tsk.x = 0;
                tsk.u = tot_size;
                tasks.push_back(tsk);
                ///cout << "inserting " << endl;
            }
            else
            {
                cin >> x;
                tsk.x = x;
                tasks.push_back(tsk);
                ///cout << "getting X" <<endl;
            }

        }
        n = tot_size;
        reset();
        leftt = vector<int> (n+1 , 0);
        rightt = vector<int> (n+1 , 0);
        arr = vector<int> (n+1 , 0);
        orr.clear();
        orr.push_back(0);
       /// cout << "before sovle" <<endl;
        solve();

        for(int i=1 ; i<=n ; i++)
        {
            adj[i].clear();
        }
        tasks.clear();
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
