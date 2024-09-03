#include <bits/stdc++.h>
#define ll long long
#define inf int (1e10+1)
#define mxsz int (1e5+5)
#define mid (l+r)/2
using namespace std;
struct dot
{
long double pos ,tim;
};

dot xt[mxsz];
ll n;

dot subans (dot a, dot b)
{
    if (a.pos == b.pos && a.tim == b.tim)return a;
    if (a.tim == b.tim)
    {
        dot f;
        f.pos = (a.pos+b.pos)/2;
        f.tim = a.tim + f.pos - min (a.pos , b.pos);
        return f;
    }
    if (a.tim > b.tim)
    {
       long double wak = a.tim - b.tim;
        if (abs(b.pos-a.pos)<=wak)
        {
            return a;
        }
        if (b.pos > a.pos)
        {
            b.pos -= wak;
        }
        else
        {
            b.pos += wak;
        }
        b.tim += wak;
        dot f;
        f.pos = (a.pos+b.pos)/2;
        f.tim = a.tim + abs(a.pos - b.pos)/2;
        return f;
    }
    else
    {
        dot c;
        c.pos = a.pos;
        c.tim = a.tim;
        a.pos = b.pos;
        a.tim = b.tim;
        b.pos=c.pos;
        b.tim=c.tim;
        return subans(a,b);

    }
}


void Read ()
{
    cin >> n;
    for ( ll i=1 ; i<=n ; i++)
    {
        cin >> xt[i].pos;
    }
    for (ll i=1 ;i <=n ; i++)
    {
        cin >> xt[i].tim;
    }
}

void solve()
{
      dot ans;
      vector <dot> res;
      if (n&1)
      {
          xt[n+1] = xt[n];
          n++;
      }
      for (ll i=1 ; i<n ;i+=2)
      {
          ans = subans(xt[i] , xt[i+1]);
          res.push_back(ans);
      }
      queue<dot, deque<dot> > ress (deque<dot>(res.begin(),res.end()));

      dot d1,d2;
      while (ress.size()>1 )
      {
          d1=ress.front();
          ress.pop();
          d2=ress.front();
          ress.pop();
          ress.push(subans(d1,d2));
      }
    cout << fixed << setprecision(6) <<ress.front().pos <<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll tc;
     cin >> tc ;
     while (tc--)
     {
         Read();
         solve();
     }

    return 0;
}
