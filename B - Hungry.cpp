#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define V vector<int>
#define Vv vector<vector<int>>
#define Vp vector<pair<int, int>>
#define No cout << "NO" << Endl
#define Yes cout << "YES" << Endl
#define ll long long
#define Pb push_back
#define S second
#define F first
using namespace std;

int modo=1e9+7;

int arr[100100];
int pref[100100];
int n,q;
int tc=1;

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    //cin>>tc;
    while(tc--)
    {
        pref[0] = 0;
        cin >> n;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
            pref[i] = pref[i-1] + arr[i];
        }
        cin >> q;
        while(q--)
        {
            int x,y,m;
            cin >> x >> y >> m;

            cout << min (y+pref[m] , max(x,pref[n])) << endl;
        }
    }
    return 0;
}
