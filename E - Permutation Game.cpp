#include <bits/stdc++.h>
#define int long long
#define double long double
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
#define mid (l+r)/2
using namespace std;

int tc=1;

int n,k;
int fi , sec , ti;
int arr[600600];

signed main()
{
    fast;
    cin >> tc;
	while(tc--)
    {
        cin >> n;
        fi=sec=ti=0;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            if (arr[i]!= i and arr[i] != n-i+1)
            {
                ti++;
            }
            else if (arr[i] != i)
            {
                fi++;
            }
            else if (arr[i] != n-i+1)
            {
                sec++;
            }
        }
        if (fi+ti <= sec)
        {
            cout << "First" <<endl;
        }
        else if(ti+sec < fi)
        {
            cout<<"Second"<<endl;
        }
        else
        {
            cout<<"Tie"<<endl;
        }
    }

	return 0;
}
