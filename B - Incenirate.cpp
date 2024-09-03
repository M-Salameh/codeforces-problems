#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int tc , n , k;

void solve()
{
    cin>>n>>k;
    pair<int,int> arr [n+1];
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i].second; ///h
    }
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i].first; ///p
    }
    sort(arr+1,arr+n+1); /// by p
    int i=1;
    int temp=0;
    while(k>0 && i<=n)
    {
        temp += k;
        while(arr[i].second <=temp && i<=n) i++;
        k -= arr[i].first;
    }
    if(i>n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return;
}

signed main()
{
    fast_io;
	cin>>tc;
	while(tc--)
	{
	    solve();
	}
	return 0;
}
