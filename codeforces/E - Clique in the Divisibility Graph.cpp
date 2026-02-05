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

const int inf = 1e6+5;

int tc=1;
int q;
int m;
int x;
int n;
int dp[inf];
void solve_D()
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


void solve_E()
{
    int arr[n+1]={0};
    for (int i=1 ;i<=n ; i++)
    {
        cin >> arr[i];
        dp[arr[i]] = 1;
    }
    int i=1;
    int ans=0;
    while (i<=arr[n])
    {
        if (dp[i]==0)
        {
            i++;
            continue;
        }
        for (int j=2*i ; j<=arr[n] ; j+=i)
        {
            if (dp[j]!=0)
            {
                dp[j] = max (dp[j] , dp[i]+1);
            }
        }
        ans = max (ans , dp[i]);
        i++;
    }
    cout << ans << endl;
    return;
}

signed main()
{
    fast;
  ///  cin >> tc ;
    while (tc--)
    {
        cin >> n;
        solve_E();
    }

}
