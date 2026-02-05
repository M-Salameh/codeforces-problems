#include <bits/stdc++.h>
#include <math.h>
//#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int tc=1;
int n;

void solveE()
{
    int arr[n+2];
    map<int,int> hits;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
        hits[arr[i]]=0;
        hits[arr[i]+1]=0;
    }

    int ans=0;
    for (int i=1 ; i<=n ;i++)
    {
        if(hits[arr[i]+1] > 0)
        {
            hits[arr[i]+1]--;
            hits[arr[i]]++;
        }
        else
        {
            hits[arr[i]]++;
            ans++;
        }
    }
    cout << ans <<endl;
}


string f = "first";
string s = "second";

void set_prime(bool prime[] , int inf)
{
    for (int i=2 ; i<=inf ; i++)
    {
        if (prime[i])
        {
           for(int j=2*i ; j<=inf ; j+=i)
            prime[j]=false;
        }
    }
    return;
}

int prime(bool pprime[] ,int j)
{
    if (pprime[j]) return j;
    return 0;
}

int solveI()
{
    const int inf = 1e7+1;
    bool prime[inf];
    set_prime(prime , inf);
    int m = n;

    int player = 0;

    while(true)
    {
        if (m==0)
        {
            player = 1-player;
            return player;
        }
        if (prime[m] or m==1)
        {
              return player;
        }
        bool fl=true;
        for (int i=1 ; i <= (m+1)/2 ; i++)
        {
            if (!prime[m-i])
            {
                player = 1-player;
                m=m-i;
                fl = false;
                break;
            }
            if (i==(m+1)/2 and fl)
            {
                  return 1-player;
            }
        }
    }
}


void solveH()
{
    int arr[n+1];
    int cnt=0;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans;
    ans.push_back(arr[1]);
    for (int i=2 ; i<=n ; i++)
    {
        if (__gcd(ans.back(),arr[i]) > 1)
        {
            ans.push_back(1);
            cnt++;
        }
        ans.push_back(arr[i]);
    }
    cout << cnt <<endl;
    for (auto i : ans ) cout << i << ' ';
    cout << endl;
    return;
}

signed main()
{

    fast;
    //cin >> tc;
    while (tc--)
    {
        cin >> n;
        solveH();
    }
    return 0;
}






