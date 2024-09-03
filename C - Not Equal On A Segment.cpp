#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
using namespace std;

int tc=1;
int n;
int m;
int a[200100];

struct vert{
int mini;
int maxi;
int indx_mini;
int indx_maxi;
};

vert segt[800800];

vert opr(vert x , vert y)
{
    vert ans;
    if(x.maxi>y.maxi)
    {
        ans.maxi=x.maxi;
        ans.indx_maxi=x.indx_maxi;
    }
    else if(x.maxi<=y.maxi)
    {
        ans.maxi=y.maxi;
        ans.indx_maxi=y.indx_maxi;
    }

    if(x.mini<y.mini)
    {
        ans.mini=x.mini;
        ans.indx_mini=x.indx_mini;
    }
    else if(x.mini>=y.mini)
    {
        ans.mini=y.mini;
        ans.indx_mini=y.indx_mini;
    }
    return ans;
}

void build(int node, int l, int r)
{
    if(l==r)
    {
        segt[node].maxi=a[l];
        segt[node].mini=a[l];
        segt[node].indx_maxi=l;
        segt[node].indx_mini=l;
        return;
    }
    build(lc, l, mid);
    build(rc, mid+1, r);
    segt[node]=opr(segt [lc], segt[rc]);
    return;
}

int query(int node, int l,int r,int st,int en, int x)
{
    if(r<l or r<st or l>en) return -1;

    if(st<=l and en>=r)
    {
        if(x!=segt[node].mini)return segt[node].indx_mini;
        else if(x!=segt[node].maxi)return segt[node].indx_maxi;
        else return -1;
    }

    return max(query(lc,l,mid,st,en,x),query(rc,mid+1,r,st,en,x));
}

void solve(){
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++ ) cin >> a[i];
    build(1 , 1 , n);
    while(m--)
    {
        int l,r,x;
        cin >> l >> r >> x;
        cout << query(1,1,n,l,r,x) << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    //cin >> tc;
    while(tc--)
    {
        solve();

    }

    return 0;
}
