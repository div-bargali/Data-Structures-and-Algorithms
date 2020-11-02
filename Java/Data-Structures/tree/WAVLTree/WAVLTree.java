package WAVLTree;

import java.util.Arrays;
import java.util.Random;

/**
 * WAVLTree
 * <p>
 * An implementation of a WAVL Tree.
 * (Haupler, Sen & Tarajan ‘15)
 */

public class WAVLTree {
    private WAVLNode root;
    private WAVLNode external;

    public WAVLTree() {
        this.root = null;
        this.external = new WAVLNode(-1, null, null, null, null);
        external.rank = -1;
        external.size = 0;
    }

    /**
     * public boolean empty()
     * <p>
     * returns true if and only if the tree is empty
     */


    public boolean empty() {
        return (root == null);
    }

    /**
     * public String search(int k)
     * <p>
     * returns the info of an item with key k if it exists in the tree
     * otherwise, returns null
     */
    private WAVLNode recSearch(int k, WAVLNode node) {
        if (node.getKey() == k) { //we found
            return node;
        } else if (node.getKey() > k) {
            if (node.children[0] == external) {
                return node;
            } else {
                return recSearch(k, node.children[0]);
            }
        } else {
            if (node.children[1] == external) {
                return node;
            } else {
                return recSearch(k, node.children[1]);
            }
        }
    }

    public String search(int k) {
        if (empty()) return null;
        WAVLNode res = recSearch(k, root);
        if (res.getKey() == k) {
            return res.getValue();
        } else return null;
    }

    private void updateNodeBranchAfterRebalance(WAVLNode node) {
        while (node != null) {
            updateSubTreeSize(node);
            node = node.parent;
        }
    }

    private void updateSubTreeSize(WAVLNode node) {
        if (node != external) {
            node.setSize(node.children[0].getSubtreeSize() + 1 + node.children[1].getSubtreeSize());
        } else {
            node.setSize(0);
        }

    }

    /***
     *
     *public void promote (WAVLNode nodeParent , WAVLNode nodeChild)
     *
     * Increases the rank of one of the nodes in the tree which is being affected
     * by the problematic situation
     *
     */
    private int promote(WAVLNode node) {
        int op = 1;
        node.rank += 1;
        if (node != root) {
            if (!node.parent.isValidNodeType()) { //parent type = [0,1],[1,0],[0,2],[2,0]
                int[] type = node.parent.getNodeType();
                if (type[0] == 1 || type[1] == 1) { //parent type = [0,1],[1,0]
                    op += promote1(node);
                } else { // parent type = [0,2],[2,0]
                    op += promote2(node);
                }
            }
        }
        return op;

    }

    private int promote1(WAVLNode node) { //parent type = [1,0] or [0,1]
        int op = 0;
        if (node.parent == this.root) {
            node.parent.rank += 1;
            op += 1;
        } else {
            op += promote(node.parent);
        }
        return op;

    }

    private int promote2(WAVLNode node) { //parent type = [2,0] or [0,2]
        int op = 0;
        op += insertBalance(node.parent, node);
        return op;

    }

    /***
     *
     *public void demote (WAVLNode nodeParent , WAVLNode nodeChild)
     *
     * Decreases the rank of one of the nodes in the tree which is being affected
     * by the problematic situation
     *
     */
    private int demote(WAVLNode node) {
        int op = 1;
        node.rank -= 1;
        if (node != root) {
            WAVLNode parent = node.parent;
            int[] type = parent.getNodeType();
            if (!parent.isValidNodeType()) { //parent type = [3,1],[1,3],[3,2],[2,3]
                if (type[0] == 1 || type[1] == 1) { //parent type = [3,1] or [1,3]
                    op += demote1(node);
                } else { //parent type = [3,2] or [2,3]
                    op += demote2(node);
                }
            }
        }
        return op;
    }

    private int demote1(WAVLNode node) {//parent type = [1,3] or [3,1]
        int op = 0;
        op += deleteBalance(node.parent, node);
        return op;
    }

    private int demote2(WAVLNode node) {//parent type = [2,3] or [3,2]
        int op = 0;
        if (node.parent == this.root) {
            node.parent.rank -= 1;
            op += 1;
        } else {
            op += demote(node.parent);
        }
        return op;
    }

    /***
     *
     *public void rotate (WAVLNode nodeParent , WAVLNode nodeChild)
     *
     * Makes one rotate of the tree so the result is a balanced WAVL tree
     *
     */

