#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
     int t;
    cin>>t;
    while(t--){
      int n,k;
      cin>>k>>n;
      vector<int>v;
      int i=1;
      v.push_back(1);
      while((v.back()+i<=n)&&(n-v.back()-i>=k-v.size()-1)){
            v.push_back(v.back()+i);
                i++;
            }
      while(v.size()<k)v.push_back(v.back()+1);
      for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;
          }

    return 0;
}
