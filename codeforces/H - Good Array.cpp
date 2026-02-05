#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define V vector<int>
#define Vv vector<vector<int>>
#define Vp vector<pair<int, int>>
#define No cout << "NO" << Endl
#define Yes cout << "YES" << Endl
#define ll long long
#define Pb push_back
#define S second
#define F first
using namespace std;

const int Mod=998244353;
const int NN = 1e7+2;

int pw(int x, int y)
{
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x)%Mod;
        y = (y >> 1)%Mod;
        x = (x * x)%Mod;
    }
    return res ;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int Tc=1;
    cin>>Tc;
    //map<int,bool>p;
    while(Tc--)
    {
       int n, k;cin>>n;
       ll a[n+2],aa[n+2];
       for(int i=1;i<=n;i++)
            cin >> a[i];
        sort(a+1, a+n+1);
        int Le = 1, Ri = n, Ans;
        while(Le <= Ri){
            int Mid = (Le + Ri) / 2;
            ll Score = 0;
            for(int i=1;i<=n;i++){
                aa[i] = a[i];
                while(aa[i] % 2 == 0){
                    aa[i] /= 2;
                    Score ++;
                }
            }
            sort(aa+1 , aa+n+1);
            int Ind = 1;
            for(int i=n;i>=1;i--){
                int Num = 0, x = aa[i];
                while (x < Mid){
                    Num ++;
                    x *= 2;
                }
                Score -= Num;
                if(Score < 0){
                    Ind = i + 1;
                    break;
                }
            }
            if(n - Ind + 1 >= Mid){
                Ans = Mid;
                Le = Mid + 1;
            }
            else
                Ri = Mid - 1;
        }
        cout << Ans << endl;
    }
    return 0;
}