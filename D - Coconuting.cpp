#include <bits/stdc++.h>
#define int long long
#define j3 j*j*j
#define endl '\n'
using namespace std;

int tc = 1;
int n;
map<int,int> freq;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        freq.clear();
        cin >> n;
        int ans = 0;
        for (int i=1 ; i<=n ; i++)
        {
            int x;
            cin >> x;
            for (int j=2 ; j3 <= x ; j++)
            {
                while(x%(j3) == 0)
                {
                    x /= j3;
                }
            }
            ans += freq[x];
            freq[x]++;
        }
        cout << ans << endl;
    }

    return 0;
}
