//Code for pair sum in BST
//Elements are entered in the level order form, and -1 is entered if there is no value or Null value.
//To find pair of nodes, an integer S, is entered which is the required sum.
// For example, for the input, 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1, the tree would be
/*
          8
         / \
             5   10
            / \      
           2   6
           \
            7
 */
/*Input:
   8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
   12
Output:
   5 7
   2 10
*/


#include <iostream>
#include <queue>
#include <climits>
using namespace std;

template <typename T>           //create class
class Node {
    public : 
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~Node() {
       if(left) 
             delete left;
       if(right) 
             delete right;
    }
};


bool findPair(Node<int>* root, Node<int>* temp, int x) 
{ 
    if (!root)                                              //not have BST
        return false; 
   
    if (root != temp && ((root->data + temp->data) == x))   //find pair
        return true; 
    
    if (x-temp->data < root->data) {
   if(findPair(root->left, temp, x))                       //finding
           return true; 
    }
    else {
   if(findPair(root->right, temp, x))                      //finding
      return true; 
    }
    return false; 
} 
 
void printPairs(Node<int>* root, Node<int>* curr, int x)    //print BST
{ 
    if (!curr) 
        return; 

    if (findPair(root, curr, x)) {
   if(curr->data < x-curr->data)
           cout<<curr->data<<" "<<x-curr->data<<endl;
       else 
      cout<<x-curr->data<<" "<<curr->data<<endl;
   curr->data = INT_MIN;
     
    }
  
    printPairs(root, curr->left, x); 
    printPairs(root, curr->right, x); 
} 

void printNodesSumToS(Node<int> *root, int s) {
   printPairs(root, root, s);                                  //call print function
}

Node<int>* takeInput() {                                        //create BST
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    Node<int> *root = new Node<int>(rootData);
    queue<Node<int>*> q;
    q.push(root);
    while(!q.empty()) {
        Node<int> *currentNode = q.front();
   q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if(leftChild != -1) {                                   //create left Child
            Node<int>* leftNode = new Node<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if(rightChild != -1) {                                  //create right Child
            Node<int>* rightNode = new Node<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(Node<int> *root) {                     //Print Level Order
   queue<Node<int>*> q;
   q.push(root);
   q.push(NULL);
   while(!q.empty()) {
      Node<int> *first = q.front();
      q.pop();
      if(first == NULL) {         
         if(q.empty()) {
            break;
         }
         cout << endl;
         q.push(NULL);
         continue;
      }
      cout << first -> data << " ";
      if(first -> left != NULL) {
         q.push(first -> left);
      }
      if(first -> right != NULL) {
         q.push(first -> right);
      }
   }
}

int main() {
    Node<int>* root = takeInput();              //call create BST function
    int s;
    cin >> s;                                   
    printNodesSumToS(root, s);                  //call print function
    delete root;                                //free
}
