#include<bits/stdc++.h>
#define int long long
#define double long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define mid (l+r)/2
using namespace std;

int tc=1;
int n;

void solve_method1(vector<int>& arr)
{
    vector<int> ans;
    for (int i=1 ; i<=n ;i++)
    {
        int l=1;
        int r=i;
        while (l<=r and mid>0)
        {
            if (l==r)
            {
                ans.push_back((arr[r]>=i-r+1)*(i-r+1));
                break;
            }
            else if (arr[mid] > i-mid+1)
            {
                r = mid;
            }
            else if (arr[mid] < i-mid+1)
            {
                l = mid+1;
            }
            else if (arr[mid] == i-mid+1)
            {
                ans.push_back(i-mid+1);
                break;
            }
        }
    }

    for (auto i : ans) cout << i << ' ';
    cout << endl;
    return;
}

void solve_method2(vector<int>& arr)
{
     vector<int> ans;
    int l=1;

    for (int i=1 ; i<=n ; i++)
    {
        while (arr[l] < i-l+1)
        {
            l++;
        }
        ans.push_back(i-l+1);
    }
}

signed main()
{
    fast;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        vector<int> arr(n+2);
        for (int i=1 ; i<=n ; i++) cin >> arr[i];
        solve_method1(arr);

    }

    for (auto i : ans) cout << i << ' ';
    cout << endl;
    return 0;
}
