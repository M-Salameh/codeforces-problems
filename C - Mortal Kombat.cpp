#include <bits/stdc++.h>
#define ll long long
#define fori(n) for (ll i=1 ;i<=n ; i++)
using namespace std;

const int inf = 1e6+2;

ll ans;
ll n;
ll tc;
ll arr[inf];
void solve ()
{
    ans=0;
    fill (arr ,arr+n+3 , -1);
    fori(n)
    {
        cin >> arr[i];
    }
    bool fr = true;
    ll i=1;
    while (i<=n)
    {
        if (fr)
        {
            if (arr[i]==1)
            {
                if (arr[i+1]==0)
                {
                    ans+=1;
                    i+=2;
                    fr=false;
                }
                else
                {
                    if (i<=n)
                    {
                        ans+=1;
                        i+=1;
                        fr=false;
                    }

                }
            }
            else
            {
                i++;
                if(arr[i]==0 && i<=n)i++;
                fr=false;
            }
        }
        else
        {
            fr=true;
            if (arr[i]==0)
            {
                if (arr[i+1]==0)
                {
                    i++;
                }
                else
                {
                    i+=2;
                }
            }
            else
            {
                i++;
                if (arr[i]==1 && i<=n)i++;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    cin >> tc;
    while (tc--)
    {
        cin >> n ;
        solve();
    }
   /* vector<ll> a,b;
    ll x=0;
    ll v;
    while (x!=-1)
    {
        cin >> v;
        a.push_back(v);
        x=v;
    }
    x=0;
    cout <<"\n\nfdgfdgnfdigndfigndfign\n\n";
    cout << a.size() << endl << b.size() <<endl;
    while (x!=-1)
    {
        cin >> v;
        b.push_back(v);
        x=v;
    }
    for (ll i=0 ; i<a.size() ; i++)
    {
        if (a[i]!=b[i])
        {
            cout << "diff on " << i << endl;
            cout << "a = " << a[i] << "  ,  b = " << b[i] <<endl;
        }
    }*/
    return 0;
}
/*
0
1
0
1
0
1
0
1
0
1
0
1
0
1
0
1
0
1
0
1
0
1
0
1
0
1
0
1
1
2
0
1
0
1
0
1
0
1
0
1
0
1
0
1
1
2
0
1
0
1
0
1
0
1
1
2
0
1
1
2
1
2
0
1
0
1
0
1
0
1
0
1
0
1
0
1
1
2
0
1
0
1
0
1
0
1
1
2
0
1
1
2
1
2
0
1
0
1
0
1
0
1
0
1
0
1
0
1
1
2
0
1
0
1
0
1
0
1
1
2
1
2
1
2
1
2
0
1
0
1
0
1
0
1
0
1
0
1
0
1
1
2
0
1
0
1
0
1
0
1
1
2
0
1
1
2
1
2
0
1
0
1
0
1
0
1
0
1
0
1
0
-1
0
1
0
1
0
1
0
1
0
1
0
1
0
1
0
1
0
1
0
1
0
1
0
1
0
1
0
1
1
2
0
1
0
1
0
1
0
1
0
1
0
1
0
1
1
2
0
1
0
1
0
1
0
1
0
1
0
1
1
2
1
2
0
1
0
1
0
1
0
1
0
1
0
1
0
1
1
2
0
1
0
1
0
1
0
1
0
1
0
1
1
2
1
2
0
1
0
1
0
1
0
1
0
1
0
1
0
1
1
2
0
1
0
1
0
1
0
1
1
2
1
2
1
2
1
2
0
1
0
1
0
1
0
1
0
1
0
1
0
1
1
2
0
1
0
1
0
1
0
1
0
1
0
1
1
2
1
2
0
1
0
1
0
1
0
1
0
1
0
1
0
-1



*/
