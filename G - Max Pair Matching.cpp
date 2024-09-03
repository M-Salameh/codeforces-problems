#include <bits/stdc++.h>
#define int long long
///#define endl '\n'

using namespace std;

const int NN = 3e5+5;
const int MOD = 1000000007;
int tc = 1;
int n;

int arr[NN];
int sum;


signed main()
{
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n;
        sum = 0;
        for (int i=1 ; i<=2*n ; i++)
        {
            int x , y;
            cin >> x >> y;
            sum += max(x,y);
            arr[i] = x+y;
        }
        sort(arr+1 , arr+n*2+1);
        for (int i=1 ; i <= n ; i++) sum -= arr[i];
        cout << sum << endl;
    }

    return 0;
}
