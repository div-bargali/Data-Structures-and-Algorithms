package WAVLTree;

public class PrintTree {
    public static void main(String[] args) {
        WAVLTree tree = new WAVLTree();
        tree.insert(100, null);
        tree.insert(50, null);
        tree.insert(150, null);
        tree.insert(30, null);
        tree.insert(70, null);
        tree.insert(130, null);
        tree.insert(170, null);
        tree.insert(10, null);
        tree.insert(120, null);
        tree.insert(140, null);
        tree.delete(10);
        tree.delete(70);
        tree.delete(30);
        tree.display(tree);
    }
}