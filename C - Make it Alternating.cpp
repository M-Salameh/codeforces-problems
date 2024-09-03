#include <bits/stdc++.h>
#include <math.h>
#define int long long
#define endl '\n'
#include <string>
#define MOD 998244353
using namespace std;

int tc=1;

int n;

void solve()
{
    string s;
	cin >> s;
	int dist=0,tot=1;
	s += "$";

	int cnt=1;

	for(int i=1 ; i < s.size() ; i++)
    {
		if(s[i] == s[i-1])
        {
            cnt++;
            continue;
        }

        dist += (cnt-1);
        tot = (tot*cnt) % MOD;
        cnt = 1;
	}

	for(int i=2 ; i<=dist ; i++)
	{
	    tot = (tot*i) % MOD;
	}
    cout << dist << ' ' << tot << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> tc;

    while(tc--)
    {
       /// cin >> n;
        solve();
    }

    return 0;
}