    private int rotate(WAVLNode parent, WAVLNode child) {
        int op = 1;
        WAVLNode grand = parent.parent;
        int i = 0;
        if (child == parent.getRight()) {
            i = 1;
        }
        if (parent == root) { //grand = null
            root = child;
        } else {
            if (parent == grand.getLeft()) {
                grand.children[0] = child;
            } else {
                grand.children[1] = child;
            }
        }
        child.parent = grand;
        if (i == 0) {
            rotateLeft(parent, child);
        } else {
            rotateRight(parent, child);
        }
        parent.parent = child;
        int p_rank = parent.rank;
        int c_rank = child.rank;
        parent.setRank();
        child.setRank();
        op += Math.abs(p_rank-parent.rank);
        op += Math.abs(c_rank-child.rank);
        updateSubTreeSize(parent);
        updateSubTreeSize(child);
        return op;
    }

    private void rotateLeft(WAVLNode parent, WAVLNode child) {
        parent.children[0] = child.children[1];
        child.children[1].parent = parent;
        child.children[1] = parent;

    }

    private void rotateRight(WAVLNode parent, WAVLNode child) {
        parent.children[1] = child.children[0];
        child.children[0].parent = parent;
        child.children[0] = parent;
    }


    /***
     *
     *public void doubleRotate (WAVLNode[] problematic vertex)
     *
     * Makes two rotates of the tree so the result is a balanced WAVL tree
     *
     */
    private int doubleRotate(WAVLNode parent, WAVLNode node) {
        int op = 2;
        WAVLNode child;
        if (node == parent.children[0]) {
            child = node.children[1];
        } else {
            child = node.children[0];
        }
        op += rotate(node, child);
        op += rotate(parent, child);
        return op;
    }

    //parent.getRank()==child.getRank()
    private int insertBalance(WAVLNode parent, WAVLNode node) {
        int op = 0;
        int[] type = node.getNodeType();
        if (parent.children[0] == node) { //node is left child
            if (type[0] == 1) { //node type = [1,1] or [1,2]
                op += rotate(parent, node);
            } else {//node type = [2,1] (or [2,2])
                op += doubleRotate(parent, node);
            }
        } else { //node is right child
            if (type[1] == 1) { //node type = [1,1] or [2,1]
                op += rotate(parent, node);
            } else { //node type = [1,2] (or [2,2])
                op += doubleRotate(parent, node);
            }
        }
        return op;
    }

    /**
     * public int insert(int k, String i)
     * <p>
     * inserts an item with key k and info i to the WAVL tree.
     * the tree must remain valid (keep its invariants).
     * returns the number of rebalancing operations, or 0 if no rebalancing operations were necessary.
     * returns -1 if an item with key k already exists in the tree.
     */
    public int insert(int k, String i) {
        int op = 0;
        if (this.empty()) {
            this.root = new WAVLNode(k, i, null, external, external);
            return op;
        } else { //not empty
            WAVLNode parent = recSearch(k, root); //return node suppose parent if not found

            if (parent.getKey() == k) { //already exist
                return -1;
            } else { //parent is a leaf or unary
                boolean isInnerNode = parent.isInnerNode(); //parent is unary
                WAVLNode child = new WAVLNode(k, i, parent, external, external);
                if (k < parent.getKey()) {
                    parent.children[0] = child;
                } else {
                    parent.children[1] = child;
                }
                if (!isInnerNode) { //parent was a leaf
                    op += promote(parent);
                }
                updateNodeBranchAfterRebalance(parent);
            }
        }
        return op;
    }

    //parent.getRank()-child.getRank() = 3
    private int deleteBalance(WAVLNode parent, WAVLNode child) {
        int op = 0;
        int j = 0;
        if (child == parent.children[0]) {
            j = 1;
        }
        WAVLNode sibling = parent.children[j];
        if (parent.getRank() - sibling.getRank() == 2) {
            op += demote(parent);
        } else {
            int[] type = sibling.getNodeType();
            if (type[0] == 2 && type[1] == 2) {
                op += demote(sibling);
            } else if (type[j] == 1) {
                op += rotate(parent, sibling);
            } else {
                op += doubleRotate(parent, sibling);
            }
        }
        return op;
    }

    /**
     * public int delete(int k)
     * <p>
     * deletes an item with key k from the binary tree, if it is there;
     * the tree must remain valid (keep its invariants).
     * returns the number of rebalancing operations, or 0 if no rebalancing operations were needed.
     * returns -1 if an item with key k was not found in the tree.
     */
    public int delete(int k) {
        if (empty()) {
            return -1;
        }
        int op = 0;
        WAVLNode node = recSearch(k, root);
        WAVLNode parent = node.parent;
        int i = 0;
        if (node != root) {
            if (node == parent.children[1]) {
                i = 1;
            }
        }
        if (node.key != k) {
            return -1;
        }
        if (node.isInnerNode()) {
            if (node.children[0] != external && node.children[1] != external) {//full
                op += delete2(node, i);
            } else {//unary
                op += delete1(node, parent, i);
            }
        } else {//leaf
            op += delete0(node, parent, i);
        }
        return op;
    }

