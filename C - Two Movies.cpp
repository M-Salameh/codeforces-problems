#include <bits/stdc++.h>
///#define int long long
#define endl '\n'

using namespace std;

const int inf = 2e18+8;
const int NN = 2e5+5;
int n , tc=1;

int arr[NN];
int brr[NN];

void solve()
{
    int sum1 = 0 , sum2 = 0;

    for (int i=1 ; i<=n ; i++)
    {
        if (arr[i]==1 and brr[i]<1) sum1 += 1;

        if (arr[i]<1 and brr[i]==1) sum2 += 1;
    }

    for (int i=1 ; i<=n ; i++)
    {
        if (arr[i] != brr[i]) continue;
        int x = arr[i];

        if (x == 1)
        {
            if (sum1 < sum2) sum1 += 1;
            else sum2 += 1;
        }
        if (x == -1)
        {
            if (sum1 >= sum2) sum1 -= 1;
            else sum2 -= 1;
        }
    }

    cout << min(sum1 , sum2) << endl;

}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        for (int i=1; i<=n ; i++)
        {
            cin >> arr[i];
        }
        for (int i=1 ; i<=n ; i++)
        {
            cin >> brr[i];
        }

        solve();

    }

    return 0;
}
