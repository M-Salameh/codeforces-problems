#include <bits/stdc++.h>
#define int long long
#include <math.h>
#define endl '\n'
using namespace std;

int tc=1;
int c;

const int inf = 1e7 + 2;

int sum_divs[inf-1];
int ans[inf-1];


void fill_ans()
{
    for (int i=1;i<inf;i++)ans[i]=inf;
    for (int i=1 ; i<inf ; i++)
    {
        for (int j=i ; j<inf ; j+=i)
        {
            sum_divs[j]+=i;
        }
        if ((sum_divs[i]<inf)&&(ans[sum_divs[i]] == inf))
        {
            ans[sum_divs[i]] = i;
        }
    }

}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc ;
    fill_ans();
    while (tc--)
    {
        cin>>c;
        if (ans[c]>c)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans[c] <<endl;
        }
    }
    return 0;
}
