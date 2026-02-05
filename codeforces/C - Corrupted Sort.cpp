#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
#include <math.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define pi pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin()+1,x.end()
#define all0(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define ll unsigned long long
#define int long long
#define double long double
#pragma once
#define ll long long
#define Pb push_back
#define S second
#define F first
///#define endl '\n'
using namespace std;
using namespace __gnu_pbds;

int tc = 1;
const int inf = 1e14+6;
int n,c ;

vector<int> ans;

signed main()
{
    fast;
    //cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        bool Chk = 0;
        int Cur = 1, Num = 0;
        while(true)
        {
            if(Chk)
                break;
            if(Num%(2*n) == 0)
            {
                for(int j=1;j<=Cur-1;j++){
                    cout << j << " "<<j+1<<endl;
                    cout.flush();
                    Num ++;
                    string s2;
                    cin >> s2;
                    if(s2 == "SWAPPED"){
                        if(j == Cur-1){
                            for(int k=j+1;k<=n;k++){
                                cout <<j<<" "<<k<<endl;
                                cout.flush();
                                Num ++;
                                string s3;
                                cin >> s3;
                                if(s3 == "WIN"){
                                    Chk = 1;
                                    break;
                                }
                            }
                        }
                        else {
                            for(int k=j+1;k<=n;k++){
                                cout <<j<<" "<<k<<endl;
                                cout.flush();
                                Num ++;
                                string s3;
                                cin >> s3;
                                if(s3 == "SWAPPED"){
                                    cout<<j+1<<" "<<k<<endl;
                                    cout.flush();
                                    Num ++;
                                    string s4;
                                    cin >> s4;
                                    if(s4 == "WIN"){
                                        Chk =  1;
                                    }
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
            }
            for(int i=1;i+Cur<=n;i++){
                if(Chk)
                  break;
                cout<<Cur<<" "<<Cur+i<<endl;
                cout.flush();
                Num ++;
                string s;
                cin >> s;
                if(s == "WIN"){
                    Chk = 1;
                    break;
                }
                if(Num%(2*n) == 0){
                    Cur --;
                    break;
                }
            }
            Cur ++;
        }
    }
    return 0;
}




///freopen("dotak.in", "r", stdin);
///freopen("library.out", "w", stdout);
