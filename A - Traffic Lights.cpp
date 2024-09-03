#include <bits/stdc++.h>
#include <math.h>
#include <string>
#define endl '\n'
#define int long long
#define double long double
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536

using namespace std;
using ll = long long ;


signed main()
{
    fast;
    int tc=1;
    cin>>tc;
    while(tc--)
    {
        int x,g,y,r;
        cin>>x>>g>>y>>r;
        int sum = g+y+r;
        int diff = x%sum;

        if(diff<g) cout<<"GREEN"<<endl;

        else if(diff<y+g) cout<<"YELLOW"<< endl;

        else cout <<"RED" <<endl;
    }

    return 0;
}

