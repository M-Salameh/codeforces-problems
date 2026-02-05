#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#include <math.h>
#define MOD 1000000007
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define pi pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin()+1,x.end()
#define all0(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define ll unsigned long long
#define int long long
#define double long double
#pragma once
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'


using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 5e15+6;
int n,m;


void Insert(ordered_set(int) &s,int x)
{
    //this function inserts one more occurrence of (x) into the set.
     s.insert(x);
}


bool Exist(ordered_set(int) &s,int x)
{ //this function checks weather the value (x) exists in the set or not.

     if((s.upper_bound(x))==s.end()){
        return 0;
     }
     return ((*s.upper_bound(x))==x);

}


void Erase(ordered_set(int) &s,int x)
{ //this function erases one occurrence of the value (x).
     if(Exist(s,x)){
        s.erase(s.upper_bound(x));
     }
}


int FirstIdx(ordered_set(int) &s,int x)
{ //this function returns the first index of the value (x)..(0 indexing).

    if(!Exist(s,x)){
        return -1;
    }
    return (s.order_of_key(x));

}


int Value(ordered_set(int) &s,int idx)
{ //this function returns the value at the index (idx)..(0 indexing).

   return (*s.find_by_order(idx));

}


int LastIdx(ordered_set(int) &s,int x)
{ //this function returns the last index of the value (x)..(0 indexing).

    if(!Exist(s,x)){
        return -1;
    }
    if(Value(s,(int)s.size()-1)==x){
        return (int)(s.size())-1;
    }
    return FirstIdx(s,*s.lower_bound(x))-1;

}


int Count(ordered_set(int) &s,int x)
{ //this function returns the number of occurrences of the value (x).

     if(!Exist(s,x)){
        return 0;
     }
     return LastIdx(s,x)-FirstIdx(s,x)+1;

}


void Clear(ordered_set(int)&s)
{ //this function clears all the elements from the set.
     s.clear();
}


int Size(ordered_set(int) &s)
{
    //this function returns the size of the set.
    return (int)(s.size());
}

vector<int> arr;
vector<int> v[100100];
vector<int> pre1;
vector<int> pre2;
vector<int> pre3;
vector<int> sum;
vector<int> avg;


ordered_set(int) s;


void solve()
{
    map<int,int>freq;
    arr[0] = inf;
    arr[n+1] = inf;

    for(int i=1;i<=m;i++)
    {
        int id = FirstIdx(s,-avg[i]);
        id++;
        id += freq[avg[i]];
        freq[avg[i]]++;

        if (arr[id] <= avg[i]) pre1[id] = 0;
        else pre1[id] = 1;

        if (arr[id-1] <= avg[i]) pre2[id] = 0;
        else pre2[id] = 1;

        if(arr[id+1] <= avg[i]) pre3[id] = 0;
        else pre3[id] = 1;
    }

    for(int i=1;i<=m;i++)
    {
        pre1[i]=pre1[i-1]+pre1[i];
        pre2[i]=pre2[i-1]+pre2[i];
        pre3[i]=pre3[i-1]+pre3[i];
    }
    vector<int>ans;
    freq.clear();
    for(int i=1;i<=m;i++)
    {
        int id0=FirstIdx(s,-avg[i]);
        id0++;
        Erase(s,-avg[i]);
        for(auto x:v[i])
        {
            int ss = sum[i]-x;
            ss /= (v[i].size()-1);
            if ( (sum[i]-x)%(v[i].size()-1) == 0) ss--;
            Insert(s,-ss);
            int id1 = FirstIdx(s,-ss);
            id1++;
            bool ok = true;
            if (arr[id1] <= ss) ok=false;
            if(id0 <= id1)
            {
                if (pre1[id0-1] < id0-1) ok = false;
                if (pre1[m]-pre1[id1] < m-id1) ok = false;
                if (pre2[id1]-pre2[id0] < id1-id0) ok = false;
            }
            else
            {
                if(pre1[id1-1] < id1-1)ok = false;
                if(pre1[m]-pre1[id0] < m-id0)ok = false;
                if(pre3[id0-1]-pre3[id1-1] < id0-id1)ok = false;
            }
            ans.push_back(ok);
            Erase(s,-ss);
        }
        Insert(s,-avg[i]);
    }
    for (auto i : ans) cout<<i;
    cout << endl;
}

signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        s.clear();
        cin >> n >> m;
        arr = vector<int>(n+5,0);
        pre1 = vector<int> (m+1,  0);
        pre2 = vector<int> (m+1,  0);
        pre3 = vector<int> (m+1,  0);
        sum = vector<int> (m+1,  0);
        avg = vector<int> (m+1,  0);

        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
            arr[i] = -arr[i];
        }
        sort(all(arr));
        for(int i=1 ; i<=n ; i++) arr[i] *= -1;

        for(int i=1 ; i<=m ; i++)
        {
            v[i].clear();
            int k;
            cin >> k;
            for(int j=1 ; j<=k ; j++)
            {
                int x;
                cin >> x;
                v[i].push_back(x);
                sum[i] += x;
            }
            avg[i] = sum[i]/k;
            if (sum[i]%k == 0)avg[i]--;
            Insert(s,-avg[i]);
        }
        solve();
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
