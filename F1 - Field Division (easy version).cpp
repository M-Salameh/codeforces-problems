#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int inf = 1e18+2;
int tc = 1;
const int NN = 2e5+6;
int n , m;
int k;

pair<int,int> arr[NN];
map<pair<int,int>,int> idx;
map<int,bool> ans;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        cin >> k ;
        ans.clear();
        idx.clear();
        for (int i=1 ; i<=k ; i++)
        {
            int r,c;
            cin >> r >> c;
            arr[i] = {c,r};
            idx[{c,r}] = i;
        }
        sort(arr+1 , arr+k+1);
        arr[k+1] = {m+1,n};

        int pre = 0;
        int tot = 0;
        for (int i=1 ; i<=k ; i++)
        {
            if(arr[i].second <= pre) continue;
            while(i<=k and arr[i].first == arr[i+1].first) i++;
            tot += (-1+arr[i].first)*(arr[i].second - pre);
            pre = arr[i].second;
            ans[idx[arr[i]]] = true;
        }

        tot += (-1+arr[k+1].first)*(arr[k+1].second - pre);
        cout << tot << endl;
        for (int i=1 ; i<=k ; i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
