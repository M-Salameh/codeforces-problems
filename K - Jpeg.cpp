#include <bits/stdc++.h>
#include <math.h>
#include <string>
#define endl '\n'
///#define int long long
//#define double long double
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536
#define ll long long

const int MOD = 1e9+7;

using namespace std;

int tc=1;
int n;
int a[110][110];

void walk_zigzag(vector<int>& ans)
{
    ans.push_back(a[1][1]);
    int i=1,j=1;
    while(i<n)
    {
        if(i==1)
        {
            if(j!=n)j++;
            ans.push_back(a[i][j]);
            while(j>1)
            {
                i++;j--;
                ans.push_back(a[i][j]);
            }
        }
        if(j==1&&i!=n)
        {
            i++;
            ans.push_back(a[i][j]);
            if(i!=n)
            {
                while(i>1&j<n)
                {
                    i--;j++;
                    ans.push_back(a[i][j]);
                }
            }
        }
    }
    while(i<n or j<n)
    {
        if(i==n&&j!=n)
        {
            if(j!=1 or n%2==0)j++;
            if(j!=1 or n%2==0)ans.push_back(a[i][j]);
            while(j!=n)
            {
                i--;j++;
                ans.push_back(a[i][j]);
            }
        }
        if(j==n&&i!=n)
        {
            i++;
            ans.push_back(a[i][j]);
            while(i<n)
            {
                i++;j--;
                ans.push_back(a[i][j]);
            }
        }
    }
}

void read()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
}


void print(vector<int>& ans)
{
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<' ';
        if((i+1)%n==0) cout<<endl;
    }
}


signed main()
{
    fast;
    cin >> tc ;
    while(tc--)
    {
        read();
        vector<int>ans;
        walk_zigzag(ans);
        print(ans);
    }

    return 0;
}
