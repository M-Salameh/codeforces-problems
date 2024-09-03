#include <bits/stdc++.h>
#define ll long long
using namespace std;

set <ll> graph[100100];
vector <ll> parent;
vector <bool> visited (100100,false);
ll n , m;
string bus = "bus topology";
string star = "star topology";
string ring = "ring topology";
string unknown = "unknown topology";
ll x , y;
ll fi;
ll en;
ll one_c;
ll two_c;
ll rr=0;
ll sz[100100];
void traverse (ll a)
{
    if (m==n-1)
    {
        if (one_c == 2 && two_c == n-2)
        {
            cout << bus << endl;
            return;
        }
        else
        {
            for (auto it=graph[rr].begin() ; it!=graph[rr].end() ; it++)
            {
                if (graph[*it].size() > 1)
                {
                    cout << unknown <<endl;
                    return;
                }
                cout << star <<endl;
                return;
            }
        }
    }
    else
    {
        cout << two_c <<endl;
        for (ll j=1 ; j<=4 ; j++){
        for (auto i:graph[j])cout << i <<"  ";
        cout << endl;}
        if (two_c == n && m==n)
        {
            cout << ring <<endl;
            return;
        }
        else
        {
            cout <<unknown <<endl;
            return;
        }
    }
}

int main()
{
    cin >> n >> m ;
    for (ll i=1 ; i<=m ; i++)
    {
        cin >> x >> y ;
        if (i==1)fi=x;
        if (i==m)en=y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    for (ll i=1 ; i<=n ; i++)
    {
        sz[graph[i].size()]++;
    }
    if (sz[2]==n-2 && sz[1]==2)
    {
        if (m==n-1)
        {
            cout << bus <<endl;
            return 0;
        }
    }
    if (sz[2]==n && m==n)
    {
        cout << ring <<endl;
        return 0;
    }
    if (sz[n-1]==1 && m==n-1)
    {
        cout << star <<endl;return 0;
    }
    //traverse(fi);
    cout << unknown <<endl;
    return 0;
}
