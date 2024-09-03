#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
     map<string,int>mp;
     int n,c;
     cin>>n>>c;
     vector<string>v;
     for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int x=0;
        for(int j=0;j<c;j++){
            if(s[j]=='*'){
                x=j;break;
            }
        }
        for(int j=97;j<=122;j++){
            s[x]=j;
            v.push_back(s);
            mp[s]++;
        }
     }
     int ans=0;
     for(int i=0;i<v.size();i++){
        if(mp[v[i]]>ans)ans=mp[v[i]];
     }
     vector<string>anss;
     for(int i=0;i<v.size();i++){
        if(mp[v[i]]==ans)anss.push_back(v[i]);
     }
     sort(anss.begin(),anss.end());
     cout<<anss[0]<<" "<<ans<<endl;
    return 0;
}
