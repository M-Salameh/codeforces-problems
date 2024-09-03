#include <bits/stdc++.h>
#include <string>
#define endl '\n'
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
//#define double long double

using namespace std;
int tc=1;
vector<int> ms [200100];

int power(int a , int b)
{
    if (b==0) return 1;
    if (b==1) return a;
    int res = power(a,b/2) % MOD;
    res = (res*res) % MOD;
    if (b&1) res = (a*res)%MOD;
    return res%MOD;
}

int power3(int a , int b)
{
    if (b==0) return 1;
    if (b==1) return a;
    int res = power(a,b/2);
    res = (res*res);
    if (b&1) res = (a*res);
    return res;
}

bool cmp(pair<pair<int,int>,int>x , pair<pair<int,int>,int> y)
{
    if (x.first.first < y.first.first)
    {
        return true;
    }
    if (x.first.first == y.first.first)
    {
        if (x.first.second < y.first.second)
        {
            return true;
        }
        if (x.first.second == y.first.second)
        {
            if (x.second < y.second) return true;
        }
        return false;
    }
    return false;
}

void solve_c()
{
    int n,m,h;
    cin >> n>> m >> h;

    for (int i=1 ;i<=n ; i++)
    {
        for (int j=1 ; j<=m;j++)
        {
            int x;
            cin >> x;
            ms[i].push_back(x);
        }
    }
    for( int i = 1 ; i <= n ; i++ )
    {
        sort(ms[i].begin(),ms[i].end());
    }
    vector <pair<int,pair<int,int>>> standings;
    for (int i=1 ;i<=n ; i++)
    {
        int sum = 0 , cnts = 0 , penalty = 0;
        for( auto j : ms[i])
        {
            if(sum + j <= h )
            {
                cnts++;
                sum += j;
            }
        }
        int c = 1 ;
        for( int j = cnts-1 ; j >= 0 ; j-- )
        {
            penalty += ms[i][j]*c;
            c++;
        }
        standings.push_back({-cnts,{penalty,i}});
    }

    sort(standings.begin(),standings.end());

    for(int pos = 0 ; pos < n ; pos++ )
    {
        if(standings[pos].second.second == 1 )
        {
            cout << pos+1 <<endl;
            break;
        }
    }



    for (int i=1 ; i<=n ; i++)
    {
        ms[i].clear();
    }
}


void solve_D()
{
    int n;
    double d,h;
    cin>>n>>d>>h;
    double arr[200100];
    for(int i=1 ; i<=n ; i++)
    {
        cin>>arr[i];
    }
    double res = (h*d)/2;
    double zero = 0;
    for(int i=n-1 ; i>0 ; i--)
    {
        res += (h*d)/2;
        double diff = max(zero, h-arr[i+1]+arr[i] );
        double x = diff*diff*d/h;
        x /= 2;
        res -= x;
    }
    cout<<fixed<<setprecision(10)<<res<<endl;
}


void solve_B()
{
    char arr[5][5];
    char res = '*' ;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            cin>>arr[i][j];

    for(int i=1;i<=3;i++)
    if(arr[i][1]==arr[i][2] and arr[i][1]==arr[i][3] and arr[i][1]!='.')
        res=arr[i][1];
    for(int i=1;i<=3;i++)

    if(arr[1][i]==arr[2][i] and arr[1][i]==arr[3][i] and arr[1][i]!='.')
        res=arr[1][i];
    if(arr[1][1]==arr[2][2] and arr[1][1]==arr[3][3] and arr[1][1]!='.')
        res=arr[1][1];
    if(arr[1][3]==arr[2][2] and arr[1][3]==arr[3][1] and arr[3][1]!='.')
        res=arr[1][3];
    if(res != '*' ) cout<<res<<endl;
    else cout<<"DRAW"<<endl;
}

void solve_E()
{
    int n;
    cin>>n;
    bool ans=false;
    int limt = ceil(sqrt(n));
    for(int k=2;k <= limt ;k++)
    {
        if(ans)break;
        for(int j=2;j<=30;j++)
        {
            int x=power3(k,j+1)-1;
            x/=(k-1);
            if(x>n)break;
            if(x==n)
            {
                ans=true;
                break;
            }
        }
    }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
}

signed main()
{
    fast;
    cin >> tc;
    while (tc--)
    {
        solve_E();
    }
    return 0;
}
