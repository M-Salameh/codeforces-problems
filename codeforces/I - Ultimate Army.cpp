  #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define enter for(ll i=1;i<=n;i++)cin>>a[i]
    #define sorrt sort(a+1,a+n+1);
    #define mem memset(vis,0,sizeof vis);
    #define pjjjj push
    #define f first
    #define s second
    int a[200005],ans[200005];

void build(int n,int a[],string s,int &p)
{
    for(int i=0;i<n;i++)
    {
        int z=i;
        if(s[i]-'0'>=0&&s[i]-'0'<=9){
                p++;
        while(s[z]!='('&&s[z]!=')'){
            a[p]+=(s[z]-'0');
            a[p]*=10;
            z++;
            if(z>=n)break;
        }
        a[p]/=10;
        i+=z-i;
        }

   }
}
void solve(int a[],string s,int p)
{
    stack <int>num;
    int n=s.size();
    num.push(a[1]);
    int z=2;
    for(int i=0;i<n;i++){
     if(s[i]=='(')
     {
        num.push(a[z]);
        z++;
     }
     else if(s[i]==')')//12(6)(9)(3(4(1)(2))(5)(7))(8)(10(11))
        {
            int cur=num.top();
            num.pop();
            ans[cur]=num.top();
        }
    }
    for(int i=1;i<=p;i++)cout<<ans[i]<<" ";
}


   int main(){
   int n,x;cin>>x;
   memset(a,0,sizeof a);
   string s;
   cin>>s;
   n=s.size();
   int p=0;
   build(n,a,s,p);
   solve(a,s,p);


      return 0;
    }
