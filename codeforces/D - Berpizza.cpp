#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#define int long long
#define double long double
#define mid (l+r)/2
#define lc 2*node
#define rc lc+1
#define endl '\n'
#define fast  ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int tc=1;
int q;
int m;
int x;

void solve()
{
    int cust_num = 0;
    vector<int> ans;
    pair<int,int>pers;
    multiset<pair<int, int>> mono;
    multiset<pair<int,int>> poly;
    while(q--)
    {
        cin>>x;
        if(x == 1)
        {
            cin >> m;
            mono.insert(make_pair(cust_num, m));
            poly.insert(make_pair(m,-cust_num));
            cust_num++;
        }
        if(x == 2)
        {
            pers = *mono.begin();
            mono.erase(*mono.begin());
            poly.erase(make_pair(pers.second, -pers.first));
            ans.push_back(pers.first);
        }
        if(x == 3)
        {
            pers = *(--poly.end());
            ans.push_back(-pers.second);
            mono.erase(make_pair(-pers.second,pers.first));
            poly.erase(--poly.end());

        }
    }
    for (auto i : ans)
    {
        cout << i+1 << ' ';
    }
    cout <<endl;
    return;
}

signed main()
{
    fast;
  ///  cin >> tc ;
    while (tc--)
    {
        cin >> q;
        solve();
    }

}
