import java.lang.Math;
/**
 * FibonacciHeap
 * <p>
 * An implementation of fibonacci heap over non-negative integers.
 */


public class FibonacciHeap {
    private HeapNode min = null;
    private int size = 0;
    private int marked = 0;
    static int links = 0;
    static int cuts = 0;

    /**
     * public boolean empty()
     * <p>
     * precondition: none
     * <p>
     * The method returns true if and only if the heap
     * is empty.
     */
    public boolean empty() {
        return min == null;
    }

    /**
     * public HeapNode insert(int key)
     * <p>
     * Creates a node (of type HeapNode) which contains the given key, and inserts it into the heap.
     */
    public HeapNode insert(int key) {
        HeapNode node = new HeapNode(key);
        if (!empty()) {
            this.concate(node, this.min, false);
        } else {
            this.min = node;
        }
        this.checkNDUpdateMin(node);
        size += 1;
        return node;
    }

    /**
     * public void deleteMin()
     * <p>
     * Delete the node containing the minimum key.
     */
    public void deleteMin() {

        if (size == 0) {
            return;
        }
        if (size == 1) {
            min = null;
        } else {
            HeapNode origMin = this.min;
            if (origMin.child != null) {
                this.concate(origMin.child, this.min, true);
            }
            this.min = this.min.next;
            this.disconnect(origMin);
            HeapNode first = this.min;
            HeapNode temp = first;
            do {
                if (temp.mark) {
                    marked -= 1;
                }
                temp.mark = false;
                checkNDUpdateMin(temp);
                temp.parent = null;
                temp = temp.next;
            } while (temp != first);
            this.successiveLinking();
        }
        this.size -= 1;
        return;

    }

    /*
    counts the number of trees in the heap
     */
    private int numOfTrees() {
        int count = 0;
        HeapNode first = this.min;
        HeapNode temp = first;
        if (!empty()) {
            do {
                count += 1;
                temp = temp.next;
            } while (temp != first);
        }
        return count;
    }

    /*
    compares the nodeToCheck.key to min.key to see if the nodeToCheck.key is the minimal
    key of the tree, and updates accordingly.
     */
    private void checkNDUpdateMin(HeapNode nodeToCheck) {
        if (nodeToCheck.getKey() < this.min.getKey()) {
            this.min = nodeToCheck;
        }
    }

    /**
     * public HeapNode findMin()
     * <p>
     * Return the node of the heap whose key is minimal.
     */
    public HeapNode findMin() {
        return this.min;
    }

    /**
     * public void meld (FibonacciHeap heap2)
     * <p>
     * Meld the heap with heap2
     */
    public void meld(FibonacciHeap heap2) {
        this.concate(heap2.min, this.min, true);
        this.checkNDUpdateMin(heap2.min);
        return;
    }


    /**
     * if concateAllList is true, it concatenates the list - nodeToConnect with this,
     * <p>
     * if concateAllList is false, it concatenates the single node - nodeToConnect with this
     */
    public void concate(HeapNode nodeToConnect, HeapNode listToConnect, boolean concateAllList) {
        HeapNode list1_first = listToConnect;
        HeapNode list2_first = nodeToConnect;
        HeapNode list1_last = listToConnect.prev;
        HeapNode list2_last = concateAllList ? nodeToConnect.prev : nodeToConnect;
        list1_first.prev = list2_last;
        list2_last.next = list1_first;
        list2_first.prev = list1_last;
        list1_last.next = list2_first;
    }

    /**
     * public int size()
     * <p>
     * Return the number of elements in the heap
     */
    public int size() {
        return this.size;
    }

    /**
     * public int[] countersRep()
     * <p>
     * Return a counters array, where the value of the i-th entry is the number of trees of order i in the heap.
     */
    public int[] countersRep() {
        int arrSize = 0;
        HeapNode nextNode = this.min;
        do {
            if (arrSize < nextNode.rank) {
                arrSize = nextNode.rank;
                nextNode = nextNode.next;
            }
        }
        while (nextNode != this.min);

        int[] arr = new int[arrSize + 1];
        HeapNode temp = this.min;
        do {
            int index = temp.rank;
            arr[index] += 1;
            temp = temp.next;
        } while (temp != this.min);
        return arr;
    }

    /**
     * public void delete(HeapNode x)
     * <p>
     * Deletes the node x from the heap.
     */
    public void delete(HeapNode x) {
        int NodeToDeleteKey = x.getKey();
        int NodeMinKey = min.getKey();

        decreaseKey(x, (1 + (NodeToDeleteKey - NodeMinKey)));
        deleteMin();
        return;

    }

    /**
     * public void decreaseKey(HeapNode x, int delta)
     * <p>
     * The function decreases the key of the node x by delta. The structure of the heap should be updated
     * to reflect this chage (for example, the cascading cuts procedure should be applied if needed).
     */
    public void decreaseKey(HeapNode x, int delta) {
        x.key -= delta;
        int nodeKey = x.getKey();
        if (x.parent != null) {
            int parentKey = x.parent.getKey();
            if (nodeKey < parentKey) {
                cascading(x);
            }
        }
        checkNDUpdateMin(x);
        return;
    }

