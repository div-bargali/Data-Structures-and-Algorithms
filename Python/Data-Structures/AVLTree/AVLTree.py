class AVLTree:

    # tree node class
    class Node:
        def __init__(self, val, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right

        # function for rotate right at given node
        def rotate_right(self):
            n = self.left
            self.val, n.val = n.val, self.val
            self.left, n.left, self.right, n.right = n.left, n.right, n, self.right

        # function for rotate left at given node
        def rotate_left(self):
            n = self.right
            self.val, n.val = n.val, self.val
            self.right, n.right, self.left, n.left = n.right, n.left, n, self.left

        # return the height of the node
        @staticmethod
        def height(n):
            if not n:
                return 0
            return max(1+AVLTree.Node.height(n.left), 1+AVLTree.Node.height(n.right))

    def __init__(self):
        self.root = None
        self.size = 0

    # return True if value is in the tree, otherwise False
    def __contains__(self, val):
        def contains_rec(node):
            if not node:
                return False
            elif val < node.val:
                return contains_rec(node.left)
            elif val > node.val:
                return contains_rec(node.right)
            else:
                return True
        return contains_rec(self.root)

    # return the number of elements in the tree
    def __len__(self):
        return self.size

    # return the height of the tree
    def height(self):
        def height_rec(t):
            if not t:
                return 0
            return max(1+height_rec(t.left), 1+height_rec(t.right))
        return height_rec(self.root)

    # function for balancing the tree
    @staticmethod
    def rebalance(t):
        if AVLTree.Node.height(t.left) > AVLTree.Node.height(t.right):
            if AVLTree.Node.height(t.left.left) >= AVLTree.Node.height(t.left.right):
                # left-left
                t.rotate_right()
            else:
                # left-right
                t.left.rotate_left()
                t.rotate_right()
        elif AVLTree.Node.height(t.right) > AVLTree.Node.height(t.left):
            if AVLTree.Node.height(t.right.right) >= AVLTree.Node.height(t.right.left):
                # right-right
                t.rotate_left()
            else:
                # right-left
                t.right.rotate_right()
                t.rotate_left()

    # function for adding values to the tree
    def add(self, val):
        assert val not in self
        def add_rec(node):
            if not node:
                return AVLTree.Node(val)
            elif val < node.val:
                node.left = add_rec(node.left)
            else:
                node.right = add_rec(node.right)
            if abs(AVLTree.Node.height(node.left) - AVLTree.Node.height(node.right)) >= 2:
                AVLTree.rebalance(node)
            return node
        self.root = add_rec(self.root)
        self.size += 1

    # function for deleting values from the tree
    def __delitem__(self, val):
        assert val in self
        def delitem_rec(node):
            if val < node.val:
                node.left = delitem_rec(node.left)
            elif val > node.val:
                node.right = delitem_rec(node.right)
            else:
                if not node.left and not node.right:
                    return None
                elif node.left and not node.right:
                    return node.left
                elif node.right and not node.left:
                    return node.right
                else:
                    # remove the largest value from the left subtree (t) as a replacement
                    # for the root value of this tree
                    t = node.left
                    if not t.right:
                        node.val = t.val
                        node.left = t.left
                    else:
                        n = t
                        while n.right.right:
                            n = n.right
                        t = n.right
                        n.right = t.left
                        node.val = t.val
            if abs(AVLTree.Node.height(node.left) - AVLTree.Node.height(node.right)) >= 2:
                AVLTree.rebalance(node)
            return node

        self.root = delitem_rec(self.root)
        self.size -= 1

    # function for printing the tree
    def pprint(self, width=64):
        height = self.height()
        nodes  = [(self.root, 0)]
        prev_level = 0
        repr_str = ''
        while nodes:
            n, level = nodes.pop(0)
            if prev_level != level:
                prev_level = level
                repr_str += '\n'
            if not n:
                if level < height-1:
                    nodes.extend([(None, level+1), (None, level+1)])
                repr_str += '{val:^{width}}'.format(val='-', width=width//2**level)
            elif n:
                if n.left or level < height-1:
                    nodes.append((n.left, level+1))
                if n.right or level < height-1:
                    nodes.append((n.right, level+1))
                repr_str += '{val:^{width}}'.format(val=n.val, width=width//2**level)
        print(repr_str)

if __name__ == "__main__":

    # creating new tree
    tree = AVLTree()

    # adding elements to the tree
    while True:
        x = input("Enter value to add to the tree or 'q' to quit: ")
        if x == 'q':
            break

        if int(x) in tree:
            print(f"{x} is already in the tree")
        else:
            tree.add(int(x))

    # print the tree
    tree.pprint()

    # remove elements in the tree
    while True:
        x = input("Enter value to remove from the tree or 'q' to quit: ")
        if x == 'q':
            break

        if int(x) not in tree:
            print(f"{x} is not in the tree")
        else:
            tree.__delitem__(int(x))

    # print the tree
    tree.pprint()
