#include <bits/stdc++.h>
#define int long long
#include <math.h>
#define endl '\n'
using namespace std;

int tc;
int n;
int a,b,c;
set<int> divs;

int LCM(int x , int y)
{
    int a = __gcd(x,y);
    return (x*y)/a;
}

int gcd_sum (int x)
{
    int ans=0;
    int y=x;
    while (x>0)
    {
        ans += x%10;
        x/=10;
    }
    ans = __gcd(y,ans);
    return ans;
}



void solve()
{
    divs.clear();
    if (n<24)
    {
        cout << "NO\n";
        return;
    }
    for (int j=1 ; j<=2 ; j++)
    {
        for (int i=2 ; i*i <=n ; i++)
        {
            if (n%i==0 && divs.count(i)==0)
            {
                divs.insert(i);
                n/=i;
                if (j==2 && n!=i)
                {
                    divs.insert(n);
                }
                break;
            }
        }
    }
    if (divs.size()<3)
    {
        cout <<"NO" <<endl;
        return;
    }
    cout <<"YES"<<endl;
    for (auto i : divs)
    {
        cout << i << ' ';
    }
    cout << endl;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tc ;
    while (tc--)
    {
        cin >> n ;
        solve();
    }
    return 0;
}
