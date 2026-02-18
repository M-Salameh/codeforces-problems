#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
//#define int int_fast64_t

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 2e18+1;
const int NN = 1e6+3;
const int mod = 1e9+7;
int tc=1;
int n;
int x , y , p , q;
int mini = INT_MIN;

void calc (int a , int b)
{
    if ((a&b)==0 and abs(a-x)+abs(b-y) < mini)
    {
        //cout << "check a = " << a << " , b = " << b << endl; 
        p = a;
        q = b;
        mini = abs(x-a) + abs(y-b);
    }
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
        mini = INT_MAX;
        cin >> x >> y;
        p = x , q = y , mini = x + y;
        //cout << "starting test case for x = " << x << " , y = " << y << endl;

        for (int bit = 30 ; bit >-1 ; bit--)
        {
            int ok = (x&y) >> bit ;
            if (not (ok & 1)) continue;
            //case incx: p : 1... -> 10... then q can stay the same 
            //case: decx : p : 1... -> 0111... then q can be 10...
            // reverse for y             
            //cout << "working bit = " << bit << endl;
            int bitx = x >> bit << bit;
            int bity = y >> bit << bit;
            int incx = bitx + (1<<bit);
            int incy = bity + (1<<bit);
            int decx = bitx - 1;
            int decy = bity - 1;

            calc (incx , y);
            calc (decx , bity);
            calc (x , incy);
            calc (bitx , decy);
            break;
        }

        cout << p << " " << q << endl;
        
    }
    
    auto time_end = clock();
    ///cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(time_end- time_start)/CLOCKS_PER_SEC<<endl;

    return 0;
}
