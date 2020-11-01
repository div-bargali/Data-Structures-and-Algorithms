package adt.rbtree;
   
import adt.bst.BSTImpl;
import adt.bst.BSTNode;
import adt.bt.Util;
import adt.rbtree.RBNode.Colour;
   
public class RBTreeImpl<T extends Comparable<T>> extends BSTImpl<T> implements RBTree<T> {
   
  	public RBTreeImpl() {
  		this.root = new RBNode<T>();
  	}
  
  	protected int blackHeight() {
  		return this.blackHeight((RBNode<T>) this.root);
  	}
  
  	protected int blackHeight(RBNode<T> node) {
  		int height = 0;
  		if (!node.isEmpty()) {
  			if (node.getColour().equals(Colour.BLACK)) {
  				height = 1;
  			}
  			height += Math.max(this.blackHeight((RBNode<T>) node.getRight()),
  					this.blackHeight((RBNode<T>) node.getLeft()));
  		}
  		return height;
  	}
  
  	protected boolean verifyProperties() {
  		boolean resp = verifyNodesColour() && verifyNILNodeColour() && verifyRootColour() && verifyChildrenOfRedNodes()
  				&& verifyBlackHeight();
  		return resp;
  	}
  
  	/**
  	 * The colour of each node of a RB tree is black or red. This is guaranteed by
  	 * the type Colour.
  	 */
  	private boolean verifyNodesColour() {
  		return true; // already implemented
  	}
  
  	/**
  	 * The colour of the root must be black.
  	 */
  	private boolean verifyRootColour() {
  		return ((RBNode<T>) root).getColour() == Colour.BLACK; // already
  																// implemented
  	}
  
  	/**
  	 * This is guaranteed by the constructor.
  	 */
  	private boolean verifyNILNodeColour() {
  		return true; // already implemented
  	}
  
  	/**
  	 * Verifies the property for all RED nodes: the children of a red node must be
  	 * BLACK.
  	 */
  	private boolean verifyChildrenOfRedNodes() {
  		return verifyChildrenOfRedNodes((RBNode<T>) root);
  	}
  
  	private boolean verifyChildrenOfRedNodes(RBNode<T> node) {
  		boolean isValid = true;
  
  		if (!node.isEmpty() && isValid != false) {
  
  			verifyChildrenOfRedNodes((RBNode<T>) node.getLeft());
  			verifyChildrenOfRedNodes((RBNode<T>) node.getRight());
  
  			if (node.getColour().equals(Colour.RED)) {
  				if (!((RBNode<T>) node.getLeft()).getColour().equals(Colour.BLACK)
  						|| !((RBNode<T>) node.getRight()).getColour().equals(Colour.BLACK))
  					isValid = false;
  			}
  		}
  
  		return isValid;
  	}
  
  	/**
  	 * Verifies the black-height property from the root.
  	 */
  	private boolean verifyBlackHeight() {
  		return verifyBlackHeight((RBNode<T>) root);
  	}
  
  	private boolean verifyBlackHeight(RBNode<T> node) {
  		int leftHeight = 0;
  		int rightHeight = 0;
  		boolean isValid = true;
  
  		if (!node.isEmpty() && isValid != false) {
  			verifyBlackHeight((RBNode<T>) node.getLeft());
  			verifyBlackHeight((RBNode<T>) node.getRight());
 
 			leftHeight = blackHeight((RBNode<T>) node.getLeft());
 			rightHeight = blackHeight((RBNode<T>) node.getRight());
 
 			if (leftHeight != rightHeight)
 				isValid = false;
 		}
 
 		return isValid;
 	}
 
 	@Override
 	public void insert(T value) {
 		if (value != null) {
 			this.insert((RBNode<T>) this.getRoot(), value);
 		}
 	}
 
