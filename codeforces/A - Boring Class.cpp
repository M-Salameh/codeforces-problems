///https://codeforces.com/gym/105190/problem/A

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) x.begin(),x.end()

using namespace std;
const int Mod = 1e9 + 7;
const int inf = 1e18;
const int NN = 2e5+5;
const int SQ = 350; // sqrt NN
int tc=1;
int n,q;
int arr[NN], inv[NN + 10];
vector<vector<int>> brr(SQ);
vector<vector<int>> pref(SQ), pref2(SQ);
int pw(int x, int y)
{
    int res = 1;
    int xx=x;int yy=y;
    while (yy > 0) {
        if (yy % 2 == 1)
            res = (res * xx)%Mod;
        yy = (yy >> 1)%Mod;
        xx = (xx * xx)%Mod;
    }
    return res%Mod ;
}
void clearr()
{
    for(int i=0; i<SQ; i++){
        brr[i].clear();
        pref[i].clear();
        pref2[i].clear();
    }
}
void precalc()
{
    for(int i=0;i<=NN;i++)
    {
        inv[i]=pw(i, Mod-2);
    }
}
void recalc(int i)
{
    sort(all(brr[i]));
    pref[i].clear();
    pref2[i].clear();
    pref2[i].push_back(1);
    pref[i].push_back(1);

    for (int& val : brr[i])
    {
        pref[i].push_back( ((val * pref[i].back())%Mod + Mod) % Mod);
        pref2[i].push_back( ((inv[val] * pref2[i].back())%Mod + Mod) % Mod);
    }

}

void process()
{
    for (int i=0 ; i<n ; i++)
    {
        brr[i/SQ].push_back(arr[i]);
    }
    for (int i=0 ; i< SQ and brr[i].size()>0 ; i++)
    {
        recalc(i);
    }
}

void update(int idx , int val)
{
    int blk_idx = idx/SQ;
    int idx_in_blk = idx%SQ;
    auto it = lower_bound(all(brr[blk_idx]) , arr[idx]);
    *it = val;
    arr[idx] = val;
    recalc(blk_idx);
}

pair<int,int> get (int blk_idx, int x)
{
    int idx = upper_bound(all(brr[blk_idx]) , x) - brr[blk_idx].begin();
    if(idx == brr[blk_idx].size()) return {0, 1};
    int num = brr[blk_idx].size() - idx;
    int prod = ((pref2[blk_idx].back() * pref[blk_idx][idx])%Mod + Mod) %Mod;
    return {num, prod};
}

pair<int,int> query(int l , int r , int x)
{
    pair<int,int> ans = {0,1};
    while (l<=r)
    {
        if (l%SQ==0 and (l+SQ)<=r)
        {
            pair<int,int> temp = get(l/SQ,x);
            ans.first += temp.first;
            ans.second = ((ans.second * temp.second)%Mod + Mod) % Mod;
            l += SQ;
        }
        else
        {
            if (arr[l] > x)
            {
                ans.first += 1;
                ans.second = ((ans.second * inv[arr[l]])%Mod + Mod) % Mod;
            }
            l++;
        }
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    precalc();
    cin >> tc;
    while(tc --)
    {
        cin >> n;
        for (int i=0 ; i<n ; i++)
        {
            cin >> arr[i];
        }
        clearr();
        process();
        cin >> q;
        while(q--)
        {
            int op;
            cin >> op;
            if (op == 1)
            {
                int idx , val;
                cin >> idx >> val; // 0-based
                update(--idx , val);
            }
            else
            {
                int l,r,x;
                cin >> l >> r >> x;
                pair<int,int> num_prod = query(--l , --r , x);
                int ans = ((pw(x, num_prod.first) * num_prod.second) % Mod + Mod) % Mod;
                cout << ans << endl;
            }
        }
    }
    return 0;
}
