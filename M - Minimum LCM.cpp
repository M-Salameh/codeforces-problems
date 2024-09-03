#include <bits/stdc++.h>
#include <math.h>
#define endl '\n'
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int tc,n,x;
	cin>>tc;
	while(tc--)
	{
		cin>>n;
		x=1;
		for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
		{
			x=n/i;
			break;
		}
		cout << x << ' ' << n - x <<endl;
	}
	return 0;
}
