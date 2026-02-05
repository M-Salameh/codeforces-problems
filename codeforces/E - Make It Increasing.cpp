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

using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 5e15+6;
int n,k;

/**
15 2
11 12 13 50 14 15 16 17 18 19 20 21 22 23 100
1 15
ans = 10

15 2
10 12 13 50 19 20 21 22 23 24 25 26 27 28 100
1 15
ans = 1
*/

vector<int> arr;
vector<int> indexs;
bool chck()
{
    for (int i=1 ; i<=k ; i++)
    {
        if (arr[indexs[i+1]] < arr[indexs[i]])
        {
            cout << -1 << endl;
            return false;
        }
    }
    return true;
}

int calc (int st , int en)
{
    st++;
    en--;
    int temp = 0;
    multiset<int> ms;
    for (int i=st ; i<=en ; i++)
    {
        bool z = (arr[i]<arr[st-1] or arr[i]>arr[en+1]);
        ///temp += z;
        if (z) continue;
        auto it = ms.upper_bound(arr[i]);
        if (it == ms.end())
        {
            ms.insert(arr[i]);
            continue;
        }
        ms.erase(it);
        ms.insert(arr[i]);
    }
    /**
   `cout << "******************************************************"<<endl;
    cout << "size for start = " << st-1 << " and end = " << en+1 << endl;
    cout << ms.size() << endl;
    cout << "ms now : " << endl;
    for (auto i : ms) cout << i << " ";
    cout << endl;
    cout << "******************************************************"<<endl;
    */

    ///int res = (en+1)-(st-1)-ms.size()-1;
   /// res -= temp;
   /// return res;
   return ms.size();
}

void solve()
{
    int ans = 0;
    for (int i=0 ; i<=k ; i++)
    {
        int st = indexs[i];
        int en = indexs[i+1];
        ans += en-st-1-calc(st , en);
    }


    ///cout << "ans = ";
    cout << ans << endl;
}



#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
signed main()
{
    fast;
    ///cin >> tc;
    while(tc--)
    {
        cin >> n >> k;
        arr = vector<int> (n+5,0);
        indexs = vector<int> (k+5,0);

        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
            arr[i] -= i;
        }
        arr[n+1] = inf;
        arr[0] = -inf;

        for (int i=1 ; i<=k; i++)
        {
            cin >> indexs[i];
        }
        indexs[0]=0;
        indexs[k+1] = n+1;


        bool x = chck();
        if (x) solve();

    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
