#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#include <math.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 1e18+6;
int n ;

int a[200005];
signed main()
{
    fast;
    cin >> tc;
    while(tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<bool> Vis (n+1 , false);

        for(int i=1;i<=n;i++) cin >> a[i];
        ll Ans = 0;
        bool no = false;
        for(int j=k-1;j>=0;j--)
        {
            Ans += (1LL << j);
            for (int i=1 ; i<=n ; i++)
            {
                if(a[i]&(1LL<<j)) continue;
                if (Vis[i]) no = true;
            }
            if (no)
            {
                no = false;
                continue;
            }

            for(int i=1;i<=n;i++)
            {
                if(Vis[i])
                {
                    continue;
                }
                if ((a[i]&(1LL<<j)))
                {
                    continue;
                }
                a[i] += (1LL << j);
                Vis[i] = true;
            }

        }
        for(int i=1;i<=n;i++)
            Ans &= a[i];
        for(int i=1;i<=n;i++)
        {
            if(Vis[i])
                continue;
            bool Chk = 0;
            for (int j=0 ;j<k ; j++)
            {
                if(!(a[i] & (1LL<<j)))
                {
                    a[i] += (1LL<<j);
                    Chk = 1;
                    break;
                }
            }
            bool Chk2 = 0;
            if(!Chk){
                for(int j=0;j<k;j++){
                    if(!(Ans & (1LL<<j))){
                        a[i] -= (1LL<<j);
                        Chk2 = 1;
                        break;
                    }
                }
                if(!Chk2)
                    a[i] --;
            }
        }
        Ans = 0;
        for(int j=0;j<k;j++)
            Ans += (1LL << j);
        for(int i=1;i<=n;i++) Ans &= a[i];

        cout << Ans << endl;
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
