#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

class DisjSet
{
    public:
	int *degree, *parent, n , *xp;
	DisjSet(int n)
	{
		degree = new int[n+1];
		parent = new int[n+1];
		xp = new int[n+1];
		this->n = n;
		makeSet();
	}
	void makeSet()
	{
		for (int i = 1; i <= n; i++)
        {
			parent[i] = i;
			xp[i]=0;
			degree[i]=1;
		}
	}
	int get_parent(int x)
	{
		if (parent[x] != x)
        {
			parent[x] = get_parent(parent[x]);
		}

		return parent[x];
	}
	void Union(int x, int y)
	{
		int xset = get_parent(x);
		int yset = get_parent(y);
		if (xset == yset)
			return;
		if (degree[xset] < degree[yset])
        {
			parent[xset] = yset;
			degree[yset] += degree[xset];
		}
		else if (degree[xset] >= degree[yset])
        {
            parent[yset] = xset;
			degree[xset] += degree[yset];
		}
	}

	void Add(int x , int v)
	{
	    int root = get_parent(x);
	    xp[root]+=v;
	}

	int get_xp(int x)
	{

	}

};

int main()
{
    int n,m,u,v;
    fast;
    cin >> n >> m;
    DisjSet DSU (n);
    string s;
    while (m--)
    {
        cin >> s;
        if (s=="add")
        {
            cin >> u >> v ;
            DSU.Add(u,v);
        }
        else if (s=="get")
        {
            cin >> u;
            cout << DSU.get_xp(u) << endl;
        }
        else
        {
            cin >> u  >> v;
            DSU.Union(u,v);
        }
    }
	return 0;
}
