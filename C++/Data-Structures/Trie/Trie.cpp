/* 

if the words are :  GOAT,  GOAL , HELLO, HEY
then in trie they are stored as
          Root
        /    \
       G      H
      /        \
     O          E
    /          / \
   A          Y   L
  /  \             \
 T    L             L
                     \
                      O


*/
#include <string>
#include <vector>
#include <map>
#include <iostream>

struct TrieNode {                                               //create class
  std::string val;
  std::map<const char, TrieNode*> Children = {};
  bool isEnd;
  TrieNode() { isEnd = false; }
};

void addToTrie(std::string s, TrieNode* root);

void setupTrie(std::vector<std::string> words, TrieNode* root){ //setting Trie
  for(auto& j : words){
    addToTrie(j, root);
  }
}

void addToTrie(std::string s, TrieNode* root){                   //insert data
  TrieNode* curr = root;
  
  for(int i = 0; i < s.size(); i++){
    char next = s[i];
    TrieNode* currNode = curr->Children[next];
    //if the current node doesn't exist, add it
    if(!currNode){
      currNode = new TrieNode();
      curr->Children[s[i]] = currNode;
    }
    curr = currNode;
  }
  
  curr->isEnd = true;
}

bool isMember(std::string word, TrieNode* root){    //find data function
  TrieNode* curr = root;
  
  for(int i = 0; i < word.length(); i++){
    const char next = word[i];
    TrieNode* currNode = curr->Children[next];
    if(!currNode)
       return 0;
    curr = currNode;
  }
  return curr->isEnd;
}


//driver
int main(){
  std::vector<std::string> words = {"hello", "hi", "yes", "you"};
  
  TrieNode* root = new TrieNode();
  setupTrie(words, root);
  std::string s = "hello";
  std::string s2 = "help";
  
   if(isMember(s,root))
     std::cout << "hello is a member\n ";
   else
     std::cout << "hello not a member\n";

   if(isMember(s2, root))
     std::cout<<"help is a member\n";
   else
     std::cout <<"help is not a member\n";
  
  return 0;
}