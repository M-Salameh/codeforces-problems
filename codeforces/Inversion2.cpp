#include <bits/stdc++.h>
#define ll long long
#define mid (l+r)/2
#define lc 2*node
#define rc lc+1
#define INF int(1e6+9)
#define endl '\n'
#include <stack>
using namespace std;

ll segt[INF];
ll n;
ll nn;
ll scope[INF];
void build (ll node , ll l , ll r)
{
    if (l == r)
    {
        segt[node] = scope[r];
        return;
    }
    build (lc , l , mid);
    build (rc , mid+1 , r);
    segt[node] = segt[lc] + segt[rc];
}

void update (ll node , ll l , ll r , ll idx)
{
    if (l > r )return;
    if (l == r && r == idx)
    {
        segt[node] = 0;
        return;
    }
    if (idx <= mid)
    {
        update (lc , l , mid , idx);
        segt[node] = segt[lc] + segt[rc];
    }
    if (idx > mid)
    {
        update(rc , mid+1 , r , idx);
        segt[node] = segt[lc] + segt[rc];
    }
}


ll sum_query (ll node , ll l , ll r , ll value)
{
    if (l > r)return 0;
    if (l == r) return l;
    if (value < segt[rc])
    {
        return sum_query(rc , mid+1 , r , value);
    }
    else
    {
        return sum_query(lc , l , mid , value-segt[rc]);
    }

}

void Read()
{
    cin >> n ;
    fill (scope , scope+n+1 , 0);
    stack<ll> s;
    stack<ll> ans;
    ll x;
    for (ll i=1 ; i<= n ;i++)
    {
        cin >> x;
        s.push(x);
        scope[i]=1;
    }
    nn = n;
    n = pow(2,ceil(log2(n)));
    fill (segt , segt+n+1 , 0);
    build(1,1,n);
    cout << endl<<endl;
    for (ll i=1 ; i<=nn ; i++)
    {
        x = s.top();
        s.pop();
        ans.push(sum_query(1,1,n,x));
        update(1,1,n,ans.top());
    }

    while ( ans.size() >0)
    {
        cout <<ans.top() <<' ';
        ans.pop();
    }
    cout << endl;

}

int main()
{
     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Read();
    return 0;
}
