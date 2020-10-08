class AVLTree:
    class Node:
        def __init__(self, val, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right

        def rotate_right(self):
            n = self.left
            self.val, n.val = n.val, self.val
            self.left, n.left, self.right, n.right = n.left, n.right, n, self.right

        def rotate_left(self):
            n = self.right
            self.val, n.val = n.val, self.val
            self.right, n.right, self.left, n.left = n.right, n.left, n, self.left

        @staticmethod
        def height(n):
            if not n:
                return 0
            return max(1+AVLTree.Node.height(n.left), 1+AVLTree.Node.height(n.right))

    def __init__(self):
        self.root = None
        self.size = 0

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

    def __len__(self):
        return self.size

    def height(self):
        def height_rec(t):
            if not t:
                return 0
            return max(1+height_rec(t.left), 1+height_rec(t.right))
        return height_rec(self.root)

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
