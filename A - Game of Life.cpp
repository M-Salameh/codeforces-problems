#include <bits/stdc++.h>
#include <string>
#define fori(a,b) for (int i=a;i<=b;i++)
using namespace std;

int tc,n,m;
string s,w;
void solve()
{
    cin >> s;
    s = "0"+s+"0";
    w=s;
    while (m--)
    {
        fori(1,n)
        {
            if(s[i-1] != s[i+1])
            {
                w[i]='1';
            }
        }
        if (s==w)break;
        s=w;
    }
    s = s.substr(1,s.size()-2);
    cout << s << '\n';
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m ;
        solve();
        s="";
        w="";
    }
    return 0;
}
