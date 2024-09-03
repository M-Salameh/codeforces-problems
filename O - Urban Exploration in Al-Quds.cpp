///https://codeforces.com/gym/538311/problem/O
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int inf = 1e18+8;
const int NN = 5e5+5;
int n , tc=1;

struct trie
{
    trie* oneChild; trie* zeroChild;
    int num0, num1;
    trie()
    {
        num1 = num0 = 0;
        oneChild = zeroChild = NULL;
    }

};

trie *root, *cur;

void add(trie* root, int x)
{
    cur = root;
    int bit = (1ll << 62);
    while (bit)
    {
        if(x & bit)
        {
            if(cur->oneChild == NULL)
            {
                cur -> oneChild = new trie();
            }
            cur -> num1 ++;
            cur = cur -> oneChild;
        }
        else
        {
            if(cur -> zeroChild == NULL)
            {
                cur -> zeroChild = new trie();
            }
            cur -> num0 ++;
            cur = cur -> zeroChild;
        }

        bit >>= 1;
    }
}

void del(trie* root, int x)
{
    cur = root;
    int bit = (1ll << 62);
    while(bit)
    {
        if(x & bit)
        {
            cur -> num1--;
            cur = cur -> oneChild;
        }
        else
        {
            cur -> num0 --;
            cur = cur -> zeroChild;
        }
        bit >>= 1;
    }
}

int answer(trie* root, int x)
{
    cur = root;
    int Ans = 0;
    int bit = (1ll << 62);
    while(bit)
    {
        if(x & bit)
        {
            if(cur->num1 == 0)
            {
                Ans += bit;
                cur = cur -> zeroChild;
            }
            else
            {
                cur = cur -> oneChild;
            }
        }
        else
        {
            if(cur -> num0 == 0)
            {
                Ans += bit;
                cur = cur -> oneChild;
            }
            else
            {
                cur = cur -> zeroChild;
            }
        }

        bit >>= 1;
    }
    return Ans;
}

vector<int> adj[NN];
int arr[NN] , ans[NN];

void dfs(int node = 1 , int parent = 0)
{
    if (node > 1)
    {
        ans[node] = answer(root , arr[node]);
    }

    add(root , arr[node]);

    for (auto& child : adj[node])
    {
        if (child == parent) continue;
        dfs(child , node);
        ans[node] = min (ans[node] , ans[child]);
    }

    del(root , arr[node]);
}


void solve()
{
    dfs();
    int q;
    cin >> q;
    while(q--)
    {
        int x ; cin >> x;
        cout << ans[x] << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ///cin >> tc;
    while(tc--)
    {
        cin >> n;
        for (int i=2 ; i<=n ; i++)
        {
            int x; cin >> x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
        }
        root = new trie();

        solve();
    }

    return 0;
}
