#include<bits/stdc++.h>
#define endl '\n'
#define MOD 10000007
using namespace std;
int a, b, c, d, e, f;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, cases;
    cin >> cases;
    for (int caseno = 1; caseno <= cases; ++caseno)
    {
        cin>>a>>b>>c>>d>>e>>f>>n;
        unsigned long long ans[n+7];
        ans[0]=a;
        ans[1]=b;
        ans[2]=c;
        ans[3]=d;
        ans[4]=e;
        ans[5]=f;
        for (int i=6 ;i<=n ; i++)
        {
            ans[i] = (ans[i-1] + ans[i-2] + ans[i-3] + ans[i-4] + ans[i-5] + ans[i-6])%MOD;
            if (ans[i]>=MOD)
            {
                ans[i]-=MOD;
            }
        }
        cout << "Case " << caseno <<": " << ans[n]%MOD << endl;
    }
    return 0;
}
