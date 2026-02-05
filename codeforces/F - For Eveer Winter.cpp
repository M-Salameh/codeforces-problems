#include<bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int degree[202],n,m;
int tc=1;
int ans;
int main()
{
    fast;
	cin >> tc;
	while(tc--)
	{
		memset(degree , 0 , sizeof(degree));
		cin >> n >> m;
		for(int i=1 ; i <= m ; i++)
		{
			int u,v;
			cin >> u >> v;
			degree[u]++;
			degree[v]++;
		}
		ans = 0;
		for(int i=1 ; i <= n ; i++)
		{
		    ans += (degree[i]==1);
		}
		int x = n-ans-1;
		int y = ans/x;
		cout << x << ' ' << y << endl;
	}
}
