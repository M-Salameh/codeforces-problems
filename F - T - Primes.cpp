#include <bits/stdc++.h>
#include <math.h>
#define int long long
#define endl '\n'
#include <string>
using namespace std;

int tc=1;

int n;

bool prime[5005005];

void seive()
{
    memset(prime , true , sizeof(prime));

    prime[1] = false;

    for (int i=2 ; i <= 2+1e6 ; i++)
    {
        if (prime[i])
        {
            for (int j=i+i ; j<=2+1e6 ; j+=i)
            {
                prime[j] = false;
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    seive();
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        int y = sqrt(x);
        int u = y*y;
        if (u==x and prime[y]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}
