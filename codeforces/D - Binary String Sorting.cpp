#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int tc,n;

string s;

void solve()
{
    int res = 1e18;
    int zeros_cnt = 0;
    int ones_cnt = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1') ones_cnt++;
    }
    int k;
    int now;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]=='0') zeros_cnt++;
        if(s[i]=='1') ones_cnt--;
        k = zeros_cnt + ones_cnt + (s[i]=='1')+(s[i+1]=='0');
        now = (n-k)*(1e12+1);
        if(s[i]>s[i+1]) now += 1e12;
        res = min(res,now);
    }
    cout << res << endl;
}

signed main()
{
    fast;
	cin >> tc;
	while(tc--)
    {
		cin >> s;
		n = s.size();
		if(n==1)
        {
			cout << 0 << endl;
			continue;
		}
		solve();
	}
	return 0;
}
