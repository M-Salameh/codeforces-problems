///https://codeforces.com/gym/104412/problem/D
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int p = 701;
const int NN = 1e6+1;
const int number_of_hashes = 2;
int power(int a, int b, int mod)
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int Inv(int a, int m)
{
    return power(a, m - 2, m);
}

vector<int> Invp[10], H[2][10], Invs;
const vector<int> Mods = {998244353, 1000000207, 1000000409, 1000000531, 1000000829, 1000001021, 1000001269,1000001447, 1000001633};

void PreCompute()
{
    for(int i=0 ; i<number_of_hashes ; i++)
    {
        Invs.push_back(Inv(p, Mods[i]));
        Invp[i] = {1};
        for(int j=1 ; j<=NN ; j++)
        {
            Invp[i].push_back(Invp[i].back() * Invs[i] % Mods[i]);
        }
    }
}
void Compute_Hash(vector<int> a, int Id)
{
    Invs.clear();
    int n = a.size();
    for(int i=0 ; i<number_of_hashes ; i++)
    {
        H[Id][i] = {0};
        int Hsh_Val = 0, P_power = 1;
        for (int &c : a)
        {
            Hsh_Val = (Hsh_Val + c * P_power%Mods[i] + Mods[i]) % Mods[i];
            P_power = (P_power * p + Mods[i]) % Mods[i];
            H[Id][i].push_back(Hsh_Val);
        }
    }
}
vector<int> Substr_Val(int l, int r, int Id)
{
    vector<int> Cur;
    assert(l <= r);
    for(int i=0 ; i<number_of_hashes ; i++)
    {
        int Val = (H[Id][i][r] - H[Id][i][l-1] + Mods[i]) * Invp[i][l-1]%Mods[i];
        Val = (Val % Mods[i] + Mods[i]) % Mods[i];
        Cur.push_back(Val);
    }

    return Cur;
}

vector<int> a,b;
vector<int> Diff1, Diff2;
int n,m;

void compress()
{
    vector<int> v;
    map<int,int> mp;
    for(int& i : Diff1)v.push_back(i);
    for(int& i : Diff2)v.push_back(i);
    sort(v.begin(), v.end());

    int cnt=0;

    for(int i=0 ; i<n+m ; i++) if(!mp[v[i]])mp[v[i]] = ++cnt;

    for(int i=0 ; i<m; i++) Diff1[i] = mp[Diff1[i]];
    for(int i=0; i<n; i++) Diff2[i] = mp[Diff2[i]];

}

void solve()
{
    compress();

    Compute_Hash(Diff1, 0);
    Compute_Hash(Diff2, 1);

    int ans = 0;
    for(int i=m;i<=n;i++)
    {
        bool chk = true;
        vector<int> val = Substr_Val(i-m+1, i, 1);
        for(int j=0 ;j<number_of_hashes; j++)
        {
            chk &= (val[j] == H[0][j][m]);
        }
        ans += chk;
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    PreCompute();

    cin >> m >> n;
    a = vector<int>(m) ; b=vector<int>(n);
    for(int& i : a) cin >> i;
    for(int& i : b) cin >> i;

    if(m == 1)
    {
        cout << n << endl;
        return 0;
    }

    for(int i=1;i<m;i++) Diff1.push_back(a[i] - a[i-1]);
    for(int i=1;i<n;i++) Diff2.push_back(b[i] - b[i-1]);
    m --;
    n--;

    solve();
    return 0;
}
