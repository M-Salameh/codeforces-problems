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
const int NN = 1e7+2;

int pw(int x, int y)
{
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x)%modo;
        y = (y >> 1)%modo;
        x = (x * x)%modo;
    }
    return res ;
}

int pre[NN];

void pre_clac()
{
    pre[0] = 0;
    pre[1] = 1;
    for (int i=1 ; i<=NN ; i++)
    {
        for (int j = i+i ; j<=NN ; j+=i)
        {
            pre[j] = i;
        }
    }
}

int n;
int a[NN];
int b[NN];

void solve()
{
    int cnt = 0;
    for (int i=1 ; i<=n ; i++)
    {
        while (a[i] != b[i])
        {
            if (a[i] > b[i])
            {
                a[i] = pre[a[i]];
            }
            else
            {
                b[i] = pre[b[i]];
            }
            cnt++;
        }
    }

    cout << cnt << endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int Tc=1;
    pre_clac();

    cin>>Tc;

    while(Tc--)
    {
        cin >> n;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> a[i];
        }
        for (int i=1 ; i<=n ; i++)
        {
            cin >> b[i];
        }

        solve();
    }
    return 0;
}
