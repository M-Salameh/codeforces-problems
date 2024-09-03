#include <bits/stdc++.h>
#define int long long
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

using namespace std;

const signed inf = 1e6+5;

int n,m;
int ans;

void solve()
{
    vector<int> v (n);
    ans=1;
    for (int i=0;i<n;i++)
    {
        cin >> v[i];
        ans+=v[i];
    }
    sort(v.begin() , v.end());
    int le=0;
    int ri=n-1;
    while(le<ri)
    {
        if (v[le]+v[ri] <= m)
        {
            le++;
            ri--;
        }
        else
        {
            ans++;
            ri--;
        }

    }
    cout << ans <<endl;
}

signed main()
{
    //fast_io;
    cin >> n >> m;
    solve();
    return 0;
}
