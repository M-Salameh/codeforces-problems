#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,m;
ll a[1e6+9];
ll q;
pair < pair <ll ,ll>  , pair <ll, ll> > point[1e6+9];
ll k[1e6+9];
map <ll , ll> m;
void Read()
{
    cin >> n  >> m;
    for (ll i=1 ; i<=m ; i++)
    {
        cin >> a[i];
    }
    cin >>  q;
    pair <ll , ll > ps;
    pair <ll , ll > pe ;
    pair < pair <ll ,ll> , pair < ll , ll > > p;
    ll xs , ys , xe,ye;
    for (ll i=1; i<=1 ; i++)
    {
        cin >> xs >> ys >> xe >> ye >> k[i];
        ps = make_pair(xs,ys);
        pe = make_pair(xe,ye);
        p = make_pair(ps , pe);
        point[i]=p;
    }



}

int main()
{

    return 0;
}
