#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int tc;
int n , c;

pair<int,int> min_p (pair<int,int> p1 , pair<int,int> p2)
{
    if (p1.first <= p2.first) return p1;
    return p2;
}


void solve()
{
    int arr[n+1];
    int min_cost[n+1]={0};
    pair<int,int> cost[n+1];
    int price[n+1]={0};
    int pos_sorted[n+1];
    for (int i=1 ;i<=n; i++)
    {
        cin >> arr[i];
        min_cost[i] = arr[i] + min (i , n-i+1);
        cost[i] = {min_cost[i],i};
    }
    sort (cost+1,cost+n+1);
    for (int i=1 ;i<=n ; i++)
    {
        price[i] = price[i-1] + cost[i].first;
        pos_sorted[cost[i].second]= i;
    }
    int ans=0;
    int remain;
    int pos;
    for (int i=1 ; i<=n ; i++)
    {
        remain = c-(arr[i]+i);
        if (remain>=0)
        {
            pos = upper_bound(price+1 , price+n+1 , remain) - (price+1);
            if (pos >= pos_sorted[i])
            {
                pos = upper_bound(price+1 , price+n+1 , remain+min_cost[i]) - (price+1);
            }
            else
            {
                pos++;
            }
            ans = max (ans , pos);
        }
    }
    cout << ans << endl;
    return;

}

/**
10
5 6
1 1 1 1 1
8 32
100 52 13 6 9 4 100 35
1 1
5
4 5
4 3 2 1
5 9
2 3 1 4 1
5 8
2 3 1 4 1
4 3
2 3 4 1
4 9
5 4 3 3
2 14
7 5
5 600000000
500000000 400000000 300000000 200000000 100000000


2
3
0
1
3
2
1
1
2
2

*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n >> c;
        solve();
    }
    return 0;
}
