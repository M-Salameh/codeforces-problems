#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
using namespace std;

int tc=1;
int n;
int ans;

signed main()
{
    fast;
    //cin >> tc;
    while(tc--)
    {
        string s;
        cin >> s;
        vector<int> nums;
        for (int i=0 ; i<s.size() ; i+=2)
        {
            nums.push_back(s[i]-'0');
        }
        sort(nums.begin() , nums.end());
        for (int i=0 ; i<nums.size() ; i++)
        {
            if (i==nums.size()-1)
            {
                cout << nums[i] <<endl;
                break;
            }
            cout << nums[i] <<'+';
        }
    }
    return 0;
}
