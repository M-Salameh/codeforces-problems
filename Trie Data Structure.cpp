#include <bits/stdc++.h>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

class Trie
{
    public:
    struct TrieNode* initiate_node(void)
    {
        struct TrieNode* pNode = new TrieNode;

        pNode -> isEndOfWord = false;

        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode -> children[i] = NULL;

        return pNode;
    }

    void insert_node(TrieNode* root, string key)
    {
        struct TrieNode* pCrawl = root;

        for (int i = 0; i < key.length(); i++)
        {
            int idx = key[i] - 'a';
            if (!pCrawl -> children[idx])
                pCrawl -> children[idx] = initiate_node();

            pCrawl = pCrawl -> children[idx];
        }

        pCrawl -> isEndOfWord = true;
}

    bool search_node(TrieNode* root, string key)
    {
        struct TrieNode* pCrawl = root;

        for (int i = 0; i < key.length(); i++)
        {
            int idx = key[i] - 'a';
            if (!pCrawl -> children[idx])
                return false;

            pCrawl = pCrawl -> children[idx];
        }

        return (pCrawl -> isEndOfWord);
    }

};


int main()
{
	string keys[] = {"the", "a", "there",
					"answer", "any", "by",
					"bye", "their" };

	int n = sizeof(keys)/sizeof(keys[0]);

	Trie* trie = new Trie;

	struct TrieNode* root = trie -> initiate_node();

	for (int i = 0; i < n; i++)
		trie -> insert_node (root, keys[i]);


    /**
	char output[][32] = {"Not present in trie", "Present in trie"};

	cout << "the" << " --- " << output[search_node(root, "the")] << endl;
	cout << "these" << " --- " << output[search_node(root, "these")] << endl;
	cout << "their" << " --- " << output[search_node(root, "their")] << endl;
	cout << "thaw" << " --- " << output[search_node(root, "thaw")] << endl;*/
	return 0;
}
