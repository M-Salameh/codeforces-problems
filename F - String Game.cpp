#include <bits/stdc++.h>
#include <math.h>
#define endl '\n'
//#define int long long
#define double long double
#define mid (l+r)/2.00
using namespace std;
string t, p;
vector<int> arr;
int n,m;


void read()
{
    cin >> t;
    cin >> p;
    n = t.size();
    for (int i=1 ; i<=n ; i++)
    {
        int x ;
        cin >> x ;
        arr.push_back(x);
    }
}

bool contains(string& s)
{
    int i=0 , j=0;
    while (i<s.size() and j<p.size())
    {
        if (s[i]==p[j])
        {
            i++;
            j++;
        }
        else i++;
    }

    return j>=p.size();
}


string deleteChars(int midd , string& s)
{
    for(int i=0 ; i<midd ; i++) s[arr[i]-1] = '?';
    string str = "";
    for(int i=0 ; i<n ; i++)
    {
        if(s[i] != '?') str += s[i];
    }
    return str;
}


void solve()
{
    int l = 0;
    int r = n;
    string s;
    while(l < r)
    {
        s = t;

        string str = deleteChars(mid , s);

        if (contains(str))
        {
            l = mid+1;
            ///cout << "CC" <<endl;
        }
        else r = mid;
    }

    cout << l-1 << endl;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    read();

    solve();

    return 0;
}
