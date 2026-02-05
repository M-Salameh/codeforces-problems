//https://codeforces.com/group/9QrbarK7qH/contest/503465/problem/C
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int mod = 1e9+7;
const int inf = 1e15+8;
const int NN = 100100;
const int Level = 25;
int tc=1;
int n,k;
int arr[NN];

void solve()
{
   int mini = inf;
   int maxi = -inf;
   vector<int> pref(n+1); pref[0] = inf;
   vector<int> suff(n+2); suff[n+1] = inf;
   for (int i=1 ; i<=n ; i++)
   {
       cin >> arr[i];
       pref[i] = min(arr[i] , pref[i-1]);
       if (arr[i] >= maxi ) maxi = arr[i];
       if (arr[i] < mini) mini = arr[i];
   }
   if (k == 1)
   {
       cout << mini << endl;
       return;
   }
   if (k > 2)
   {
       cout << maxi << endl;
       return;
   }


   for (int i=n ; i>=1 ; i--) suff[i] = min(suff[i+1],arr[i]);
   int ans = -inf;

   for (int i=1 ; i<=n ; i++)
   {
       ans = max (ans , max(pref[i] , suff[i]));
   }
   cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ///cin >> tc;
    while(tc--)
    {
        cin >> n >> k;
        solve();
    }
    return 0;
}

