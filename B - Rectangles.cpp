#include <bits/stdc++.h>
#include <queue>
using namespace std;


priority_queue < pair<int ,int> , vector <pair <int , int> > , less <pair <int , int> > > x_vals;
priority_queue < pair<int ,int> , vector <pair <int , int> > , less <pair <int , int> > > y_vals;
priority_queue < pair<int ,int> , vector <pair <int , int> > , greater <pair <int , int> >  > xs_vals;
priority_queue < pair<int ,int> , vector <pair <int , int> > , greater <pair <int ,int> > > ys_vals;

priority_queue < pair<int ,int> , vector <pair <int , int> > , less <pair <int , int> > > cl_vals1;

priority_queue < pair<int ,int> , vector <pair <int , int> > , greater <pair <int ,int> > > cl_vals2;

pair <int , int > cords;

int x,y;
int ans[100100];
int main()
{
    int n;
    int tests;
    cin >> tests;
    int dn=0;
    int m1,m2;
    while (tests > 0)
    {
        priority_queue < pair<int ,int> , vector <pair <int , int> > , less <pair <int , int> > > x_vals;
        priority_queue < pair<int ,int> , vector <pair <int , int> > , less <pair <int , int> > > y_vals;
        priority_queue < pair<int ,int> , vector <pair <int , int> > , greater <pair <int , int> >  > xs_vals;
        priority_queue < pair<int ,int> , vector <pair <int , int> > , greater <pair <int ,int> > > ys_vals;
        cin >> n ;
    for (int i=0 ; i< n ; i++)
    {

        for (int j=0 ; j < 4 ; j++)
        {
            cin >> x >> y;
            cords = make_pair(x,y);
            x_vals.push(cords);
           xs_vals.push(cords);
            cords = make_pair(y,x);
            y_vals.push(cords);
            ys_vals.push(cords);
        }

    }
    m1= y_vals.top().first - ys_vals.top().first;
    m2 =x_vals.top().first - xs_vals.top().first;
    ans[dn] = m1*m2;
    dn++;
    tests--;
    }
    for (int i=0 ; i<dn ; i++)
    {
        cout << ans[i]<<endl;
    }
    return 0;
}
