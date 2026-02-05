#include <bits/stdc++.h>
//#define int long long
#define double long double
#define endl '\n'
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <math.h>
#include <string.h>
#define ll long long
# define pi 3.14159265358979323846
using namespace std;
ll pw(ll a,ll b){
    if(b==0)return 1;
    ll res=pw(a,b/2);
    res=(res*res);
    if(b&1)res=(res*a);
    return res;
}
string s;
int ansS(int i,int j,int ans){
    if(i<=2){
                while(i!=3){
                    ans++;
                    s+="D";
                    i++;
                }
            }
            else{
                while(i!=3){
                    s+="U";
                    ans++;
                    i--;
                }
            }
            if(j<=2){
                while(j!=3){
                    ans++;
                    s+="R";
                    j++;
                }
            }
            else{
                while(j!=3){
                    ans++;
                    s+="L";
                    j--;
                }
            }
            return ans;
}
int main()
{
    fast;
    int L;
    cin>>L;
    for(int x=1;x<=L;x++){
            s="";
        int i,j,ans=0;
        cin>>i>>j;
        if((i<=5)||(i<=8&&j<=5)){
            ansS(i,j,ans);
            //cout<<"one"<<endl;
        }
        else if(j==1&&i>8){
            while(i!=8){
                ans++;
                s+="U";
                i--;
            }
            ans=ansS(i,j,ans);
            //cout<<"2"<<endl;
        }
        else if(j==12&&i>8){
            while(i!=5){
                ans++;
                s+="U";
                i--;
            }
            ans=ansS(i,j,ans);
            //cout<<"3"<<endl;
        }
        else if(i<=8&&j>=8){
            while(i!=5){
                ans++;
                s+="U";
                i--;
            }
            ans=ansS(i,j,ans);
             //cout<<"4"<<endl;
        }
        else if(i>=8&&j>=4&&j<=9)
        {
                while(i!=8){
                    s+="U";
                    ans++;
                    i--;
                }
                while(j!=4){
                s+="L";
                ans++;
                j--;
                }
            ans=ansS(i,j,ans);
             //cout<<"five"<<endl;
        }
        else if(i==12||i==11){
            while(j!=1){
                j--;
                ans++;
                s+="L";
                }
                while(i!=8){
                    s+="U";
                    ans++;
                    i--;
                }
                ans=ansS(i,j,ans);
                 //cout<<"6"<<endl;
        }
        cout<<s.size()<<endl;
        cout<<s<<endl;
    }
    return 0;
}
