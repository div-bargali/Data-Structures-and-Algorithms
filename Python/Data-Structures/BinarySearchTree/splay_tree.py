from extended_binary_search_tree import ExtendedNode

# This implements a splay tree
# with functions:
# - splay
# - delete
# which are not in the basic binary search tree

class SplayNode(ExtendedNode):

    def __init__(self, val):
        super().__init__(val)
    
    # Splays a node, i.e. moves it to the root
    # with a series of rotations.
    # Note this does NOT naively rotate the node.
    def splay(self,node):
        while node.parent != node:
            # print(node.parent.parent, node)
            if node.parent.parent == node.parent:
                if node.value > node.parent.value:
                    node.parent.rotate("l")
                else:
                    node.parent.rotate("r")
            else:
                isRightChild = node.parent.right == node
                if node.parent.parent.right==node.parent and isRightChild:
                    node.parent.parent.rotate("l")
                    node.parent.rotate("l")
                elif node.parent.parent.left==node.parent and not isRightChild:
                    node.parent.parent.rotate("r")
                    node.parent.rotate("r")
                elif isRightChild:
                    node.parent.rotate("l")
                    node.parent.rotate("r")
                else:
                    node.parent.rotate("r")
                    node.parent.rotate("l")

    # Overloads find
    def find(self, val):
        node = super().find(val)
        self.splay(node)
        return node

    # Overloads insert
    def insert(self, node):
        super().insert(node)
        self.splay(node)

    # Implements deleting a value
    # from the tree rooted at self
    def delete(self, val):
        node = self.find(val)
        if node.value != val:
            return False
        assert node.root()==node, "Node is not root: {} {}".format(node,node.root())
        if node.left != None:
            l = node.left
            newRoot = l
            while newRoot.right != None:
                newRoot = newRoot.right
            l.splay(newRoot)
            newRoot.right = node.right
            if newRoot.right:
                newRoot.right.parent = newRoot
            newRoot.parent = newRoot
            del node
            return True
        else:
            r = node.right
            newRoot = r
            while newRoot.left != None:
                newRoot = newRoot.left
            r.splay(newRoot)
            newRoot.left = node.left
            if newRoot.left:
                newRoot.left.parent = newRoot
            newRoot.parent = newRoot
            del node
            return True

# An example for reference:
# if __name__ == "__main__":
#     t = SplayNode(5)
#     for i in [3,7,2,6,4]:
#         t.root().insert(SplayNode(i))
#     t = t.root()
#     print("Full tree:")
#     print(t)
#     t.delete(6)
#     t = t.root()
#     print("w/o 6:")
#     print(t)
#     t.delete(2)
#     t = t.root()
#     print("w/o 2:")
#     print(t)