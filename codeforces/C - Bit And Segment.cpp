#include <bits/stdc++.h>
#define int long long
#define mid (l+r)/2
#define lc 2*node
#define rc 2*node+1
#define endl '\n'

using namespace std;

const int NN = 1e5+5;
const int inf = 1e6+5;
int tc=1;
int n;
int arr[NN];
int segt[4*NN];

int mergee(int& a , int& b)
{
    return a&b;
}

void build(int node=1 , int l=1 , int r=n)
{
    if (l > r) return;
    if (l==r)
    {
        segt[node] = arr[r];
        return;
    }
    build(lc , l , mid);
    build(rc , mid+1 , r);
    segt[node] = mergee(segt[lc] , segt[rc]);
    return;
}


int query (int node , int l ,int r , int st , int en , int one)
{
    if (l>r or st>r or en<l or en<st) return one;
    if (l>=st and en>=r)
    {
        return segt[node];
    }
    int p1 = query(lc , l , mid , st , en , one);
    int p2 = query(rc , mid+1 , r , st , en , one) ;
    return mergee(p1,p2);
}

long long ans = 0;

void solve(int idx)
{
    int l=1 , r=idx;

    int lans = idx, rans = idx;

    while (l <= r)
    {
        int x = query(1,1,n, mid , idx , arr[idx]);
        //cout << "query(" << mid << "," << idx << ") = " << x << " , and elem = " << arr[idx] << endl;
        if (x == arr[idx])
        {
            lans = mid;
            r = mid-1;
        }
        else
        {
            l = mid + 1;
        }
    }

    //cout << "*********************" << endl;
    l = idx , r = n;
    while (l <= r)
    {
        int x = query(1,1,n, idx , mid , arr[idx]);
        //cout << "query(" << mid << "," << idx << ") = " << x << " , and elem = " << arr[idx] << endl;
        if (x == arr[idx])
        {
            rans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    //cout << "L = " << lans << "  , R = " << rans << endl;

    ans = ((rans-idx+1)*(idx-lans+1));
    cout << ans << ' ';

}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> tc ;
    while (tc--)
    {
        cin >> n;
        for (int i=1 ; i<=n ;i++) cin >> arr[i];

        build();

        for (int i=1 ; i<=n ; i++) solve(i);

        cout << endl;
    }
    return 0;
}
