#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
using namespace std;

int tc=1;
int n,m;

int mypow(int a,int b)
{
    if(b==0)return 1;
    if (b==1 ) return a;
    if (b&1) return a*mypow(a,b/2)*mypow(a,b/2);
    return mypow(a,b/2)*mypow(a,b/2);
}


void Read_and_Set(vector<vector<int>>&rotten , vector<vector<int>>&fix ,vector<int>& fix_hash , vector<int>& rotten_hash)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>rotten[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            fix[i][rotten[i][j]]=j;
        }
    }
    int x,y;
    for(int i=1 ; i<=n ; i++)
    {
        x=y=0;
        for(int j=1; j<=m ; j++)
        {
            if(rotten[i][j]==10)rotten[i][j]=0;
            if(fix[i][j]==10)fix[i][j]=0;
            x*=10;
            x+=rotten[i][j];
            y*=10;
            y+=fix[i][j];
        }
        rotten_hash.push_back(x);
        fix_hash.push_back(y);
    }
    sort(fix_hash.begin(),fix_hash.end());
    return;
}

int find_max_beauty(int rot_hash ,int fix_hash)
{
    int beauty=0;
    int dig1 , dig2;
    int k;
    for(int j=m-1;j>=0;j--)
    {
        k = mypow(10,j);
        dig2=fix_hash/k;
        dig1=rot_hash/k;
        if(dig1==dig2)
        {
            beauty++;
            fix_hash%=k;
            rot_hash%=k;
        }
        else break;
    }
    return beauty;
}

void solve(vector<int>& fix_hash , vector<int>& rotten_hash)
{
    vector<int>ans;
    int pos;
    int beauty_bigger ;
    int beauty_smaller;
    for(int i=0; i<n ;i++)
    {
        pos=(lower_bound(fix_hash.begin(),fix_hash.end(),rotten_hash[i]))-fix_hash.begin();
        pos -= (pos==n);
        beauty_bigger = find_max_beauty(rotten_hash[i],fix_hash[pos]);
        pos = max (pos-1,0LL);
        beauty_smaller = find_max_beauty(rotten_hash[i],fix_hash[pos]);
        ans.push_back(max(beauty_bigger,beauty_smaller));
    }
    for (auto i : ans) cout << i << ' ';
    cout<<endl;
    return;
}

signed main()
{
    fast;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        vector<vector<int>> rotten(n+1,vector<int>(m+1));
        vector<vector<int>> fix(n+1,vector<int>(m+1));
        vector<int> fix_hash,rotten_hash;
        Read_and_Set(rotten,fix,fix_hash,rotten_hash);
        solve(fix_hash,rotten_hash);
    }
    return 0;
}