    /*
     *makes the cascading cuts in decreaseKey
     *and updates the relevant fields
     */
    private void cascading(HeapNode nodeToCascade) {
        HeapNode parent = nodeToCascade.parent;
        disconnect(nodeToCascade);
        concate(nodeToCascade, this.min, false);
        if (nodeToCascade.mark) {
            this.marked -= 1;
            nodeToCascade.mark = false;
        }
        this.cuts += 1;
        if (parent.parent != null) { //parent is not a root
            if (parent.mark) {
                cascading(parent);
            } else {
                parent.mark = true;
                //parent.rank -= 1;
                this.marked += 1;
            }
        }
    }

    /*
     *disconnects the single node from his linkedList
     */
    private HeapNode disconnect(HeapNode nodeToDisconnect) {
        HeapNode parent = nodeToDisconnect.parent;
        /* if parent.child is nodeToDisconnect
        we would like parent.child to be the next child
        because we want to keep all the other elements in child*/
        if (parent != null) {
            parent.rank -= 1;
            if (parent.child == nodeToDisconnect) {
                parent.child = nodeToDisconnect.next;
                if (nodeToDisconnect.next == nodeToDisconnect) {
                    parent.child = null;
                }
            }
        }
        HeapNode prevNode = nodeToDisconnect.prev;
        HeapNode nextNode = nodeToDisconnect.next;
        prevNode.next = nextNode;
        nextNode.prev = prevNode;
        nodeToDisconnect.prev = nodeToDisconnect;
        nodeToDisconnect.next = nodeToDisconnect;
        nodeToDisconnect.parent = null;
        return nodeToDisconnect;
    }

    /**
     * public int potential()
     * <p>
     * This function returns the current potential of the heap, which is:
     * Potential = #trees + 2*#marked
     * The potential equals to the number of trees in the heap plus twice the number of marked nodes in the heap.
     */
    public int potential() {
        int trees = this.numOfTrees();
        return (trees + 2 * marked);
    }


    /*
     * makes a number of link operations which each gets as input two trees of the same rank,
     * and generates a tree of rank bigger by one,
     * by hanging the tree which has larger value in its root
     * on the tree which has smaller value in its root
     * Successive Linking - One Pass
     */
    private void successiveLinking() {
        int log = (int) (Math.log(size) / Math.log(2));
        HeapNode[] buckets = new HeapNode[log + 2];
        for (int ind = 0; ind < log + 2; ind++) {
            buckets[ind] = null;
        }
        HeapNode first = this.min;
        HeapNode curr = first;
        do {

            HeapNode temp = curr; //did it because curr may not stay at the roots list
            curr = curr.next;
            int i = temp.rank;
            if (buckets[i] == null) {
                buckets[i] = temp;
            } else {
                link(temp, buckets[i]);
                buckets[i] = null;
            }
        } while (curr != first);
    }

    /*
     * link two nodes with the same rank
     * the new root is the node with the smaller key
     * return the new root node
     */
    private HeapNode link(HeapNode node1, HeapNode node2) {
        HeapNode bigger = node1;
        HeapNode smaller = node2;
        if (node1.getKey() < node2.getKey()) { //check which node will be the root (the smaller)
            bigger = node2;
            smaller = node1;
        }
        disconnect(bigger); //disconnects the bigger from the roots list
        bigger.parent = smaller;
        if (smaller.child == null) {
            smaller.child = bigger;
        } else {
            concate(bigger, smaller.child, false); //join the node to the child list
        }
        smaller.rank += 1;
        links += 1;
        return smaller; //return the root
    }


    /**
     * public static int totalLinks()
     * <p>
     * This static function returns the total number of link operations made during the run-time of the program.
     * A link operation is the operation which gets as input two trees of the same rank, and generates a tree of
     * rank bigger by one, by hanging the tree which has larger value in its root on the tree which has smaller value
     * in its root.
     */
    public static int totalLinks() {
        return links;
    }

    /**
     * public static int totalCuts()
     * <p>
     * This static function returns the total number of cut operations made during the run-time of the program.
     * A cut operation is the operation which diconnects a subtree from its parent (during decreaseKey/delete methods).
     */
    public static int totalCuts() {
        return cuts;
    }

    /**
     * public class HeapNode
     * <p>
     * If you wish to implement classes other than FibonacciHeap
     * (for example HeapNode), do it in this file, not in
     * another file
     */
    public class HeapNode {

        public int key;
        int rank = 0;
        boolean mark = false;
        HeapNode child = null;
        HeapNode next = this;
        HeapNode prev = this;
        HeapNode parent = null;

        public HeapNode(int key) {
            this.key = key;
        }

        public int getKey() {
            return this.key;
        }

    }
}
