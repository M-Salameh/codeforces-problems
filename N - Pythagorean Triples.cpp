#include <bits/stdc++.h>
#define int long long
#include <math.h>
#define endl '\n'
using namespace std;

int tc=1;
int n;
int x;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ///cin >> tc ;
    while (tc--)
    {
        cin>>n;
        x = n*n;
        if (n<=2) cout<<-1<<endl;
        else if (n%2) cout<< (x-1)/2 << ' ' << (x+1)/2 << endl;
        else cout << (x-4)/4 << ' ' << (x+4)/4 << endl;

    }
    return 0;
}
