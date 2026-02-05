#include <bits/stdc++.h>
#define ll long long
#define NN int(1e4+5)
using namespace std;

ll n , k;
ll arr[NN];
ll ans;
ll ans1;
ll ans2;
void Read()
{
    cin >> n >> k;
    for (ll i=1; i<= n;i++)
    {
        cin >> arr[i];
    }
}

void solve()
{
    ll i=1;
    ans=0;
    ans1=0;
    ans2=0;
    while (i<=n)
    {
        vector<ll> v,w;
        ans1=ans2=0;
        while (arr[i]%2==0)
        {
            v.push_back(arr[i]);
            ans1+=arr[i];
            i++;
            //cout << "Filling vector v \n";
        }
        if (v.size()>0)
        {
            if (v.size() <=k)
            {
                ans+=ans1;
            }
            else
            {
                sort(v.begin() , v.end());
                ll rr=k-1;
                while (rr>=0)
                {
                    ans+=v[v.size()-rr-1];
                    rr--;
                }
            }
        }
        if (i>n)return;
        while (arr[i]%2!=0)
        {
            w.push_back(arr[i]);
            ans2+=arr[i];
            i++;
        }
         if (w.size()>0)
        {
            if (w.size() <=k)
            {
                ans+=ans2;
            }
            else
            {
                ll tt=k-1;
                sort(w.begin() , w.end());
                while (tt>=0)
                {
                    ans+=w[w.size()-tt-1];
                    tt--;
                }
            }
        }
    }
}

ll take_k(vector <ll> v , ll g)
{
    sort(v.begin() , v.end());
    ll h = v.size()-1;
    ll nk=0;
    for (ll i=h ; i >= h-g+1 ; i-- )
    {
        nk+=v[i];
    }
    return nk;
}

void solve2()
{
    ll i=1;
    while (i<=n)
    {
        vector <ll> even , odd;
        ans1=ans2=0;
        while (arr[i]%2==0 && i<=n)
        {
            even.push_back(arr[i]);
            ans1+=arr[i];
            i++;
        }
        if (even.size()<=k)
        {
            ans+=ans1;
        }
        if (even.size() > k)
        {
            ans+=take_k(even , k);
        }
        if (i>n)return;
        while (arr[i]%2 != 0 && i<=n)
        {
            odd.push_back(arr[i]);
            ans2+=arr[i];
            i++;
        }
        if (odd.size() <=k )
        {
            ans+=ans2;
        }
        if (odd.size() > k)
        {
            ans+=take_k(odd , k);
        }

    }

}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Read();
        solve();
        cout <<ans<<endl;
        ans=0;
    }
    return 0;
}
