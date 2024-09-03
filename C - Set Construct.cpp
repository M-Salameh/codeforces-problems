#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define fast_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int n;
int tc;
void solve()
{
    vector <vector<char>> b(101 , vector<char>(101,'0'));
    vector <vector<bool>> subset(101 , vector<bool>(101,false));
    cin >> n;
    for (int i=1 ;i<=n ; i++)
    {
        for (int j=1 ; j<=n; j++)
        {
            // cin>>x;
            cin >> b[i][j];
        }
    }
    for (int i=1 ;i<=n ; i++)
    {
        subset[i][i]=true;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if(b[i][j]=='1')
            {
                subset[i][j]=true;
                for (int k=1;k<=n;k++)
                {
                    if(subset[j][k])
                    {
                        subset[i][k]=true;
                    }
                }
            }
        }
    }
    int numb;
    for (int i=1;i<=n;i++)
    {
        numb=0;
        for(int j=1;j<=n;j++)
        {
            if (subset[j][i])
            {
                numb++;
            }
        }
        cout << numb <<" ";
        for (int j=1;j<=n;j++)
        {
            if (subset[j][i])
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }

}

signed main()
{
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
