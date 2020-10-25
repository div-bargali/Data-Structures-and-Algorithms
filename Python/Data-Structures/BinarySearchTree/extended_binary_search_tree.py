from binary_search_tree import Node

# This builds on top of the basic binary_search_tree Node
# with extra functionality:
# - parents
# - root
# - find, and
# - rotate!

class ExtendedNode(Node):

    def __init__(self,val):
        self.value = val
        self.left = None
        self.right = None
        self.parent = self

    # Returns a string that represents the tree
    def __repr__(self):
        return "{left: "+str(self.left)+", value: "+str(self.value)+", right: "+str(self.right)+"}"

    # Finds the root of the node
    def root(self):
        r = self
        while r.parent != r:
            r = r.parent
        return r

    # Finds whether a particular value
    # is in the tree whose root is self
    def find(self,val):
        curr = self
        while curr!=None:
            if curr.value == val:
                return curr
            elif val < curr.value:
                curr = curr.left
            else:
                curr = curr.right
        return curr.parent

    # Overloads insert from Node
    def insert(self, node):
        super().insert(node)
        if self.left==node or self.right==node:
            node.parent = self


    # Rotates tree in L(eft) or R(ight)
    # dir is to indicate the direction the ROOT is going
    # so t        l
    #   / \   ->   \
    #  l   r        t
    #                \
    #                 r
    # can be performed by calling t.rotate("r")
    # and the reverse is performed by calling l.rotate("l")

    # Note that in either case t is the particular node,
    # and need NOT remain the root of the tree.
    # To go to the root you will have to call t.root()
    def rotate(self,direction):
        if self.parent==self:
            parentSide = "o"
        elif self.value < self.parent.value:
            parentSide = "l"
            prevParent = self.parent
        else:
            parentSide = "r"
            prevParent = self.parent
        assert type(direction)==str and direction.lower() in 'lr', "Direction should be L/l/R/r"
        if direction.lower() == "l":
            assert self.right!=None, "Node {} has no right child:\n{}".format(self.value,self)
            holder = self.right
            if self.right.left:
                self.right = self.right.left
                self.right.parent = self
            else:
                self.right = None
            assert holder!=self.right, "Hmm..."
            self.parent = holder
            self.parent.left = self
        else:
            assert self.left!=None, "Node {} has no left child:\n{}".format(self.value,self)
            holder = self.left
            if self.left.right:
                self.left = self.left.right
                self.left.parent = self
            else:
                self.left = None
            assert holder!=self.left, "Hmm..."
            self.parent = holder
            self.parent.right = self
        if parentSide=="o":
            self.parent.parent = self.parent
        elif parentSide=="l":
            prevParent.left = self.parent
            self.parent.parent = prevParent
        else:
            prevParent.right = self.parent
            self.parent.parent = prevParent
        assert self.parent.left==self or self.parent.right==self, "self not a child of parent:\nSelf:\n{}\nParent:\n{}".format(self, self.parent)
        