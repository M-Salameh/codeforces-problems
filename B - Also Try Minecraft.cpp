#include <bits/stdc++.h>
#include <math.h>
#define ll long long
using namespace std;

ll n,m;
ll a[900900];
vector < pair <ll , ll > > quests;
vector < ll > diff_forwards;
vector <ll > diff_backwords;
vector <ll> ans;
void ReadandStore()
{
     cin >> n >> m ;
    cin >> a[0];
    diff_backwords.push_back(0);
    diff_forwards.push_back(0);
    ll cmp=0;
    for (ll i = 1 ; i<n ; i++)
    {
        cin >> a[i];
        diff_forwards.push_back(max(cmp , a[i-1]-a[i]) + diff_forwards[i-1]);
        diff_backwords.push_back(max(cmp , a[i]-a[i-1]) + diff_backwords[i-1]);
    }
    int s ,t;
    pair <ll , ll > p;
    for (ll i=0 ;i<m; i++)
    {
        cin >> s >> t ;
        p = make_pair(s,t);
        quests.push_back(p);
    }
}


void solve()
{
    pair < ll , ll > p;
    for (int i=0 ; i< m ; i++)
    {
        p=quests[i];
        if (p.first < p.second)
        {
            ans.push_back (diff_forwards[p.second-1] - diff_forwards[p.first-1]);
        }
        else{
            ans.push_back(diff_backwords[p.first-1] - diff_backwords[p.second-1]);
        }
    }
}

int main()
{

    ReadandStore();
    solve();
    for (ll i=0 ;i<m;i++)
    {
        cout << ans[i] <<endl;
    }

    return 0;
}
