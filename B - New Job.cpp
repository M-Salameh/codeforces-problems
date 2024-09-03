#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mem memset(vis,0,sizeof vis);
#define pb push_back
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

int n,m;

signed main()
{
    fast;
    int tc=1;
    cin>>tc;
    while(tc--)
    {
        cin >> n >> m ;
        if(m==1)
        {
            cout<<n<<endl;
            continue;
        }
        int k=1,ans=0 ;
        while(n>0)
        {
            if(k<=m)
            {
                n-=k;
                ans++;
                k+=k;
            }
            else
            {
                n-=m;
                ans++;
                k+=m;
            }
        }

        cout << ans <<endl;

    }
    return 0;
}
