#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin >> n ;
    ll val;
    vector <int > v_odd;
    vector <int> v_even;
    ll loc_eve;
    ll loc_odd;
    for (ll i=0 ; i<n ; i++)
    {
        cin >> val;
        if (val%2 == 0)
        {
            v_even.push_back(val);
            loc_eve = i+1;
        }
        else
        {
            v_odd.push_back(val);
            loc_odd = i+1;
        }
    }
    if (v_even.size() > 1)
    {
        cout << loc_odd <<endl;
    }
    else{
        cout << loc_eve <<endl;
    }

    return 0;
}