    private int delete0(WAVLNode node, WAVLNode parent, int i) {//leaf
        int op = 0;
        if (node == root) {
            root = null;
        } else {
            parent.children[i] = external;
            if (parent.getRank() - node.getRank() == 1) {
                if (!parent.isValidNodeType()) {
                    updateNodeBranchAfterRebalance(parent);
                    op += demote(parent);
                }
            } else {
                updateNodeBranchAfterRebalance(parent);
                op += deleteBalance(parent, external);
            }
        }
        return op;
    }

    private int delete1(WAVLNode node, WAVLNode parent, int i) {//unary
        int op = 0;
        WAVLNode child;
        if (node.children[1] == external) {
            child = node.children[0];
        } else {
            child = node.children[1];
        }
        if (node == root) {
            root = child;
            child.parent = null;
        } else {
            child.parent = parent;
            parent.children[i] = child;
            if (parent.getRank() - child.getRank() == 3) {
                updateNodeBranchAfterRebalance(parent);
                op += deleteBalance(parent, child);
            }
        }
        return op;
    }

    private int delete2(WAVLNode node, int i) {//full
        int op = 0;
        WAVLNode successor = successor(node);
        op += delete(successor.key);
        if (node == root) {
            root = successor;
            successor.parent = null;
        } else {
            node.parent.children[i] = successor;
        }
        node.children[0].parent = successor;
        node.children[1].parent = successor;
        successor.children = node.children;
        successor.setRank();
        updateNodeBranchAfterRebalance(successor);
        return op;
    }


    /**
     * public String min()
     * <p>
     * Returns the info of the item with the smallest key in the tree,
     * or null if the tree is empty
     */
    public String min() {
        if (empty()) return null;
        WAVLNode temp = root;
        while (temp.children[0] != external) {
            temp = temp.children[0];
        }
        return temp.getValue();
    }

    public int minKey() {
        if (empty()) return -1;
        WAVLNode temp = root;
        while (temp.children[0] != external) {
            temp = temp.children[0];
        }
        return temp.getKey();
    }

    /**
     * public String max()
     * <p>
     * Returns the info of the item with the largest key in the tree,
     * or null if the tree is empty
     */
    public String max() {
        if (empty()) return null;
        WAVLNode temp = root;
        while (temp.children[1] != external) {
            temp = temp.children[1];
        }
        return temp.getValue();
    }

    private WAVLNode successor(WAVLNode node) {
        if (node.getRight() != external) {
            return node.getRight().minNodeInSub();
        } else {
            while (node.parent != null && node == node.parent.getRight()) {
                node = node.parent;
            }
            return node.parent;
        }
    }

    /**
     * public int[] keysToArray()
     * <p>
     * Returns a sorted array which contains all keys in the tree,
     * or an empty array if the tree is empty.
     */
    public int[] keysToArray() {
        if (empty()) return new int[0];
        int[] arr = new int[root.getSubtreeSize()];
        WAVLNode temp = root.minNodeInSub();
        arr[0] = temp.getKey();
        for (int i = 1; i < root.getSubtreeSize(); i++) {
            temp = successor(temp);
            arr[i] = temp.getKey();
        }
        return arr;
    }


    /**
     * public String[] infoToArray()
     * <p>
     * Returns an array which contains all info in the tree,
     * sorted by their respective keys,
     * or an empty array if the tree is empty.
     */
    public String[] infoToArray() {
        if (empty()) return new String[0];
        String[] arr = new String[root.getSubtreeSize()];
        WAVLNode temp = root.minNodeInSub();
        arr[0] = temp.getValue();
        for (int i = 1; i < root.getSubtreeSize(); i++) {
            temp = successor(temp);
            arr[i] = temp.getValue();
        }
        return arr;
    }

    /**
     * public int size()
     * <p>
     * Returns the number of nodes in the tree.
     */
    public int size() {
        if (empty()) return 0;
        return root.getSubtreeSize();
    }

    /**
     * public WAVLNode getRoot()
     * <p>
     * Returns the root WAVL node, or null if the tree is empty
     */
    public WAVLNode getRoot() {
        return root;
    }

