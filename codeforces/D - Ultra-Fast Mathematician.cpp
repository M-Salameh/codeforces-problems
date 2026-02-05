#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
using namespace std;

int tc=1;
int n;
int ans;

signed main()
{
    fast;
    //cin >> tc;
    while(tc--)
    {
        string s1,s2;
        cin >> s1 >> s2;
        string s3="";
        for (int i=0 ; i<s1.size() ;i++)
        {
            if (s1[i] != s2[i])
            {
                s3+="1";
            }
            else s3+="0"
        }
        cout << s3 << endl;
    }
    return 0;
}
