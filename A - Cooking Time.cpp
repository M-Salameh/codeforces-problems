#include <bits/stdc++.h>
///#define int long long
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
using namespace std;

int tc=1;
int n,k;

void solve()
{
    int arr[n+1];
    map <int,bool> taken;
    map <int,vector<int>> pos;
    multiset<pair<int,int>>on_table;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
        pos[arr[i]].push_back(i);
    }
    int ans=0;
    for (int i=1 ; i<=n ; i++)
    {
        if (!taken[arr[i]])
        {
            ans++;
            if (on_table.size() < k)
            {
                taken[arr[i]] = true;
                pos[arr[i]].erase(pos[arr[i]].begin());
                if (pos[arr[i]].size()) on_table.insert({pos[arr[i]].front() ,arr[i]});
            }
            else /// cur = k
            {
                taken[arr[i]] = true;
                pair<int,int> p = *--on_table.end();
                on_table.erase(p);
                taken[p.second] = false;
                pos[arr[i]].erase(pos[arr[i]].begin());
                if (pos[arr[i]].size()) on_table.insert({pos[arr[i]].front() ,arr[i]});
            }
        }
        else /// it's taken!
        {
            pair<int,int> p = *on_table.find({pos[arr[i]].front(),arr[i]});
            on_table.erase(p);
            pos[arr[i]].erase(pos[arr[i]].begin());
            if (pos[arr[i]].size()) on_table.insert({pos[arr[i]].front() ,arr[i]});
        }
    }
    cout << ans <<endl;
}
/**
3
5 3
2 4 5 2 1
7 3
1 2 3 4 3 2 1
13 2
3 4 5 3 5 3 5 5 5 4 4 4 4

ans=4,5,4
*/
signed main()
{
    fast;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> k ;
        solve();
    }

    return 0;
}
