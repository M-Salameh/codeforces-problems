#include<bits/stdc++.h>
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0) ;cout.tie(0);
#define endl '\n'
using namespace std;



void print(multiset<int> ms)
{
    for (auto i : ms)
    {
        cout << i << ' ' ;
    }
    cout <<"\n******************"<<endl;
}

int n,k;

void solve()
{
    int arr[n+1];
    multiset<int> ms;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
    }
    int l=1,r=1;
    int ans=0;
    int diff;
    for (int r=1;r<=n ; r++)
    {
        ms.insert(arr[r]);
        diff = *--ms.end()-*ms.begin();
        while(diff > k)
        {
            ms.erase(ms.find(arr[l]));
            l++;
            diff = *--ms.end()-*ms.begin();
        }
        ans += (r-l+1);
    }
    cout << ans << endl;
}

signed main()
{
    int x =1;
    while (x < 7)
    {
        x++;
        cout << x << endl;
    }
    x=1;
    while (x < 7)
    {
        cout << x << endl;
        x++;
    }
    /**fast;
    cin >> n >> k;
    solve();*/
    return 0;
}
