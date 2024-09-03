#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        int n,x,y;
    cin>>n>>x>>y;
    int k=0;
    while(x%2==0){
        x/=2;
        k++;
    }
    cout<<n-1-k<<endl;
     }

    return 0;
}
