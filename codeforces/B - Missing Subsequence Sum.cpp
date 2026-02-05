#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int NN = 5e5+5;
const int inf = 8e8;
int tc = 1;
int n , k;
multiset<int> ans;

void solve()
{
    int msb = __lg(k);
    int x = (1 << msb);
    ans.erase(ans.find(x));
    int y = k-x;
    //cout << "y = " << y << endl;
    if(y) ans.insert(y);
    ans.insert(k+1);
    ans.insert(k+1+x);
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    cin >> tc;
    while (tc--)
    {
        cin >> n >> k;
        int msb = 0;
        ans.clear();

        while (true)
        {
            int x = 1 << msb;
            if (x <= n)
            {
                ans.insert(x);
                msb++;
            }
            else
            {
                ans.insert(x);
                break;
            }
        }
        solve();
    }

    return 0;
}
