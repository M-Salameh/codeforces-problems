#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

class DisjSet
{
	int *degree, *parent, n;
    public:
	DisjSet(int n)
	{
		degree = new int[n+1];
		parent = new int[n+1];
		this->n = n;
		makeSet();
	}
	void makeSet()
	{
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
	}
	int get_parent(int x)
	{
		if (parent[x] != x) {
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
		if (degree[xset] < degree[yset]) {
			parent[xset] = yset;
		}
		else if (degree[xset] > degree[yset]) {
			parent[yset] = xset;
		}
		else {
			parent[yset] = xset;
			degree[xset] = degree[xset] + 1;
		}
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
        cin >> u >> v;
        if (s=="get")
        {
            if (DSU.get_parent(u) == DSU.get_parent(v))
            {
                cout << "YES" << endl;
            }
            else cout << "NO" <<endl;
        }
        else
        {
            DSU.Union(u,v);
        }
    }
	return 0;
}
