#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll modo=1000000007;

void multiply(ll F[2][2], ll M[2][2]);
void power(ll F[2][2], ll n);

// Function that returns nth Fibonacci number
ll fib(ll n)
{
    ll F[2][2] = { { 15LL, 18LL }, { 1LL, 0LL } };
    if (n == 0)
        return 0;
    if(n==1)
        return 3;
    power(F, n - 1);
    return ((3*F[0][0])%modo+modo)%modo;
}

// Optimized version of power() in method 4
void power(ll F[2][2], ll n)
{
    if (n == 0||n==1 )
        return;
    ll M[2][2] = { { 15LL, 18LL }, { 1LL, 0LL } };

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

void multiply(ll F[2][2], ll M[2][2])
{
    ll x = (((F[0][0] * M[0][0])%modo + (F[0][1] * M[1][0])%modo)%modo+modo)%modo;
    ll y = (((F[0][0] * M[0][1])%modo + (F[0][1] * M[1][1])%modo)%modo+modo)%modo;
    ll z = (((F[1][0] * M[0][0])%modo + (F[1][1] * M[1][0])%modo)%modo+modo)%modo;
    ll w = (((F[1][0] * M[0][1])%modo + (F[1][1] * M[1][1])%modo)%modo+modo)%modo;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll t=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<fib(n)<<endl;
    }
    return 0;
}
