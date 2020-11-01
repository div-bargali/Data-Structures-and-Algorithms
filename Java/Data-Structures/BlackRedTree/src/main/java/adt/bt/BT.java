package adt.bt;

/**
 * The interface of a generic binary tree (BT). It has nodes containing elements
 * of type T.
 */
public interface BT<T> {
	/**
	 * Returns the root of the tree.
	 * 
	 * @return
	 */
	public BTNode<T> getRoot();

	/**
	 * Say if a BT is empty (NIL).
	 */
	public boolean isEmpty();

	/**
	 * The height of a BT. An empty BT has height -1 (there is no root element).
	 * In non-empty BT the height is given by 1 + (the highest height of its
	 * sub-trees).
	 */
	public int height();

	/**
	 * Searches an element in a BT. The search starts at the root node. If the
	 * key does not exist the methods returns a NIL (empty) node.
	 */
	public BTNode<T> search(T elem);

	/**
	 * Inserts an element in a BT.
	 */
	public void insert(T value);

	/**
	 * Removes a node from a BT.
	 */
	public void remove(T key);

	/**
	 * Returns an array of elements filled according to the pre-order traversing
	 * in a BT.
	 */
	public T[] preOrder();

	/**
	 * Returns an array of elements filled according to the symmetric order
	 * traversing in a BT.
	 */
	public T[] order();

	/**
	 * Returns an array of elements filled according to the port-order
	 * traversing in a BT.
	 */
	public T[] postOrder();

	/**
	 * Returns the number of nodes (not NIL) in a BT.
	 */
	public int size();
}
