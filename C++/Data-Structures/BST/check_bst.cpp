//Check if a given binary tree is a BST
//Testcase:
// Input: 5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
// Output: false

// Input: 3 1 5 -1 2 -1 -1 -1 -1
// Output: true

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //Root Data
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //Left Child
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //Right child
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

bool help(BinaryTreeNode<int> *root, int min, int max){
    
    if(root== NULL)
        return true;
    
    if(root->data>=min && root->data<= max)
    {
        bool ansl= help(root->left, min, root->data-1);
        bool ansr= help(root->right, root->data, max);
        
        if(ansl && ansr)
            return true;
        else
            return false;
        
    }
    else
        return false;
}

bool isBST(BinaryTreeNode<int> *root){
    
    int min= INT_MIN;
    int max= INT_MAX;
    
    return help(root, min, max);

}

int main() {
    BinaryTreeNode<int>* root = takeInput();

    if(isBST(root)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    delete root;
}