    /**
     * public int select(int i)
     * <p>
     * Returns the value of the i'th smallest key (return -1 if tree is empty)
     * Example 1: select(1) returns the value of the node with minimal key
     * Example 2: select(size()) returns the value of the node with maximal key
     * Example 3: select(2) returns the value 2nd smallest minimal node, i.e the value of the node minimal node's successor
     */
    public String select(int i) {
        if (size() < i || empty()) return null;
        WAVLNode temp = root.minNodeInSub();
        for (int j = 1; j < i; j++) {
            temp = successor(temp);
        }
        return temp.getValue();
    }

    /**
     * public class WAVLNode
     */
    public class WAVLNode {
        private int key;
        private String value;
        private WAVLNode parent;
        private WAVLNode[] children = {null, null};
        private int rank;
        private int size;

        private WAVLNode(int k, String v, WAVLNode p, WAVLNode ln, WAVLNode rn) {
            this.key = k;
            this.value = v;
            this.parent = p;
            this.children[0] = ln;
            this.children[1] = rn;
            this.rank = 0;
            this.size = 1;
        }


//TODO
//        public int updateSubTreeSize(WAVLNode node){
//            if (node==null){
//                return 0;
//            }
//            else {
//                return updateSubTreeSize(node.children[0])+updateSubTreeSize(node.children[1])+1;
//            }
//        }

        /**
         * sets the size of the subtree in which node is the root
         */

        private void setSize(int size) {
            this.size = size;
        }

        int getRank() {
            return rank;
        }

        private int setRank() {
            rank = Math.max(children[0].getRank(), children[1].getRank()) + 1;
            return rank;
        }

        public int getKey() {
            return key;
        }

        public String getValue() {
            return value;
        }

        public WAVLNode getLeft() {
            if (children[0]==external){
                return null;
            }
            return children[0];
        }

        public WAVLNode getRight() {
            if (children[1]==external){
                return null;
            }
            return children[1];
        }

        public boolean isInnerNode() {
            if (this == external) {
                return false;
            }
            for (int i = 0; i < 2; i++) {
                if (children[i] != external) {
                    return true;
                }
            }
            return false;
        }

        public int getSubtreeSize() {
            return size;
        }

        private WAVLNode minNodeInSub() {
            WAVLNode temp = this;
            while (temp.children[0] != external) {
                temp = temp.children[0];
            }
            return temp;
        }

        private int[] getNodeType() {
            int[] arr = new int[2];
            for (int i = 0; i < 2; i++) {
                arr[i] = rank - this.children[i].rank;
            }
            return arr;
        }

        private boolean isValidNodeType() {
            int[] type = this.getNodeType();
            if ((type[0] == 1 || type[0] == 2) && (type[1] == 1 || type[1] == 2)) {
                return (this.isInnerNode() || (type[0] == 1 && type[1] == 1));
            }
            return false;
        }


    }


    private String recDisplay(WAVLNode node) {
        if (node == null || node == external) {
            return "";
        }
        StringBuilder str = new StringBuilder("");
        str.append("[" + node.key + ":" + node.rank + "[left" + recDisplay(node.children[0]) + ", right" + recDisplay(node.children[1]) + "]]");
        return str.toString();
    }

    public void display(WAVLTree tree) {
        System.out.println(recDisplay(tree.getRoot()));
    }


    // WAVER Tester

    private static final boolean DISPLAY_SUBTREESIZE = false;

    public void display() {
        display(!DISPLAY_SUBTREESIZE);
    }

    public void display(boolean displayRank) {
        final int height = root.rank * 2 + 2, width = (root.size + 1) * 12;

        int len = width * height * 2 + 2;
        StringBuilder sb = new StringBuilder(len);
        for (int i = 1; i <= len; i++)
            sb.append(i < len - 2 && i % width == 0 ? "\n" : ' ');

        displayR(sb, width / 2, 1, width / 4, width, root, " ", displayRank);
        System.out.println(sb);
    }

    private void displayR(StringBuilder sb, int c, int r, int d, int w, WAVLNode n, String edge, boolean displayRank) {
        if (n != null) {
            displayR(sb, c - d, r + 2, d / 2, w, n.children[0], " /", displayRank);

            String s = (displayRank) ? String.valueOf(n.key) + "[" + n.size + "]" : String.valueOf(n.key) + "[" + n.rank + "]";
            int idx1 = r * w + c - (s.length() + 1) / 2;
            int idx2 = idx1 + s.length();
            int idx3 = idx1 - w;
            if (idx2 < sb.length())
                sb.replace(idx1, idx2, s).replace(idx3, idx3 + 2, edge);

            displayR(sb, c + d, r + 2, d / 2, w, n.children[1], "\\ ", displayRank);
        }
    }


