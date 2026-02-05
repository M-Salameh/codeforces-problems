#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n;
int tc;
int w[404040];
///int alice[404040];
///int bob[404040];

void reset()
{
    memset(w , 0 , sizeof(w));
    ///memset(alice , 0 , sizeof(alice));
    ///memset(bob , 0 , sizeof(bob));
}

void solve()
{
    reset();
    for (int i=1 ; i<=n ; i++)
    {
        cin >> w[i];
    }
    int ans=0;
    int alice=w[1];
    int bob=w[n];
    int l=1 , r=n ;
    int alice_iter=1;
    int bob_iter=1;
    while (l < r)
    {
        if (alice == bob)
        {
            ans = ans + alice_iter + bob_iter;
            alice_iter=1;
            bob_iter=1;
            l++;
            r--;
            if (l<r)
            {
                bob+=w[r];
                alice+=w[l];
            }

        }
        if (alice < bob)
        {
            alice_iter++;
            l++;
            if(l<r) alice+=w[l];
        }
        if (bob < alice)
        {
            bob_iter++;
            r--;
            if (l<r) bob+=w[r];
        }
    }
    /**
    int j=n+1;
    for (int i=1 ;i<=n ; i++)
    {
        alice[i] = alice[i-1] + w[i];
        bob[j-i] = bob[j+1-i] + w[j-i];
    }

    reverse(bob+1 , bob+n+1);
    for (int i=1 ; i<=(n/2) ; i++)
    {
        x = lower_bound(alice+1 , alice+n+1 , bob[i]) - alice;
        if (alice[x] == bob[i])
        {
            alic_eat+=x;
            bob_eat=i;
        }
    }*/
    cout << ans << endl;

}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc ;
    while (tc--)
    {
        cin >> n ;
        solve();
    }
    return 0;
}
