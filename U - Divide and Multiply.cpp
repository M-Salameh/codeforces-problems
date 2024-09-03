#include <bits/stdc++.h>
#define int long long
#include <math.h>
#define endl '\n'
using namespace std;

int tc=1;
int n;


int mypower (int x , int y)
{
    if (y==0) return 1;
    if (y==1) return x;
    if (y&1) return x*mypower(x,y/2)*mypower(x,y/2);
    return mypower(x,y/2)*mypower(x,y/2);
}

void solve()
{
    int arr[n+1];
    int sum = 0;
    int c = 0;
    int mx = 0;
    for (int i = 1; i <= n ; i++)
    {
        cin>>arr[i];
        if (arr[i] % 2 == 0)
        {
            while (arr[i] % 2 == 0)
            {
                c++;
                arr[i] /=  2 ;
            }
        }
        sum +=arr[i];
        mx = max(mx, arr[i]);
    }
    int get_big = mx*mypower(2,c);
    int ans = sum + get_big - mx;
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc ;
    while (tc--)
    {
        cin >>n;
        solve();
    }
    return 0;
}
