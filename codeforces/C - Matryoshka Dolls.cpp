#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <math.h>
#include <string.h>

using namespace std;

int tc=1;

void subsetsUtil(vector<int>& A, vector<vector<int>>& res, vector<int>& subset, int index)
{
	res.push_back(subset);
	for (int i = index; i < A.size(); i++)
    {
		subset.push_back(A[i]);
		subsetsUtil(A, res, subset, i + 1);
		subset.pop_back();
	}

	return;
}

vector<vector<int>> subsets(vector<int>& A)
{
	vector<int> subset;
	vector<vector<int>> res;
	int index = 0;
	subsetsUtil(A, res, subset, index);
	return res;
}

void solve_k()
{

    int n;
	cin >> n ;
	vector<int> arr;
	int bg;
	while (n--)
    {
        cin >> bg;
        arr.push_back(bg);
    }
	vector<vector<int>> res = subsets(arr);
	long long ans = 0;
	long long cur = 0;
	for (int i = 0; i < res.size(); i++)
    {
        cur=0;
		for (int j = 0; j < res[i].size(); j++)
		{
            cur |= res[i][j];
		}
		ans += cur;
	}
    cout << ans << endl;
    return;
}


void solve_C()
{
    int x,s;
    cin >> s >> x;
    int ans=1;
    ans = 0;
    for (int i=1 ; i<=s ; i*=x)
    {
        if (i <= s)ans++;
        else break;
    }
    cout << ans << endl;
    return;
}
signed main()
{
    fast;
    solve_C();
    return 0;
}
