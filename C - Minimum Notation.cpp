#include <bits/stdc++.h>
#define ll long long
#define inf int (1e10+1)
#define mxsz int (1e5+5)
#define mid (l+r)/2
using namespace std;

using namespace std;

int main()
{
    int tc;
    string s="";
    cin >> tc;
    char cmp = 'a';
    while (tc--)
    {
        cin >> s;
        for (int i=s.size()-1 ; i>=0 ; i--)
        {
            cmp = min (cmp , s[i]);
            if(s[i] > cmp && s[i]!='9')
            {
                s[i] = s[i] + '1'-'0';
            }
        }
        sort (s.begin() , s.end());
        cout << s <<'\n';
        s="";
        cmp = 'a';
    }

    return 0;
}
