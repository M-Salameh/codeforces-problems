#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define V vector<int>
#define Vv vector<vector<int>>
#define Vp vector<pair<int, int>>
#define No cout << "NO" << Endl
#define Yes cout << "YES" << Endl
#define ll long long
#define Pb push_back
#define S second
#define F first
using namespace std;

const int Mod=998244353;
const int NN = 1e7+2;

int pw(int x, int y)
{
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x)%Mod;
        y = (y >> 1)%Mod;
        x = (x * x)%Mod;
    }
    return res ;
}

int a[1000005];

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int Tc=1;
    cin>>Tc;
    while(Tc--)
    {
        int n;cin>>n;
        string s;cin>>s;
        if(n==1)
        {
            cout<<0<<" "<<0<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
        {
            a[i]=s[i]-'0';
        }
        int m1=-1,m2=-1;
        int id1,id2;
        for(int i=0;i<n;i++)
        {
            if(a[i]>=m1)
            {
                id1=i;
                m1=a[i];
            }
        }
        int ans=0;
        if(id1!=n-1)
            {int x=a[n-1];a[n-1]=m1;a[id1]=x;ans++;}
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>m2)
            {
                id2=i;
                m2=a[i];
            }
        }
        if(id2!=0)
        {
           int x=a[0];a[0]=m2;a[id2]=x;ans++;
        }
        //cout<<ans<<endl;
        int sum=0;
        //for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
        for(int i=0;i<n-1;i++)
        {
            sum+=a[i]*10+a[i+1];
        }
        cout<<ans<<" "<<sum<<endl;
    }
    return 0;
}
