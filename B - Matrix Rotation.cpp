#include <bits/stdc++.h>

using namespace std;


bool check(int a,int b,int c,int d){
if(a<b&&c<d&&b<d&&a<c)return true;
return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int i=1;
       for(;i<4;i++){
        if(check(a,b,c,d)){
            cout<<"YES"<<endl;
            break;
        }
        else{
            int x=b;
            b=a;
            int y=d;
            d=x;
            a=c;
            c=y;
        }
       }
       if(i==4&&check(a,b,c,d))cout<<"YES"<<endl;
       if(!check(a,b,c,d))cout<<"NO"<<endl;
    }
    return 0;
}
