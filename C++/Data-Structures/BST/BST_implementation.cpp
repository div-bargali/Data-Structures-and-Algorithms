#include<bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode {            //Create Class
public:
   T data;
   BinaryTreeNode* left;
   BinaryTreeNode* right;
   BinaryTreeNode(T data) {
      this->data = data;
      left = NULL;
      right = NULL;
   }
   ~BinaryTreeNode() {
      delete left;
      delete right;
   }
};
BinaryTreeNode<int>* takeInput() {   
   int rootdata;
   cin >> rootdata;
   if (rootdata == -1) {
      return NULL;
   }
   BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
   queue<BinaryTreeNode<int>*> pendingNode;
   pendingNode.push(root);
   while (pendingNode.size() != 0) {
      BinaryTreeNode<int>* front = pendingNode.front();
      pendingNode.pop();
      int leftchild;
      cin >> leftchild;
      if (leftchild != -1) {      //Create leftchild
         BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftchild);
         front->left = child;
         pendingNode.push(child);
      }
      int rightchild;
      cin >> rightchild;
      if (rightchild != -1) {      //create rightchild
         BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightchild);
         front->right = child;
         pendingNode.push(child);
      }

   }
   return root;
}
BinaryTreeNode<int>* searchBinarySearchTree(BinaryTreeNode<int>*root, int data) {
   if (root == NULL)            //Tree = Null
      return NULL;
   else if (data == root->data)   //Find Data
      return root;
   else if (data < root->data)      //Move leftChild
      return searchBinarySearchTree(root->left, data);
   else                     //Move rightChild
      return searchBinarySearchTree(root->right, data);


}
void searchinrange(BinaryTreeNode<int>*root, int lb, int ub) {

   if (root == NULL)                        //Tree = Null
      return ;
   if (root->data >= lb && root->data <= ub) {      //print data
      cout << root->data << " ";
   }
   if (ub > root->data)                     //Move right Child
      searchinrange(root->right, lb, ub);
   if (lb < root->data)                     //Move left Child
      searchinrange(root->left, lb, ub);
}

int minimum(BinaryTreeNode<int>* root) {
   if (root == NULL)
      return INT_MAX;
   return min(root->data, min(minimum(root->left), minimum(root->right)));   //return minimun in BST
}
class isBSTReturn {
public:
   bool isBST;
   int minimum;
   int maximum;
};
isBSTReturn isBST(BinaryTreeNode<int>* root) {
   if (root = NULL) {
      isBSTReturn output;
      output.isBST = true;
      output.minimum = INT_MAX;
      output.maximum = INT_MIN;
      return output;
   }
   isBSTReturn leftOut = isBST(root->left);
   isBSTReturn rightOut = isBST(root->right);
   int minimum = min(root->data, min(leftOut.minimum, rightOut.minimum));   //return minimum
   int maximum = max(root->data, max(leftOut.maximum, rightOut.maximum));   //return maxinmum
   bool isBSTfinal = (root->data > leftOut.maximum && root->data < rightOut.minimum && leftOut.isBST && rightOut.isBST);
   isBSTReturn output;
   output.minimum = minimum;   
   output.maximum = maximum;
   output.isBST = isBSTfinal;
   return output;   //return Output

}

int main() {

#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);         //read txt file (will read data)
   freopen("output.txt", "w", stdout);         //read txt file (will right)
#endif
   BinaryTreeNode<int>* root = takeInput();         //create BST
   cout << searchBinarySearchTree(root, 4) << endl;;   //find '4'
   searchinrange(root, 2, 50);                     //find  2 ~ 50
   cout << endl;
   cout << isBST(root).isBST << endl;               

   delete root;
   return 0;
}
