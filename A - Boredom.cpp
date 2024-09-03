#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll x;
ll n;
int main()
{
    cin >> n;
    vector <ll> cnt(200009);
    vector<ll>  ans(200009);
    ll mx = -(1e9);
    for (ll i=1 ;i<=n ;i++)
    {
        cin >> x;
        cnt[x]++;
        mx=max(mx,x);
    }
    ans[0]=0;
    ans[1]=cnt[1];
    for (ll i=2 ; i<=mx; i++)
    {
        ans[i] = max(ans[i-1] , ans[i-2] + i*cnt[i]);
    }
    cout << ans[mx]<<endl;
    return 0;
}
