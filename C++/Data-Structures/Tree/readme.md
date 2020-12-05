### Tree
- [Morris Traversa Inorder](Morris_Traversal/MorrisTraversal_Inorder.cpp)\

    MorrisTraversal_Inorder, by using Morris traversal, we can traverse the tree without using stack and recursion. In this traversal, we first create links to Inorder successor and print the data using these links, and finally revert the changes to restore the original tree.
    
    Time complexity = O(n)

- [Morris Traversal Preorder](Morris_Traversal/MorrisTraversal_Preorder.cpp)

    the algorithm for Preorder is almost similar to Morris traversal for Inorder. 1. If  left child is null, print the current node data. Move to right child. Else, make the right child of the Inorder predecessor point to the current node. Two cases arise, first the right child of the Inorder predecessor already points to the current node. Set right child to NULL. Move to right child of current node. Or the right child is null. So set it to current node. Print current node’s data and move to left child of current node. 2. Iterate until current node is not NULL. 

    Time complexity = O(n)

- [AVL Tree](AVL_Tree.cpp)

    AVL_Tree is a self-balancing Binary Search Tree where the difference between heights of left and right subtrees cannot be more than one for all nodes.

    Time complexity = O(log n)  

- [Binary Search Tree Implement](Construct_Tree_from_given_Inorder_and_Preorder_traversals.cpp)

    Binary_Search_Tree_Implementation, BST is a type of data structure typically used to organize data. Below are properties that BST have 1. The tree has a root node that is used as the starting point for any operation. 2. Each node in the tree has one or two nodes attached to it. One is to the right of the node, and the other is to the left. 3. Everything to the right of a node is larger in value compared to it. Everything to the left of a node is smaller in value compared to it.  

Time complexity = O(h) (h represent height of BST)

- [Construct Tree from given Inorder and Preorder traversals](Construct_Tree_from_given_Inorder_and_Preorder_traversals.cpp)

    Construct_Tree_from_given_Inorder_and_Preorder_traversals, For example there are traversals : Inorder sequence => D B E A F C, Preorder sequence => A B D E C F, in a preorder sequence, leftmost element is the root of the tree. So we know ‘A’ is the root for a given sequence. By searching ‘A’ in inorder sequence, we can find out all elements on the left side of ‘A’ are in the left subtree and elements on the right are in the right subtree.

    Time complexity = O(n^2)

- [Euler Tree FLattening](Euler_tree_flattening.cpp)

    Euler_tree_flattening, Euler tour is defined as a way of traversing a tree such that each vertex is added to the tour when we visit it( either moving down from parent vertex or returning from child vertex). We start from root and reach back to root after visiting all vertices.

    Time complexity = O(n)

- [Expression Tree](ExpressionTree.cpp)
    ExpressionTree is a binary tree in which each internal node corresponds to the operator and each leaf node corresponds to the operand. Two common types of expressions that a binary expression tree can represent are algebraic and boolean. These trees can represent expressions that contain both unary and binary operators.
    
    Time complexity = O(n)

- [Fenwick Tree](fenwick_tree.cpp)

    fenwick_tree is a data structure that can efficiently update elements and calculate prefix sums in a table of numbers. When compared with a flat array of numbers, the fenwick tree achieves a much better balance between two operations, which is element update and prefix sums.

    Time complexity = O(Mlog N) (M represent number of operations, N represent number of elements)

- [Huffman Decoding](huffman_decoding.cpp)

    huffman_decoding, to decode the encoded data, we require the Huffman tree. We iterate through the binary encoded data. These are step to find character corresponding to current bits. 1. We start from root and do following until a leaf is found. 2. If current bit is 0, we move to left node of the tree. 3. If the bit is 1, we move to right node of the tree. 4. If during traversal, we encounter a leaf node, we print character of that particular leaf node and then again continue the iteration of the encoded data staring from step 1. 
    
    Time complexity = O(nlog n)

- [LCA Binary Lifting](LCA_binary_lifting.cpp)

    LCA_binary_lifting, given a binary tree, we have to find the Lowest Common Ancestor of the given two nodes in the tree. We set G as a tree then LCA of two nodes u and v is defined as the node w in the tree which is an ancestor of both u and v and is farthest from the root node. If one node is the ancestor of another one than that particular node is the LCA of those two nodes. 

    Time complexity = O(nlog n)

- [Segment Tree for Max Subsequnce(Cont) for range queries](Segment%20tree%20for%20max%20subsequnce(cont)%20for%20range%20queries.cpp)

    segment tree for max subsequence(cont) for range queries, segment tree, also known as a static tree, is a tree data structure used for storing information about intervals, or segments. With a given array of n numbers, for example if there is a function maximumSubarraySum(start,end), we have to find the maximum subarray sum in the range from array index ‘start’ to ‘end’ 

    Time complexity = O(log n) for each query

- [Segment Tree with Lazy Propagation.cpp](Segment_Tree_with_Lazy_Propagation.cpp)

    Segment_Tree_with_Lazy_Propagation, lazy propagation which is an optimization to make range updates faster. When there are many updates and updates are done on a range, we can postpone some updates(avid recursive calls in update) and do those updates only when required.

    Time complexity = O(logN) (N represent range)


