#include <bits/stdc++.h>
#define intt long long
#define endl '\n'
#include <string>
using namespace std;
intt n;
string s;
int tc;

void solve()
{
    cin >> n ;
    cin >> s ;
    s = "0"+s;
    intt ans=-1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]!=s[i-1])ans++;
    }
    cout << ans*(ans>0) <<endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc ;
    while (tc--)
    {
        solve();
        s="";
    }
    return 0;
}
