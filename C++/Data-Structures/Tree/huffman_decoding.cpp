
//  C++ Program to find Huffman Decoded String from a Tree.

#include<bits/stdc++.h>
using namespace std;

// Structure definition of a Tree.
typedef struct node {
    int freq;
    char data;
    node * left;
    node * right;
} node;

// Constructing the Huffman Tree.
struct deref:public binary_function<node*, node*, bool> {
  	bool operator()(const node * a, const node * b)const {
        return a->freq > b->freq;
    }
};

typedef priority_queue<node *, vector<node*>, deref> spq;

node * huffman_hidden(string s) {

    spq pq;
    vector<int>count(256,0);
  
    for(int i = 0; i < s.length(); i++ ) {
        count[s[i]]++;
    }
    
    for(int i=0; i < 256; i++) {
        
        node * n_node = new node;
        n_node->left = NULL;
        n_node->right = NULL;
        n_node->data = (char)i;
        n_node->freq = count[i];
      
        if( count[i] != 0 )
        	pq.push(n_node);
      
    }
    
    while( pq.size() != 1 ) {
      
        node * left = pq.top();
        pq.pop();
        node * right = pq.top();
        pq.pop();
        node * comb = new node;
        comb->freq = left->freq + right->freq;
        comb->data = '\0';
        comb->left = left;
        comb->right = right;
        pq.push(comb);
      
    }
    
    return pq.top();
    
}

// To recursively contruct the whole tree with code of each branch.
void print_codes_hidden(node * root, string code, map<char, string>&mp) {
    
  	if(root == NULL)
        return;
    
  	if(root->data != '\0') {
        mp[root->data] = code;
    }
  
    print_codes_hidden(root->left, code+'0', mp);
    print_codes_hidden(root->right, code+'1', mp);
        
}

/* 
The structure of the node is

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
    
} node;

*/

// Funtion to decode the Huffman Tree.
void decode_huff(node * root, string s) 
{
    int len=s.length();
    node *temp=root;
    for(int i=0; i<len; i++)
    {
        if(s[i]=='0')
        {
            temp=temp->left;
        }
        else if(s[i]=='1')
        {
            temp=temp->right;
        }
        if(temp->data!=NULL)
        {
            cout<<temp->data;
            temp=root;
        }
    }

}

// To take input values of each node and pass them to create a tree.
int main() {
  
    string s;
    std::cin >> s;
  
    node * tree = huffman_hidden(s);
    string code = "";
    map<char, string>mp;
  
    print_codes_hidden(tree, code, mp);
    
    string coded;
  
    for( int i = 0; i < s.length(); i++ ) {
        coded += mp[s[i]];
    }
    
    decode_huff(tree,coded);
  
    return 0;
}