#include <bits/stdc++.h>
#define ld long double
using namespace std;

ld r,x,y,x_n,y_n;
ld dist;
ld ans;
int main()
{
    cin >> r >> x >> y >> x_n >> y_n ;
    r*=2;
    dist = sqrt((x-x_n)*(x-x_n)+(y-y_n)*(y-y_n));
    ans = ceil(dist/r);
    cout <<ans <<'\n';
    return 0;
}
