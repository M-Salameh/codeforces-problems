#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int NN =1e6+9;
ll n;
ll x[NN];
ll h[NN];
ll ans;

int main()
{
	cin >> n ;
	for (ll i=1 ; i<=n ; i++)
	{
		cin >> x[i] >> h[i];
	}
	if (n<=2)
	{
		cout << n << endl;
		return 0;
	}
	for (ll i=2; i<n ; i++)
	{
		if (h[i] < x[i]-x[i-1])
		{
			ans++;
		}
		else if (h[i] < x[i+1]-x[i])
		{
			ans++;
			x[i]+=h[i];
		}
	}
	ans+=2;
	cout << ans <<endl;
	
	
    return 0;
}
