#include <bits/stdc++.h>
#define int long long
#define mid (l+r)/2
#define lc 2*node
#define rc lc+1
#define endl '\n'

using namespace std;

int tc , n;

void solve()
{
    vector<int> a(n+1);
    vector<int> b(n+1);
    multiset<int> ms;
    int cur;
    int s=0,offset=0;
    /// offset for a[i] that must serve after i but not pre i in accumulative
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1 ;i<=n ; i++)
    {
        s=0;
        ms.insert(a[i]+offset);
        while(ms.size())
        {
            cur = *ms.begin() - offset;
            if (cur < b[i])
            {
                ms.erase(ms.find(*ms.begin()));
                s+=cur;
            }
            else break;
        }
        s += b[i]*ms.size();
        cout << s <<' ';
        offset+=b[i];
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n ;
        solve();
    }
    return 0;
}
