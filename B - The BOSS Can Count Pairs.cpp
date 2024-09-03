#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;

const int NN = 2e5+5;
const int inf = 8e18;
int tc=1;
set<int> as;
vector<int> bs[NN];
int arr[NN] , brr[NN];
int n;
int ans ;

void solve()
{
    for (auto i : as)
    {
        sort(all(bs[i]));
        bs[i].push_back(inf);
    }

    for (auto a1 : as)
    {
        for (auto a2 : as)
        {
            int ai = a1 , aj = a2;
            if (ai*aj > 2*n) break;
            if (bs[ai].size() > bs[aj].size())
            {
                swap(ai,aj);
            }
            for (auto bi : bs[ai])
            {
                int rem = ai*aj-bi;
                if (rem <= 0) break;
                ///cout << "ai = " << ai << " , aj = " << aj << " and rem = " << rem << endl;
                ///cout << "bi = " << bi << endl;
                int l = lower_bound(all(bs[aj]) , rem) - bs[aj].begin();
                auto r = upper_bound(all(bs[aj]) , rem) - bs[aj].begin();
                if (l == r) continue;
                r--;
                ans += (r - l + 1);
            }
        }
    }
    ans /= 2;
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        ans = 0;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
            as.insert(arr[i]);
        }
        for (int i=1 ; i<=n ; i++)
        {
            cin >> brr[i];
            bs[arr[i]].push_back(brr[i]);
            if (arr[i]*arr[i] == brr[i] + brr[i]) ans--;
        }
        solve();
        for (int i=1 ; i<=n ; i++)
        {
            bs[arr[i]].clear();
        }
        as.clear();
    }

    return 0;
}
