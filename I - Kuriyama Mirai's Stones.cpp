#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n , m;
int arr[101010];
int copy_arr[101010];
int sums[101010];
int sums_copy[101010];
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n ;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
        copy_arr[i] = arr[i];
        sums[i] = sums[i-1] + arr[i];
    }
    copy_arr[0] = -LONG_MAX;
    sort(copy_arr , copy_arr+n+1);
    for (int i=1 ; i<=n ;i++)
    {
        sums_copy[i] = sums_copy[i-1] + copy_arr[i];
    }
    int type , l , r;
    cin >> m ;
    while (m--)
    {
        cin >> type;
        cin >> l >> r;
        l--;
        if (type == 1)
        {
            cout << sums[r] - sums[l] << endl;
        }
        else
        {
            cout << sums_copy[r] - sums_copy[l] << endl;
        }
    }
    return 0;
}
