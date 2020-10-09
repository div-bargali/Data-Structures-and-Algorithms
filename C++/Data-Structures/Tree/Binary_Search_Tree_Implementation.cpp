#include <iostream>
using namespace std;
//Data Structure to store a Binary Search Tree node
struct Node{
    int data;
    Node* left;
    Node* right;
};

//Function creates the new binary search tree node with the given value.
Node* newNode(int value)
{
    Node* node= new Node;
    node->data=value;
    node->left=NULL;
    node->right=NULL;
    return node;
}
//Function to insert a value into Binary search tree,
//It's a Recursive function, that will insert the value at it's right position
Node* Insertion(Node *root,int value)
{
    if(root==NULL)
        return newNode(value);
    
    if(value<root->data)
      root->left=Insertion(root->left,value);
    
    else
       root->right=Insertion(root->right,value);
    
    return root;
}
//You can also Transverse the Tree and One of the way is by doing inorder Transversal
void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main() {
    //creating a root pointer
    Node* root= NULL;
    
    //We'll insert these values into BST
    int ar[]={15,10,20,8,12,16,25};
    
    for(int i=0;i<7;i++)
    {
        root=Insertion(root,ar[i]);
    }
    inorder(root);
	return 0;
}
