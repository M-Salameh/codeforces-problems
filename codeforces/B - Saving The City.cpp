#include <bits/stdc++.h>
#include <string>
#define int long long
#define endl '\n'
using namespace std;

int tc;
int a,b;

void print (vector<int> a, int p[] , int sz)
{
    for (auto i:a) cout << i <<' ';
    cout << endl<<endl;
    for (int i=1 ;i<=sz ; i++) cout << p[i] <<' ';
    cout << endl << endl;
    return;
}

vector<int> process(string s)
{
    vector<int> ones;
    int fi = -1 , la = -3 ;
    for (int i=0 ; i<s.size() ; i++)
    {
        if (s[i]=='1')
        {
            fi = i;
            break;
        }
    }
    for (int i=s.size()-1 ; i>-1; i--)
    {
        if (s[i]=='1')
        {
            la = i;
            break;
        }
    }
    if (fi < 0) return ones;
    if (fi == la)
    {
        ones.push_back(0);
        return ones;
    }
    string s2="";
    bool op = true;
    for (int i=fi ; i<=la ; i++)
    {
        if (s[i]=='1' && op)
        {
            s2+="1";
            op = false;
        }
        if (s[i] == '0')
        {
            s2+="0";
            op = true;
        }
    }

    for (int i=0 ;i<s2.size();i++)
    {
        if (s2[i] == '1')
        {
            ones.push_back(i+1);
        }
    }

    return ones;
}

void solve()
{
    string s;
    cin >> s ;
    vector<int> mines_pos;
    mines_pos = process (s);
    int n = mines_pos.size();
    if (n<=1) cout << a*n << endl;
    else
    {
        int dist=0;
        int ans = a;
        for (int i=1 ; i<n ; i++)
        {
            dist = mines_pos[i] - mines_pos[i-1]-1;
            ans+=min(a,b*dist);
        }
        cout << ans << endl;
    }
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> a >> b ;
        solve();
    }
	return 0;
}


/**
1
5 4
0000001111111010101010101011111101
*/