    public static int WAVLCheckRank(WAVLTree.WAVLNode t) {
        if (t == null)
            return 1;
        if (t.getLeft() != null) {
            if (t.getRank() - t.getLeft().getRank() > 2)
                return 0;
            if (t.getRank() == t.getLeft().getRank())
                return 0;
        } else {
            if (t.getRank() - -1 > 2)
                return 0;
            if (t.getRank() == -1)
                return 0;
        }
        if (t.getRight() != null) {
            if (t.getRank() - t.getRight().getRank() > 2)
                return 0;

            if (t.getRank() == t.getRight().getRank())
                return 0;
        } else {
            if (t.getRank() - -1 > 2)
                return 0;

            if (t.getRank() == -1)
                return 0;
        }


        if (t.getLeft() != null && t.getRight() != null) {
            return WAVLCheckRank(t.getRight()) * WAVLCheckRank(t.getLeft());
        }
        if (t.getLeft() == null && t.getRight() == null) {
            return 1;
        }
        if (t.getLeft() != null && t.getRight() == null) {
            return WAVLCheckRank(t.getLeft());
        }
        if (t.getLeft() == null && t.getRight() != null) {
            return WAVLCheckRank(t.getRight());
        }
        return 0;

    }

    public static int WAVLCheckSize(WAVLTree.WAVLNode t) {

        if (t.getRank() == -1) {
            return 1;
        }
        if (t.getLeft() != null && t.getRight() != null) {
            if (t.getSubtreeSize() != t.getLeft().getSubtreeSize() + t.getRight().getSubtreeSize() + 1) {
                return 0;
            }
        }
        if (t.getLeft() == null && t.getRight() == null) {
            if (t.getSubtreeSize() != 1) {
                return 0;
            }
        }
        if (t.getLeft() != null && t.getRight() == null) {
            if (t.getSubtreeSize() != t.getLeft().getSubtreeSize() + 1) {
                return 0;
            }
        }
        if (t.getLeft() == null && t.getRight() != null) {
            if (t.getSubtreeSize() != t.getRight().getSubtreeSize() + 1) {
                return 0;
            }
        }

        if (t.getLeft() != null && t.getRight() != null) {
            return WAVLCheckSize(t.getRight()) * WAVLCheckSize(t.getLeft());
        }
        if (t.getLeft() == null && t.getRight() == null) {
            return 1;
        }
        if (t.getLeft() != null && t.getRight() == null) {
            return WAVLCheckSize(t.getLeft());
        }
        if (t.getLeft() == null && t.getRight() != null) {
            return WAVLCheckSize(t.getRight());
        }
        return 0;
    }


    public static void main(String[] args) {
        WAVLTree t = new WAVLTree();
        for (int j = 1; j <= 10; j++) {
            int[] integers = new int[j * 100000];
            Random gen = new Random();
            for (int i = 0; i < integers.length; i++) {
                integers[i] = Math.abs(gen.nextInt());

            }

            int max_insert = 0;
            int max_delete = 0;
            int res;
            int sum_insert = 0;
            int sum_delete = 0;

            for (int i = 0; i < integers.length; i++) {
                res = t.insert(integers[i], "");
//            if (WAVLCheckSize(t.root) != 1){
//                System.out.println("i ERROR");
//            }
//            if (WAVLCheckRank(t.root) != 1){
//                System.out.println("i ERROR");
//            }
                if (res > max_insert) {
                    max_insert = res;
                }
                sum_insert += res;
            }

            if (WAVLCheckSize(t.root) != 1) {
                System.out.println("i ERROR");
            }
            if (WAVLCheckRank(t.root) != 1) {
                System.out.println("i ERROR");
            }

            System.out.println("sizes :" + WAVLCheckSize(t.root));
            System.out.println("ranks :" + WAVLCheckRank(t.root));


            Arrays.sort(integers);
            for (int i = 0; i < integers.length; i++) {
                res = t.delete(integers[i]);
//            if (t.root != null) {
//                if (WAVLCheckSize(t.root) != 1) {
//                    System.out.println("d ERROR");
//                }
//                if (WAVLCheckRank(t.root) != 1) {
//                    System.out.println("d ERROR");
//                }
//            }
                if (res > max_delete) {
                    max_delete = res;
                }
                sum_delete += res;
            }

            System.out.println("j= " + j * 10000 + " max_insert: " + max_insert + " sum_insert: " + sum_insert + " insert avg: " + (float) sum_insert / integers.length);
            System.out.println("j= " + j * 10000 + " max_delete: " + max_delete + " sum_delete: " + sum_delete + " delete avg: " + (float) sum_delete / integers.length);
            System.out.println("--------------");

        }

    }


}

