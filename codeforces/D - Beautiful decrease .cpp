///https://codeforces.com/gym/105020/problem/D
#include <bits/stdc++.h>
#define int long long
#define lc 2*node
#define rc 2*node+1
#define mid (l+r)/2
#define endl '\n'

using namespace std;

const int inf = 1e17+8;
const int NN = 1e5+5;
int n , tc=1;
int q , k;

struct vertex
{
    int sum = 0 ; int pushX = 0; int mini = inf ; int idx = inf;
};
vertex fuck;

vertex merge(vertex& a , vertex& b)
{
    vertex ans;
    ans.pushX = 0;
    ans.sum = a.sum + b.sum;
    if(a.mini < b.mini)
    {
        ans.mini = a.mini;
        ans.idx = a.idx;
    }
    else if(a.mini == b.mini)
    {
        ans.mini = a.mini;
        ans.idx = max(a.idx, b.idx);
    }
    else
    {
        ans.mini = b.mini;
        ans.idx = b.idx;
    }
    return ans;
}

int arr[NN];
vertex segt[4*NN];

void build (int node=1 , int l=1 , int r=n)
{
    if (l == r)
    {
        segt[node].idx = r;
        segt[node].mini = segt[node].sum = arr[r];
        segt[node].pushX = 0;
        return;
    }
    build (lc , l , mid);
    build (rc , mid+1 , r);

    segt[node] = merge(segt[lc] , segt[rc]);
}

void propagate(int node , int l , int r)
{
    if (segt[node].pushX == 0) return;
    segt[node].sum -= segt[node].pushX * (r - l + 1);
    segt[node].mini -= segt[node].pushX;

    if (l < r)
    {
        segt[lc].pushX += segt[node].pushX;
        segt[rc].pushX += segt[node].pushX;
    }

    segt[node].pushX = 0;
}

void update(int node, int l, int r, int st, int en, int val)
{
    propagate(node, l , r);

    if(en < l or st > r or st > en) return;

    if(st <= l and r <= en)
    {
        segt[node].pushX += val;
        propagate(node, l, r);
        return;
    }
    update(lc, l, mid, st, en, val);
    update(rc, mid + 1, r, st, en, val);

    segt[node] = merge(segt[lc], segt[rc]);
    return;
}


vertex get(int node, int l, int r, int st, int en)
{
    propagate(node, l , r);

    if(en < l or st > r or st > en) return fuck;

    if(st <= l and r <= en) return segt[node];

    vertex p1 = get(lc, l, mid, st, en);
    vertex p2 = get(rc, mid+1, r, st, en);

    return merge(p1,p2);
}

map<int, vector<int> > pos;

priority_queue <pair <int , pair<int,int> > > pq;

void get_new_ranges(int min_prev , int l , int r)
{
    pq.pop();

    for (int j=0 ; j < pos[min_prev].size() ; j++)
    {
        int PosCur = pos[min_prev][j];
        if(PosCur<l or PosCur>r) continue;

        if (j==0 or pos[min_prev][j-1] < l)
        {
            if (PosCur > l)
            {
                pq.push({PosCur-l, {l, PosCur - 1}});
            }
            if(j == pos[min_prev].size()-1)
            {
                if(PosCur < r)
                {
                    pq.push({r-PosCur, {PosCur + 1, r}});
                }
            }
            continue;
        }

        if(j == pos[min_prev].size()-1)
        {
            if(PosCur < r) pq.push({r-PosCur, {PosCur + 1, r}});
        }

        int PosPrev = pos[min_prev][j-1];

        if(PosCur-1 >= PosPrev+1)
        {
            pq.push({PosCur-1-PosPrev, {PosPrev + 1, PosCur - 1}});
        }
    }
    return;
}

void solve()
{
    build();

    pq.push({n , {1,n} });

    while(q--)
    {
        int k ; cin >> k;
        while (k>0 and not pq.empty())
        {
            int st = pq.top().second.first;
            int en = pq.top().second.second;
            vertex cur = get(1 , 1 , n , st , en);

            int mini = cur.mini;
            int ops = min (k , mini);
            k -= ops;
            update(1,1,n , st , en , ops);

            if (mini - ops) continue;

            int min_prev = arr[cur.idx];

            get_new_ranges(min_prev , st , en);

        }
        cout << get(1 , 1 , n , 1 , n).sum << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ///cin >> tc;

    while(tc--)
    {
        cin >> n >> q;
        pos.clear();

        for (int i=1 ; i <= n; i++)
        {
            cin >> arr[i];
            pos[arr[i]].push_back(i);
        }

        solve();
    }

    return 0;
}
