#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#include <math.h>
#define MOD 1000000007
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define pi pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin()+1,x.end()
#define all0(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define ll unsigned long long
#define int long long
#define double long double
#pragma once
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'


using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 5e15+6;
int n,w,m;

map<int,vector<int>> pos;
vector<int> pref;
signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        string s;
        cin >> s;
        cin >> w >> m;
        n = s.size();
        s = "&" + s + "&";
        pos.clear();
        pref = vector<int> (n+3 , 0);

        for(int i=1;i<=n;i++) pref[i] = pref[i-1] + (s[i]-'0');

        for(int i=1;i<=n-(w-1);i++)
        {
            int x = pref[w-1+i]-pref[i-1];
            x = (x+9)%9;
            pos[x].push_back(i);
        }
        while(m--)
        {
            int l, r, k;
            cin >> l >> r >> k;
            int ans1 = 1e9, ans2 = 1e9;
            int x = pref[r] - pref[l-1];
            x %= 9;
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    if(((i*x)%9+j)%9 == k)
                    {
                        if(i == j)
                        {
                            if(pos[i].size() < 2) continue;

                            if(pos[i][0] < ans1)
                            {
                                ans1 = pos[i][0];
                                ans2 = pos[i][1];
                            }

                            else if(pos[i][0] == ans1)
                            {
                                ans2 = min(ans2, pos[i][1]);
                            }
                        }
                        else
                        {
                            if(pos[i].empty() or pos[j].empty()) continue;

                            if(pos[i][0] < ans1)
                            {
                                ans1 = pos[i][0];
                                ans2 = pos[j][0];
                            }
                            else if(pos[i][0] == ans1) ans2 = min(ans2, pos[j][0]);
                        }
                    }
                }
            }
            if(ans1 == 1e9) cout << -1 << " " << -1 << endl;
            else cout << ans1 << " " <<ans2 << endl;
        }
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
