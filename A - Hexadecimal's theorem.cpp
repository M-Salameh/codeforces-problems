#include <bits/stdc++.h>
#define ll long long
using namespace std;


unsigned char coun;
unsigned int value;
unsigned int table[10]={0x10FA, 0x1DC0, 0x150E, 0x55BB, 0xAD34,0x2Fc5, 0x4567, 0x33DB, 0xE464, 0x74FF};

char Compare(value){
    for (coun=10; coun>0; coun--)
    {
        if(value==table[coun])
        {
            return(0xFF);
        }

    }
    return(0x0);
}



int main()
{
    /*ll n;
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
    }*/
  cout << Compare(351);
    return 0;
}
