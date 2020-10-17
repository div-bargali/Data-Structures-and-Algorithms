//construct BST from its level order traversal
#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *lchild, *rchild;
};


// function to create node
struct node* createNode(int key)
{
	struct node *newNode =
		(struct node*)malloc(sizeof(struct node));
	newNode->data = key;
	newNode->lchild = newNode->rchild = NULL;
	return newNode;
}
// function to construct a BST from its level order traversal
struct node *levelOrder(struct node *root , int key)
{
	if(root==NULL){
		root = createNode(key);
		return root;
	}
	if(key <= root->data)
	root->lchild = levelOrder(root->lchild, key);
	else
	root->rchild = levelOrder(root->rchild, key);
	return root;
}
//function to construct BST
struct node* constructBst(int a[], int n)
{
	if(n==0)return NULL;
	struct node *root =NULL;

	for(int i=0;i<n;i++)
	root = levelOrder(root , a[i]);

	return root;
}
// function to get the inorder traversal of BST
void inorder(struct node* root)
{
	if (!root)
		return;

	inorder(root->lchild);
	cout << root->data << " ";
	inorder(root->rchild);
}


// Driver program
int main()
{
	int a[] = {100,50,200,25,75,350};
	int n = sizeof(a) / sizeof(a[0]);

	struct node *root = constructBst(a, n);

	cout << "Inorder Traversal: ";
	inorder(root);
	return 0;
}
