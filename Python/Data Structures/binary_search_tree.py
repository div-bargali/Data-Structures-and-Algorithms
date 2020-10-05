# Tree Node Class for BST
class Node:
  def __init__(self, val):
    self.value = val;
    self.left = None
    self.right = None

  # function to insert node into BST such that the left child is always smaller than the root
  # and the right child is always greater than the root
  def insert(self, node):
    if node.value >= self.value:
      if self.right == None:
        self.right = node
      else:
        self.right.insert(node)
    else:
      if self.left == None:
        self.left = node
      else:
        self.left.insert(node)

  # print tree using inorder traversal
  def printTree(self):
    if self != None:
      if self.left != None:
        self.left.printTree()
      print(self.value, end=' ')
      if self.right != None:
        self.right.printTree()

# driver code
if __name__ == "__main__":

  x = input("Enter root node:")
  tree = Node(int(x))

  # add nodes to the BST till 'q' is input
  while True:
    x = input("Enter value to add to the tree or q to quit:")
    if x == "q":
      break
    tree.insert(Node(int(x)))

  print("The BST input traversed inorder:")
  tree.printTree()
