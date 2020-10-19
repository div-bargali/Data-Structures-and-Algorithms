// C++ program to demonstrate delete operation in binary search tree
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

// Function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<  root->key;
        inorder(root->right);
    }
}

/* Function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

/* Function to return the node with minimum key value found*/
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/*function to delete the key and return the new root */
struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children
        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Main functions
int main()
{

    struct node *root = NULL;
    //Use Following inputs for testing
    //root = insert(root, 55);
    //root = insert(root, 37);
    //root = insert(root, 24);
    //root = insert(root, 41);
    //root = insert(root, 73);
    //root = insert(root, 67);
    //root = insert(root, 88);

    int n;
    cout<<"Number of Nodes\n";
    cin>>n;

    int element;
    for(int i=0;i<n;i++){
        cin>>element;
        root = insert(root, element);
    }

    int del;
    cout<<"Delete Element:\n";
    cin>>del;
    root = deleteNode(root, del);

    cout<<"Inorder traversal of the modified tree \n";
    inorder(root);

    return 0;
}
