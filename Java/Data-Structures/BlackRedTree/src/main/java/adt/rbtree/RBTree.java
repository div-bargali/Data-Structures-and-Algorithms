package adt.rbtree;

import adt.bst.BST;

/**
 * Interface representando uma árvore vermelha e preta.
 */
public interface RBTree<T extends Comparable<T>> extends BST<T> {
	/**
	 * Método que retorna um array de RBNode (ao invés de T) como resultado do
	 * percurso da arvore em pre ordem.
	 * 
	 * @return
	 */
	public RBNode<T>[] rbPreOrder();
}
