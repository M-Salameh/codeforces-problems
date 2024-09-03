#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
using namespace std;

int tc=1;

long long process_equal(string s1 , string s2)
{
    int n = s1.size() - 1;
    reverse(s1.begin() , s1.end());
    reverse(s2.begin() , s2.end());

    bool nine_granted = false;
    long long ans = 0;
    for (int i = n ; i>-1 ; i--)
    {
        if (s1[i] < s2[i] and !nine_granted)
        {
            nine_granted = true;
            ans += (s2[i] - s1[i]);
        }
        else if (s1[i] > s2[i] and !nine_granted)
        {
            nine_granted = true;
            ans += (s1[i] - s2[i]);
        }
        else if (s1[i] > s2[i] and nine_granted)
        {
            ans += 9;
        }
        else if (s1[i] <= s2[i] and nine_granted)
        {
            ans += 9;
        }
    }
    return ans;

}


void solve()
{
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    long long ans = 0;
    if (n == m)
    {
        ans = process_equal(s1,s2);
        cout << ans << endl;
        return;
    }

    if (m > n)
    {
        swap (s1 , s2);
    }
    n = s1.size() - 1;
    ans += (s1[0]-'0');
    ans += (n*9);
    cout << ans <<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> tc;
    while(tc--)
    {
        solve();
    }

    return 0;
}
