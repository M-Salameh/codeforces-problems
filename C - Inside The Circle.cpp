#include <bits/stdc++.h>
#define endl '\n'
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int tc=1;
int n;
const int NN = 1e5+2;

struct point
{
    int x;
    int y;
    point(int a=0,int b=0)
    {
        x=a;
        y=b;
    }
};
struct Node
{
    bool push = false;
    int ans=0;
    int sum=0;

};

struct circle
{
    point center;
    int radius;
};

point S,E;
circle big_circle;

point ReadPoint(int a,int b)
{
    point x;
    x.x=a;
    x.y=b;
}

pair<int,int> ReadCircle(int r , int x , int y)
{
    return{0,0};
}




Node segt[4*NN];

void reset()
{
    S={0,0};
    E={0,0};
    big_circle={E,0};
    for (int i=0 ; i<4*NN ; i++)
    {
        segt[i] = {false,0,0};
    }
}

signed main()
{
    fast;
    cin >> tc;
    while (tc--)
    {
        reset();
        int sx,sy,ex,ey;
        cin >> sx >> sy >> ex >> ey;
        S = ReadPoint(sx,sy);
        E = ReadPoint(ex,ey);
        cin >> n;
    }
    return 0;
}
