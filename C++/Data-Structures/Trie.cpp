#include <bits/stdc++.h>
using namespace std;
struct Trie_Node
{
    struct Trie_Node* alphabet[26];
    bool isLeaf;
    Trie_Node()
    {
        isLeaf = false;
        for(int i = 0; i < 26; i++)
            alphabet[i] = NULL;
    }
};
class Trie {
    Trie_Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Trie_Node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string str) {
        if(!root)
		    root = new Trie_Node;
        Trie_Node* temp = root;
        int index;
        for(int i = 0; i < str.size(); i++)
        {
            index = str[i] - 'a';
            if(!temp->alphabet[index])
                temp->alphabet[index] = new Trie_Node;
            temp = temp->alphabet[index];
        }
        temp->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string str) {
        Trie_Node* temp = root;
        if(!root && str == "")
            return true;
        int index;
        for(int i = 0; i < str.size(); i++)
        {
            index = str[i] - 'a';
            if(!temp->alphabet[index])
                return false;
            temp = temp->alphabet[index];
        }
        if(temp->isLeaf)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string str) {
        Trie_Node* temp = root;
        if(!root && str == "")
            return true;
        int index;
        for(int i = 0; i < str.size(); i++)
        {
            index = str[i] - 'a';
            if(!temp->alphabet[index])
                return false;
            temp = temp->alphabet[index];
        }
        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main()
{
	Trie t;
	while(1)
	{
		string str;
		cout << "Enter a string::" << endl;
		cin>>str;
		int type;
		cout << "Enter type of query\n1. for insert\n2. for search\n3. for finding matching prefix::" << endl;
		cin>>type;
		if(type==1)
			t.insert(str);
		else if(type==2)
		{
			if(t.search(str))
				cout << "string is already present in the trie::" << endl;
			else
				cout << "string is not present in the trie::" << endl;
		}
		else
		{
			if(t.startsWith(str))
				cout << "Trie contain this string as a prefix::" << endl;
			else
				cout << "Trie doesn't contain this string as a prefix::" << endl;
		}
	}
}