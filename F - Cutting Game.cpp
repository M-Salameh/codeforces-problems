#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int inf = 1e15+8;
const int NN = 3e5;
int n , m , a , b, tc=1;

set<pair <int,int>> row,col;
int x[NN] , y[NN];

void solve()
{
    int alice = 0 , bob = 0;

    int l_row = 1 , r_row = a;
    int l_col = 1 , r_col = b;

    int idx=0;

    for (int i=1 ; i<=m ; i++)
    {
        char op ; int k;
        cin >> op >> k;

        if (op == 'U')
        {
            l_row += k;
            while(row.size())
            {
                if (l_row<= row.begin()->first )break;
                idx = row.begin()->second;
                col.erase({y[idx], idx});
                row.erase(row.begin());
                alice += (i&1);
                bob += !(i&1);
            }
        }
        if (op == 'D')
        {
            r_row -= k;
            while(row.size())
            {
                auto it = --row.end();
                if(it->first <= r_row)break;

                idx = it->second;
                col.erase({y[idx], idx});
                row.erase(it);
                alice += (i&1);
                bob += !(i&1);
            }
        }

        if (op == 'L')
        {
            l_col += k;
            while(col.size())
            {
                if (l_col <= col.begin()->first) break;
                idx = col.begin()->second;
                row.erase({x[idx], idx});
                col.erase(col.begin());
                alice += (i&1);
                bob += !(i&1);
            }
        }
        if (op == 'R')
        {
            r_col -= k;
            while(col.size())
            {
                auto it = --col.end();
                if(it->first <= r_col)break;
                idx = it->second;
                row.erase({x[idx], idx});
                col.erase(it);
                alice += (i&1);
                bob += !(i&1);
            }
        }
    }

    cout << alice << " " << bob << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> a >> b >> n >> m;
        col.clear(); row.clear();
        for (int i=1 ; i<=n ; i++)
        {
            cin >> x[i] >> y[i];
            row.insert({x[i], i});
            col.insert({y[i], i});
        }
        solve();
    }

    return 0;
}
