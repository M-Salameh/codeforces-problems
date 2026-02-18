#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#define endl '\n'
#define int int_fast64_t

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 2e18+1;
const int NN = 1e6+3;
const int mod = 1e9+7;
int tc=1;
int n;
vector<int> arr[NN];
map<int,int> freq;
pair<int,int> mex[NN];
int total_mex = 0;

int affect(int v_idx , int arr_idx)
{
    vector<int>& temp = arr[arr_idx];
    if (temp.back() != NN) temp.push_back(NN);
    if (temp.size() == 2)
    {
        if (temp[0] == 0) return total_mex-1;
    }
    if (temp[v_idx] == temp[v_idx+1] or (v_idx>0 and temp[v_idx-1]==temp[v_idx]))
    {
        ///return mex[arr_idx].first;
        return total_mex;
    }

    if (temp[v_idx] > mex[arr_idx].first) return total_mex; ///return mex[arr_idx].first;
    return temp[v_idx]+total_mex-mex[arr_idx].first;

}

void solve()
{
    for (int i=1 ; i<=n ; i++) sort(all(arr[i]));
    int ans = 0;
    for (int i=1 ; i<=n ; i++)
    {
        for (int& x : arr[i])
        {
            if (x > mex[i].first) break;
            mex[i].first += 1ll*(x == mex[i].first);
        }
        total_mex += mex[i].first;
        mex[i].second = 1 + mex[i].first;
        for (int& x : arr[i])
        {
            if (x > mex[i].second) break;
            mex[i].second += 1ll*(x == mex[i].second);
        }
    }
    for (int i=1 ; i<=n ; i++)
    {
        int old_size = arr[i].size();
        for (int j=0 ; j<old_size ; j++)
        {
            ans += (n-1)*(affect(j , i));
        }
        ans += (freq[mex[i].first]) * (mex[i].second - mex[i].first);
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> tc;
    auto time_start = clock();
    while (tc--)
    {
        cin >> n;
        for (int i=1, sz ; i<=n ; i++)
        {
            cin >> sz;
            for (int j=1,x ; j<=sz ; j++)
            {
                cin >> x;
                arr[i].push_back(x);
                freq[x]++;
            }
        }
        solve();
        for (int i=1 ; i<=n ; i++)
        {
            arr[i].clear();
            mex[i] = {0,0};
        }
        freq.clear();
        total_mex = 0;
    }
    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;
    return 0;
}