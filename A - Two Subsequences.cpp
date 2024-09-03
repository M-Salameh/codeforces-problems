#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;


/**
not accepted !
*/
signed main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc;
    cin >> tc ;
    string s;
    while (tc--)
    {
        cin >> s ;
        char cmp = char('z'+1);
        int pos1;
        for (int i=0;i<s.size();i++)
        {
            if (s[i] < cmp)
            {
                cmp = s[i];
                pos1=i;
            }
        }
        string a="",b="";
        for (int i=0;i<s.size();i++)
        {
            if (i==pos1)
            {
                a+=s[i];
            }
            else
            {
                b+=s[i];
            }
        }
        cout << a << ' ' << b << endl;
    }

    return 0;
}
