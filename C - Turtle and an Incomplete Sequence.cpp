#include <bits/stdc++.h>
///#define int long long
#define endl '\n'

using namespace std;

const int inf = 1e18+2;
int tc = 1;
const int NN = 5e5+6;
int n;
int arr[NN];
vector<int> pos;


int binary_LCA(int u , int v)
{
    while(u>1 or v>1)
    {
        if (u == v) return u;
        if (u > v) u /= 2;
        else v /= 2;
    }
}

///start is x , dest is y , between them idx numbers
bool get_ans(int x , int y)
{
    int idx = y-x-1;
    int lca = binary_LCA(arr[x],arr[y]);

    int depth_x = __lg(arr[x]);
    int depth_y = __lg(arr[y]);
    int depth_lca = __lg(lca);
    int dist = depth_x + depth_y - 2*depth_lca - 1;

    int need = idx - dist;

    if (dist>idx or need&1) return false;
    int l=x,r=y;

    while(arr[x]!=lca and x+1<y)
    {
        x++;
        arr[x]=arr[x-1]/2;
        l=x;
    }
    while(arr[y]!=lca && x<y-1)
    {
        y--;
        arr[y]=arr[y+1]/2;
        r=y;
    }

    while(l+1<r)
    {
        l++;
        arr[l] = 2*arr[l-1];
        arr[l+1] = arr[l-1];
        l++;
    }
    return true;
}


void solve()
{
    if (pos.size() == 0)
    {
        for (int i=1 ; i<=n ; i++)
        {
            cout << (i&1)+1 << " ";
        }
        cout << endl;
        return;
    }
    for (int i=pos[0]-1 ; i>=1 ; i--)
    {
        if ((pos[0]-i)&1)
        {
            arr[i] = 2*arr[i+1];
        }
        else arr[i] = arr[i+1]/2;
    }

    for (int i = pos.back()+1 ; i<=n ; i++)
    {
        if ((i-pos.back())&1)
        {
            arr[i] = 2*arr[i-1];
        }
        else arr[i] = arr[i-1]/2;
    }

    for (int i=0 ; i<pos.size()-1 ; i++)
    {
        bool can = get_ans(pos[i] , pos[i+1]);

        if (not can)
        {
            cout << -1 << endl;
            return;
        }
    }
    for (int i=1 ; i<=n ; i++) cout << arr[i] << " ";

    cout << endl;
    return;
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        pos.clear();
        for (int i=1 ; i<=n ; i++)
        {
            cin >> arr[i];
            if (arr[i]+1)
            {
                pos.push_back(i);
            }
        }

        solve();
    }
    return 0;
}
