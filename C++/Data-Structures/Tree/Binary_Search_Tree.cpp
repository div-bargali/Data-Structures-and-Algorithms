#include&lt;iostream&gt; 
using namespace std;
  
//declaration for new bst node  
struct bstnode 
{ 
int data; 
struct bstnode *left, *right; 
}; 
  
// create a new BST node 
struct bstnode *newNode(int key) 
{ 
struct bstnode *temp =  new struct bstnode(); 
temp-&gt;data = key; 
temp-&gt;left = temp-&gt;right = NULL; 
return temp; 
} 
   
// perform inorder traversal of BST 
void inorder(struct bstnode *root) 
{ 
if (root != NULL) 
    { 
inorder(root-&gt;left); 
cout&lt;&lt;root-&gt;data&lt;&lt;" "; 
inorder(root-&gt;right); 
    } 
} 
   
/* insert a new node in BST with given key  */
struct bstnode* insert(struct bstnode* node, int key) 
{ 
    //tree is empty;return a new node
if (node == NULL) return newNode(key); 
   
    //if tree is not empty find the proper place to insert new node
if (key &lt; node-&gt;data) 
node-&gt;left  = insert(node-&gt;left, key); 
else
node-&gt;right = insert(node-&gt;right, key); 
   
    //return the node pointer
return node; 
} 
//returns the node with minimum value
struct bstnode * minValueNode(struct bstnode* node) 
{ 
struct bstnode* current = node; 
   
    //search the leftmost tree
while (current &amp;&amp; current-&gt;left != NULL) 
current = current-&gt;left; 
   
return current; 
} 
  //function to delete the node with given key and rearrange the root
struct bstnode* deleteNode(struct bstnode* root, int key) 
{ 
    // empty tree 
if (root == NULL) return root; 
   
    // search the tree and if key &lt; root, go for lefmost tree 
if (key &lt; root-&gt;data) 
root-&gt;left = deleteNode(root-&gt;left, key); 
   
    // if key &gt; root, go for rightmost tree 
else if (key &gt; root-&gt;data) 
root-&gt;right = deleteNode(root-&gt;right, key); 
   
    // key is same as root
else
    { 
        // node with only one child or no child 
if (root-&gt;left == NULL) 
        { 
struct bstnode *temp = root-&gt;right; 
free(root); 
return temp; 
        } 
else if (root-&gt;right == NULL) 
        { 
struct bstnode *temp = root-&gt;left; 
free(root); 
return temp; 
        } 
   
     // node with both children; get successor and then delete the node
struct bstnode* temp = minValueNode(root-&gt;right); 
   
        // Copy the inorder successor's content to this node 
root-&gt;data = temp-&gt;data; 
         
       // Delete the inorder successor 
root-&gt;right = deleteNode(root-&gt;right, temp-&gt;data); 
    } 
    return root; 
}   
// main program
int main() 
{ 
    /* Let us create following BST 
              40 
             /  \ 
           30   60 
                    \ 
                   65 
                      \
                     70*/
struct bstnode *root = NULL; 
root = insert(root, 40); 
root = insert(root, 30); 
root = insert(root, 60); 
root = insert(root, 65); 
root = insert(root, 70); 
 
cout&lt;&lt;"Binary Search Tree created (Inorder traversal):"&lt;&lt;endl; 
inorder(root); 
   
cout&lt;&lt;"\nDelete node 40\n"; 
root = deleteNode(root, 40); 
cout&lt;&lt;"Inorder traversal for the modified Binary Search Tree:"&lt;&lt;endl; 
inorder(root); 
   
return 0; 
}
