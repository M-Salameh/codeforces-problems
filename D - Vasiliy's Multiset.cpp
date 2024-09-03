#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

struct TrieNode
{
	TrieNode* bit[2];
	int cnt=0;
};


class Trie
{
public:

    TrieNode* root;
    Trie()
    {
        this->root = new TrieNode();
    }

    void insert(int x)
    {
        TrieNode* node = root;
        for(int i=30 ; i>=0 ; i--)
        {
            int curbit = (x>>i)&1 ;
            if(node -> bit[curbit] == NULL)
            {
                node->bit[curbit] = new TrieNode();
            }
            node = node -> bit[curbit];
            node -> cnt++;
        }
    }

    void remove(int x)
    {
        TrieNode* node = root;
        for(int i=30 ; i>=0 ; i--)
        {
            int curbit = (x>>i)&1 ;
            node = node -> bit[curbit];
            node -> cnt--;
        }
    }


    int maxxor(int x)
    {
        TrieNode* node = root;
        long long ans = 0;
        for(int i=30 ; i>=0 ; i--)
        {
            bool curbit = (x>>i)&1 ;
            bool notcurbit = !curbit;

            if(node->bit[notcurbit]!=NULL
                and
                node->bit[notcurbit]->cnt >0)
            {
                ans += (1LL << i);
                node = node -> bit[notcurbit];
            }
            else
                node=node->bit[curbit];
        }
        return ans;
    }

};


void solve()
{
    Trie* trie = new Trie();
	trie->insert(0);
	int q;
	cin >> q;
	while(q--)
	{
		char ch;
		cin >> ch;
		int x;
		cin >> x;
		if(ch == '+') trie->insert(x);
		else if(ch == '-') trie->remove(x);
		else
        {
            long long ans = trie->maxxor(x);
            cout << ans << endl;
        }
	}
	return ;
}


signed main()
{
   fast;
   solve();
   return 0;
}




