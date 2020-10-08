// C++ program for Morris Preorder traversal 
//Preorder Traversal : Root, left, right

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

//function to create a new tree node
node* newNode(int data) 
{ 
	node* newnode = new node(); 
	newnode->data = data; 
	newnode->left = NULL;
    newnode->right = NULL; 
	return newnode; 
} 

// Function for recursive preorder traversal 
void preorder(node* root) 
{ 
	if(!root)
        return ;
	 
	cout<<root->data<<" "; 
	preorder(root->left); 
	preorder(root->right); 
	
} 

// Preorder traversal without using recursion and without using stack 
void morrisTraversalPreorder(node* root) 
{ 
    //while root is not NULL
	while (root) 
	{ 
		// If left child is null, print the current node data and move to right child. 
		if (root->left == NULL) 
		{ 
			cout<<root->data<<" "; 
			root = root->right; 
		} 
		else
		{ 
			// Find inorder predecessor 
			node* cur = root->left; 
			while (cur->right && cur->right != root) 
				cur = cur->right; 

			// If the right child of inorder predecessor already points to this node make it null and move root
			if (cur->right == root) 
			{ 
				cur->right = NULL; 
				root = root->right; 
			} 

			// If right child doesn't point to this node, then print this node and make right child point to this node 
			else
			{ 
				cout<<root->data<<" "; 
				cur->right = root; 
				root = root->left; 
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

    cout<<"Morris Traversal (Preorder) \n";
	morrisTraversalPreorder(root); 
    cout<<"\n\n";

    cout<<"Recursive Preorder Rraversal \n";
	preorder(root); 

	return 0; 
} 

