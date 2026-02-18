#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
//#define int int_fast64_t
//#define pii pair<int,int>

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 2e18+1;
const int NN = 2e6 + 4;
const int mod = 1e9+7;
int tc=1;
int n , q;
int segt[NN*4 + 5];


void build()
{
    for (int i=(1 << n)-1 ; i>0 ; i--)
    {
        segt[i] = segt[i<<1] ^ segt[(i<<1) + 1];
    }
}

int query(int idx , int skill)
{
    int ans = 0 ;
    int node = 1;
    while (idx != 1)
    {
        int j = idx ^ 1;
        if ( (segt[j] == skill and j < idx) or segt[j] > skill )
        {
            ans += node;
        }
        node <<= 1;
        idx >>= 1;
        skill ^= segt[j];
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///freopen("test_input.txt" , "r" , stdin);
    ///freopen("test_output.txt" , "w" , stdout);
    auto time_start = clock();
    cin >> tc;
    while (tc--)
    {
        cin >> n >> q;
        for (int i=(1 << n) ; i<(1 << (n+1)) ; i++)
        {
            cin >> segt[i]; 
        }
        build();
        int idx , skill;
        while(q--)
        {
            cin >> idx >> skill ;
            idx += ((1 << n) - 1); 
            cout << query(idx , skill) << endl;
        }
    }
    
    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
