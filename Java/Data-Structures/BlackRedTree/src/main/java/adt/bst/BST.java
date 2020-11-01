package adt.bst;

import adt.bt.BT;

/**
 * The interface of a binary search tree (BST).
 */
public interface BST<T extends Comparable<T>> extends BT<T> {

	/**
	 * Returns the node containing the greatest element in a BST. If the tree is
	 * empty the method returns null.
	 */
	public BSTNode<T> maximum();

	/**
	 * Returns the node containing the lowest element in a BST. If the tree is
	 * empty the method returns null.
	 */
	public BSTNode<T> minimum();

	/**
	 * Returns a node containing the successor of the given element in a BST or
	 * null if it does not exist.
	 */
	public BSTNode<T> sucessor(T element);

	/**
	 * Returns a node containing the predecessor of the given element in a BST
	 * or null if it does not exist.
	 */
	public BSTNode<T> predecessor(T element);

}
