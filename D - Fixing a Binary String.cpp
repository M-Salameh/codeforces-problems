#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int inf = 1e18+8;
const int NN = 5e5+5;
int n , tc=1;
int k;

string s;

int get_idx()
{
    int ptr1 = 1;
    int idx = inf;
    while(ptr1 <= n)
    {
        int ptr2 = ptr1;
        while (s[ptr1] == s[ptr2]) ptr2++;
        if (ptr2 - ptr1 < k)
        {
            idx = ptr2;
            return idx;
        }
        else if (ptr2 - ptr1 > k)
        {
            idx = ptr2 - k;
            return idx;
        }
        ptr1 = ptr2;
    }
    return idx;
}

void solve()
{
    int idx = min(n,get_idx());
    ///cout << "idx = " << idx << endl;
    int ans = (idx == n ? n : idx-1);
    string arr = "";
    for (int i = idx ; i<=n ; i++)
    {
        arr += s[i];
    }
    for (int i=idx-1 ; i>=1 ; i--)
    {
        arr += s[i];
    }

    ///cout << "arr = " << arr  << " -- " << arr.size() << endl;
    for (int i=0 ; i<k ; i++)
    {
        if (arr[i] != arr[0])
        {
            cout << -1 << endl;
            return;
        }
    }

    for (int i=k ; i<n ; i++)
    {
        if (arr[i] == arr[i-k])
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n >> k;
        cin >> s;
        s = "@" + s;
        solve();
    }

    return 0;
}
