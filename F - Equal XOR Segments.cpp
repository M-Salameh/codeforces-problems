#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) (v.begin(),v.end())

using namespace std;

const int inf = 2e8+7;
int tc = 1;
const int NN = 1010;
int n,q;
vector<int> arr;
vector<int> pref;

map<int,vector<int>> pos;

void solve()
{
    for(auto& [idx,vals] : pos)
    {
        vals.push_back(n+1);
    }

    while(q--)
    {
        int l,r;
        cin >> l >> r;
        if (pref[l-1] == pref[r])
        {
            cout << "YES" << endl;
            continue;
        }
        auto x = lower_bound( pos[pref[r]].begin() , pos[pref[r]].end() , l );
        auto y = upper_bound( pos[pref[l-1]].begin() , pos[pref[l-1]].end() , r );
        y--;
        if (*x < *y)
        {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> tc;
    while(tc--)
    {
        cin >> n >> q;
        arr = vector<int> (n+1 , 0);
        pref = vector<int> (n+1 , 0);
        pos.clear();pos[0].push_back(0);

        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
            pref[i] = pref[i-1] ^ arr[i];
            pos[pref[i]].push_back(i);
        }
        solve();
    }
    return 0;
}
 