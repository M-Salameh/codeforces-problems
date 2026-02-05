#include <bits/stdc++.h>
#include <string>
#define endl '\n'
#define lc 2*node
#define rc lc+1
#define mid (l+r)/2
#define M_PI 3.14159265358979323846
#define M_E  2.71828182845904523536
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
///#define int long long

using namespace std;

int ans = 0;


int *pre_kmp(string pattern)
{
	int sizee = pattern.size();
	int *pie=new int [sizee];
	pie[0] = 0;
	int k=0;
	for(int i=1;i<sizee;i++)
	{
		while(k>0 and k<sizee and pattern[k] != pattern[i] )
		{
			k = pie[k-1];
		}
		if(k<sizee and pattern[k] == pattern[i] )
		{
			k=k+1;
		}
		pie[i]=k;
	}

	return pie;
}

void kmp(string text,string pattern)
{
    if (text.size()==0 or pattern.size() ==0) return;
	int* pie = pre_kmp(pattern);
	int matched_pos = 0;

	for(int current = 0; current< text.size(); current++)
	{
		while (matched_pos > 0 and matched_pos<pattern.size() and pattern[matched_pos] != text[current] )
			matched_pos = pie[matched_pos-1];

		if(matched_pos<pattern.size() and pattern[matched_pos] == text[current])
			matched_pos = matched_pos+1;

		if( matched_pos == (pattern.length()) )
		{
		    ans++;
			matched_pos = pie[matched_pos-1];
		}
	}
}


pair<vector<int> , vector<int>> read(int& n , int& m)
{
    cin >> m >> n;
    vector<int> arrm(m+1);
    vector<int> arrn (n+1);
    for (int i=1 ;i<=m ; i++)
    {
        cin >>arrm[i];
    }
    for (int i=1 ; i<=n ;i++) cin >> arrn[i];
    return make_pair(arrn , arrm);
}

string convert_int(int x)
{
    stringstream ss;
    ss<<x;
    string d;
    ss >> d;
    return d;
}

pair<string , string> make_string(int n ,vector<int> arrn , int m , vector<int> arrm)
{
    string SN="" , SM="";
    for (int i=2 ; i<=n ;i++)
    {
        int x = arrn[i] - arrn[i-1];
        string temp = convert_int(abs(x));
        if (x<0)
        {
            SN+=('-');
        }
        SN+=temp;
        SN+=',';
    }
    for (int i=2 ;i<=m ;i++)
    {
        int x = arrm[i] - arrm[i-1];
        string temp = convert_int(abs(x));
        if (x<0)
        {
            SM+=('-');
        }
        SM+=temp;
        SM+=',';
    }
    return make_pair(SN , SM);

}

signed main()
{
    fast;
    int n,m;
    vector<int> arrn , arrm;
    pair<vector<int> , vector<int>> pp;
    pp = read(n,m);
    if (m==1)
    {
        cout << n << endl;
    }
    else
    {
        arrn = pp.first;
        arrm = pp.second;
        pair<string , string> ps;
        ps = make_string(n , arrn , m , arrm);
        string SN = ps.first;
        string SM = ps.second;
        kmp(SN , SM);
        cout << ans << endl;
    }

    return 0;
}
