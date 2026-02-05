#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define Pb push_back
#define S second
#define F first
#define Fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define Endl '\n'
#define V vector<int>
#define Vv vector<vector<ll>>
#define Vp vector<pair<ll,ll>>
#define No cout << "NO" << Endl
#define Yes cout << "YES" << Endl
#define endl '\n'

const int NN = 2e5 + 6;
const int inf = 2e18;

int n;



signed main()
{
    int Tc=1;
    Fastio;
    cin>>Tc;
    while(Tc--)
    {
        int x = 10;
        cin >> x;
        int ans = 0;
        while (x > 0)
        {
            for (int i=61 ; i>=0 ; i--)
            {
                if (x == 0) break;
                int k = (1LL << i);
                if (x - (k-1) == 0)
                {
                    x-=(k-1);
                }
                else if (x & (k) )
                {
                    x -= (k-1);
                    ans ++ ;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
