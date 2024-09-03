#include <bits/stdc++.h>
#include <math.h>
#define endl '\n'
#define int long long
///#define double long double
#define mid (l+r)/2
using namespace std;

int n,m;

vector<int> t;
vector<int> z;
vector<int> y;


int balloons(int idx , int dur)
{
    idx--;
    int ti = t[idx];
    int zi = z[idx];
    int yi = y[idx];

    int a = ti*zi + yi;

    int numberOfBalloons = (zi)*(dur/a);

    int rem = dur % a;

    if (rem >= a-yi) numberOfBalloons += zi;
    else numberOfBalloons += (rem/ti);

    return numberOfBalloons;

}


void read()
{
    cin >> n  >> m ; /// m assisstants and n balloons
    t.clear();
    y.clear();
    z.clear();
    for (int i=1 ; i<=m ; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        t.push_back(a);
        z.push_back(b);
        y.push_back(c);

    }
}



int solve()
{
    int l=-1 ;
    int r = 5e10;

    int sum;

    while(l+1 < r)
    {
        sum = 0;
        int T = mid;
        for (int i=1 ; i<=m  ; i++)
        {
            int s = balloons(i,T);
            sum += s;
        }
        if (sum >= n)
        {
            r = T;
        }
        else l = T;
    }

    return r;
}


void printAns (int r)
{

    cout << r << endl;
    int sub;
    for (int i=1 ; i<=m ; i++)
    {
        sub = min (n , balloons(i,r));
        cout << sub << ' ';
        n -= sub;
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    read();

    int tim = solve();

    printAns(tim);

    return 0;
}
