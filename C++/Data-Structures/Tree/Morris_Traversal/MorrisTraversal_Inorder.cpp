// C++ program for Morris Inorder traversal 
//Inorder Traversal :left, root, right

#include<iostream>
#include <bits/stdc++.h> 
using namespace std; 

//A tree node has data, left and right pointers
class node 
{ 
	public: 
	int data; 
	node *left;
    node *right; 
}; 

// Function to create a new tree node
node* newNode(int data) 
{ 
	node* newnode = new node(); 
	newnode->data = data; 
	newnode->left = NULL;
    newnode->right = NULL; 
	return newnode; 
} 

// Function for recursive inorder traversal 
void inorder(node* root) 
{ 
	if(!root)
        return ;
	
    inorder(root->left);
	cout<<root->data<<" "; 
	inorder(root->right); 
	
} 

// Preorder traversal without using recursion and without using stack 
void morrisTraversalInorder(node* root) 
{
    if (!root) 
        return; 

    node *cur ;
     
    while (root != NULL) { 
        
        // If left child is null, print the current node data and move to right child. 
        if (root->left == NULL) { 
            cout<<root->data<<" ";
            root = root->right; 
        } 
        else { 
  
            // Find the inorder predecessor 
            cur = root->left; 
            while (cur->right != NULL && cur->right != root) 
                cur = cur->right; 
  
            // Make cur as the right child of its inorder predecessor
            if (cur->right == NULL) { 
                cur->right = root; 
                root = root->left; 
            } 
  
            // If the right child of inorder predecessor already points to this node make it null, print the value and move root
            else { 
                cur->right = NULL; 
                cout<<root->data<<" " ;
                root = root->right; 
            } 
        } 
    } 

} 


//Driver program
int main() 
{ 
	node* root = NULL; 

	root = newNode(2); 
	root->left = newNode(4); 
	root->right = newNode(6); 

	root->left->left = newNode(8); 
	root->left->right = newNode(10); 

	root->right->left = newNode(12); 
	root->right->right = newNode(14); 

	root->left->left->left = newNode(16); 
	root->left->left->right = newNode(18); 

    cout<<"Morris Traversal (Inorder) \n";
	morrisTraversalInorder(root); 
    cout<<"\n\n";

    cout<<"Recursive Inorder Rraversal \n";
	inorder(root); 

	return 0; 
} 

