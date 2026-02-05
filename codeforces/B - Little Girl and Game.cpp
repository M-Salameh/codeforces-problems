#include <bits/stdc++.h>
#include <string>
#include <cstring>
using namespace std;

string s;
int a[100100];
map <char , int>m;

int main()
{
    cin>>s;
    int sz = s.size();
    if (!sz)
    {
        cout << "First\n";
    }
    else
    {

    for (int i=0 ; i<sz ; i++)
    {
        m[s[i]]++;
    }
    int coun = 0;
    for (char i='a' ; i<='z' ; i++)
    {
        if (m[i]%2 != 0)
        {
            coun++;
        }
    }

    if (coun %2 == 0 && coun!=0)
    {
        cout<<"Second\n";
    }
    else
    {
        cout << "First\n";
    }
    }
    return 0;
}