 	private void insert(RBNode<T> node, T value) {
 
 		if (node.isEmpty()) {
 			this.setNewNode(node, value);
 			node.setColour(Colour.RED);
 			fixUpCase1(node);
 		} else if (node.getData().compareTo(value) > 0) {
 			this.insert((RBNode<T>) node.getLeft(), value);
 		} else if (node.getData().compareTo(value) < 0) {
 			this.insert((RBNode<T>) node.getRight(), value);
 		}
 
 	}
 
 	private void setNewNode(RBNode<T> node, T value) {
 		node.setData(value);
 		node.setLeft(new RBNode<>());
 		node.getLeft().setParent(node);
 		node.setRight(new RBNode<>());
 		node.getRight().setParent(node);
 	}
 
 	@Override
 	public RBNode<T>[] rbPreOrder() {
 		BSTNode<T>[] array = new RBNode[size()];
 		this.preOrder((RBNode<T>[]) array, ((RBNode<T>) root));
 		return (RBNode<T>[]) array;
 	}
 
 	private void preOrder(RBNode<T>[] array, RBNode<T> node) {
 		if (!node.isEmpty()) {
 			int post = this.getNextPos(array);
 			array[post] = node;
 			preOrder(array, (RBNode<T>) node.getLeft());
 			preOrder(array, (RBNode<T>) node.getRight());
 		}
 	}
 
 	protected int getNextPos(RBNode<T>[] array) {
 		int pos = 0;
 		while (array[pos] != null)
 			pos++;
 		return pos;
 	}
 
 	// FIXUP methods
 	protected void fixUpCase1(RBNode<T> node) {
 		if (node.getParent() == null) {
 			node.setColour(Colour.BLACK);
 		} else {
 			fixUpCase2(node);
 		}
 	}
 
 	protected void fixUpCase2(RBNode<T> node) {
 		if (((RBNode<T>) node.getParent()).getColour().equals(Colour.RED)) {
 			fixUpCase3(node);
 		}
 	}
 
 	protected void fixUpCase3(RBNode<T> node) {
 		RBNode<T> parent = (RBNode<T>) node.getParent();
 		RBNode<T> uncle = null;
 
 		if (parent.getParent().getLeft().equals(parent)) {
 			uncle = (RBNode<T>) parent.getParent().getRight();
 		} else {
 			uncle = (RBNode<T>) parent.getParent().getLeft();
 		}
 
 		if (uncle.getColour().equals(Colour.RED)) {
 			parent.setColour(Colour.BLACK);
 			uncle.setColour(Colour.BLACK);
 			((RBNode<T>) parent.getParent()).setColour(Colour.RED);
 			fixUpCase1((RBNode<T>) parent.getParent());
 		} else {
 			fixUpCase4(node);
 		}
 
 	}
 
 	protected void fixUpCase4(RBNode<T> node) {
 		RBNode<T> parent = (RBNode<T>) node.getParent();
 		RBNode<T> aux = node;
 
 		if (parent.getRight().equals(node) && parent.getParent().getLeft().equals(parent)) {
 			Util.leftRotation(parent);
 			aux = (RBNode<T>) node.getLeft();
 		} else if (parent.getLeft().equals(node) && parent.getParent().getRight().equals(parent)) {
 			Util.rightRotation(parent);
 			aux = (RBNode<T>) node.getRight();
 		}
 
 		fixUpCase5(aux);
 	}
 
 	protected void fixUpCase5(RBNode<T> node) {
 		RBNode<T> parent = (RBNode<T>) node.getParent();
 		RBNode<T> returnNode = null;
 
 		((RBNode<T>) parent).setColour(Colour.BLACK);
 		((RBNode<T>) parent.getParent()).setColour(Colour.RED);
 
 		if (node.getParent().getLeft().equals(node)) {
 			returnNode = (RBNode<T>) Util.rightRotation((BSTNode<T>) parent.getParent());
 		} else {
 			returnNode = (RBNode<T>) Util.leftRotation((BSTNode<T>) parent.getParent());
 		}
 
 		if (this.getRoot().equals(returnNode.getLeft()) || this.getRoot().equals(returnNode.getRight())) {
 			this.root = (BSTNode<T>) parent;
 		}
 
 	}
 
 }
