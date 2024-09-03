#include <bits/stdc++.h>
#define ll long long
#define modo int(1e9+7)
#define NN int(1e6+6)
#define endl '\n'
using namespace std;

ll fac[100100];
ll pre[100100];
ll ans[100100];
int tc=1;

ll div(ll n)
{
	ll k=0;
	for (int i=1 ;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			k++;
			if (n/i != i) k++;
		}
	}
	k--;
	return k;
}

ll power(int a , int b)
{
    if (b==0) return 1;
    if (b==1) return a;
    ll res = power(a,b/2) % modo;
    res = (res*res) % modo;
    if (b&1) res = (a*res)%modo;
    return res%modo;
}

void solve()
{
    int t;
    fac[0]=1;
    for(int i=1;i<=100000;i++)
    {
        fac[i]=(fac[i-1]*i)%modo;
    }

    pre[0]=1;
    for(int i=1;i<=100100;i++)
    {
        pre[i]=(pre[i-1]+fac[i])%modo;
    }

    ans[1]=0;ans[2]=1;
    for(int n=3;n<=100000;n++)
    {
        ans[n]=(n*ans[n-1])%modo;
        ll k = div(n);
        ll x = (k*fac[n])%modo;
        x=(x*power(2,modo-2))%modo;
        ans[n]=(ans[n]+x)%modo;
    }
}

int main()
{
    solve();
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>tc;
    while(tc--)
    {
        ll n;
        cin>>n;
        cout<<ans[n]<<endl;
    }

    return 0;
}
