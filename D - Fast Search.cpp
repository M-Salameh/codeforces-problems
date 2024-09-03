#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;

int n;
int k;

vector<int> arr;
vector <int> ans;
void read()
{
    cin >> n ;
    arr.clear();
    ans.clear();
    for (int i=1 ; i<=n  ; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin() , arr.end());

}


void solve()
{
    int l,r;
    cin >> l >> r;
    int x = upper_bound(arr.begin() , arr.end() , r) - arr.begin() -1;
    int y = lower_bound(arr.begin() , arr.end() , l) - arr.begin();

    ans.push_back(max(x-y+1,0));

}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    read();
    cin >> k;
    while (k--)
    {
        solve();
    }

    for (auto i : ans) cout << i << ' ';
    cout << endl;

    return 0;
}
