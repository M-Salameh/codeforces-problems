#include <bits/stdc++.h>
#include <math.h>
#include <string>
#define endl '\n'
#define int long long
#define double long double
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536

const int MOD = 1e9+7;

using namespace std;
using ll = long long ;

int tc=1;

signed main()
{
    fast;
    cin >> tc ;
    while(tc--)
    {
        int vis[10][10];
        bool chk=true;
        memset(vis,0,sizeof vis);
        for(int i=1;i<=8;i++)
        {
            string s;
            cin>>s;
            char t=s[0];
            int l = t-'A'+1;
            t=s[1];
            int r = s[1]-'0';
            vis[l][r]=1;
             int col=l,row=r;
                while(col<8)
                {
                    col++;
                    if(vis[col][row])chk=false;
                }
                  col=l,row=r;
                while(row<8)
                {
                    row++;
                    if(vis[col][row])chk=false;
                }
                  col=l,row=r;
                while(row>1)
                {
                    row--;
                    if(vis[col][row])chk=false;
                }
                  col=l,row=r;
                while(col>1)
                {
                    col--;
                    if(vis[col][row])chk=false;
                }
                 col=l,row=r;
                while(col<8&&row<8)
                {
                    col++;row++;
                    if(vis[col][row])chk=false;
                }
                col=l;row=r;
                while(row>1&&col>1)
                {
                    col--;row--;
                    if(vis[col][row])chk=false;
                }
                  col=l;row=r;
                while(row>1&&col<8)
                {
                    col++;row--;
                    if(vis[col][row])chk=false;
                }
                  col=l;row=r;
                while(row<8&&col>1)
                {
                    col--;row++;
                    if(vis[col][row])chk=false;
                }
            }
        if(chk)cout<<"Valid"<<endl;
        else cout<<"Invalid"<<endl;
    }
    return 0;
}



