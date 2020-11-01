package adt.bst;
   
   public class BSTImpl<T extends Comparable<T>> implements BST<T> {
   
   	protected BSTNode<T> root;
   
   	public BSTImpl() {
   		root = new BSTNode<T>();
   	}
  
  	public BSTNode<T> getRoot() {
  		return this.root;
  	}
  
  	@Override
  	public boolean isEmpty() {
  		return root.isEmpty();
  	} 
  	
  	
  	@Override
  	public int height() {
  		return this.height(this.root);
  	}
  
  	protected int height(BSTNode<T> node) {
  		int height = -1;
  		if (!node.isEmpty()) {
  			height = 1 + Math.max(this.height((BSTNode<T>) node.getRight()), this.height((BSTNode<T>) node.getLeft()));
  		}
  		return height;
  	}
  
  	@Override
  	public BSTNode<T> search(T element) {
  
  		@SuppressWarnings({ "unchecked", "rawtypes" })
  		BSTNode<T> node = new BSTNode.Builder().data(element).build();
  
  		if (element != null) {
  			return search(root, node);
  		}
  
  		return node;
  	}
  
  	private BSTNode<T> search(BSTNode<T> current, BSTNode<T> node) {
  
  		if (!current.isEmpty()) {
  			if (current.equals(node)) {
  				return current;
  			} else {
  				if (current.getData().compareTo(node.getData()) == 1) {
  					return search((BSTNode<T>) current.getLeft(), (BSTNode<T>) node);
  				} else {
  					return search((BSTNode<T>) current.getRight(), node);
  				}
  			}
  		}
  		return current;
  	}
  
  
  	@Override
  	public void insert(T element) {
  		if (element != null) {
  			this.insert(this.getRoot(), element);
  		} 
  	}
  
  	private void insert(BSTNode<T> node, T element) {
  		if (node.isEmpty()) {
  			this.addNewNode(node, element);
  		} else if (node.getData().compareTo(element) > 0) {
  			this.insert((BSTNode<T>) node.getLeft(), element);
  		} else if (node.getData().compareTo(element) < 0) {
  			this.insert((BSTNode<T>) node.getRight(), element);
  		}
  	}
  
  	protected void addNewNode(BSTNode<T> node, T element) {
  		@SuppressWarnings({ "unchecked", "rawtypes" })
  		BSTNode<T> newNode = new BSTNode.Builder()
  				.data(element)
  				.parent(node.getParent())
  				.left(new BSTNode<>())
  				.right(new BSTNode<>())
  				.build();
  		
  		newNode.getLeft().setParent(newNode);
  		newNode.getRight().setParent(newNode);
  		
  		if (node.getParent() == null) {
  			this.root = newNode;
  		} else if (node.getParent().getData().compareTo(element) > 0) {
  			node.getParent().setLeft(newNode);
  		} else if (node.getParent().getData().compareTo(element) < 0) {
  			node.getParent().setRight(newNode);
  		}
 	}
 
 	@Override
 	public BSTNode<T> maximum() {
 		if (isEmpty()) {
 			return null;
 		} else {
 			return maximum(root);
 		}
 	}
 
 	private BSTNode<T> maximum(BSTNode<T> current) {
 		if (current.getRight().isEmpty()) {
 			return current;
 		} else {
 			return maximum((BSTNode<T>) current.getRight());
 		}
 	}
 
 	@Override
 	public BSTNode<T> minimum() {
 		if (isEmpty()) {
 			return null;
 		} else {
 			return minimum(root);
 		}
 	}
 
 	private BSTNode<T> minimum(BSTNode<T> current) {
 		if (current.getLeft().isEmpty()) {
 			return current;
 		} else {
 			return minimum((BSTNode<T>) current.getLeft());
 		}
 	}
 	
 	@Override
 	public BSTNode<T> sucessor(T element) {
 		BSTNode<T> node = this.search(element);
 		BSTNode<T> result = null;
 
 		if (!node.isEmpty()) {
 			if (!node.getRight().isEmpty()) {
 				result = this.minimum((BSTNode<T>) node.getRight());
 			} else {
 				result = this.getFirstParentMaximum(node, node.getData());
 			}
 		}
 		
 		return result;
 	}
 	
 	private BSTNode<T> getFirstParentMaximum(BSTNode<T> node, T value) {
 		BSTNode<T> result = null;
 
 		if (node.getParent() == null) {
 			result = null;
 		} else if (node.getParent().getData().compareTo(value) > 0) {
 			result = (BSTNode<T>) node.getParent();
 		} else {
 			result = (BSTNode<T>) this.getFirstParentMaximum((BSTNode<T>) node.getParent(), value);
 		}
 		
 		return result;
 	}
 
 	@Override
 	public BSTNode<T> predecessor(T element) {
 		BSTNode<T> node = this.search(element);
  		BSTNode<T> result = null;
  		
  		if (!node.isEmpty()) {
  			if (!node.getLeft().isEmpty()) {
  				result = this.maximum((BSTNode<T>) node.getLeft());
  			} else {
  				result = this.getFirstParentMinimum(node, node.getData());
  			}
  		}
  		
  		return result;
 	}
 	
 	private BSTNode<T> getFirstParentMinimum(BSTNode<T> node, T value) {
  		BSTNode<T> result;
  		
  		if (node.getParent() == null) {
  			result = null;
  		} else if (node.getParent().getData().compareTo(value) < 0) {
  			result = (BSTNode<T>) node.getParent();
  		} else {
  			result = (BSTNode<T>) this.getFirstParentMinimum((BSTNode<T>) node.getParent(), value);
  		}
  		
  		return result;
  	}
 
 	@Override
 	public void remove(T element) {
 		if (element != null) {
 
 			BSTNode<T> node = search(element);
 
 			if (!node.isEmpty()) {
 				if (node.isLeaf()) {
 					node.setData(null);
 				} else if (!node.getLeft().isEmpty() && !node.getRight().isEmpty()) {
 					removeTwoLeaves(node);
 				} else {
 					removeOneLeaf(node);
 				}
 			}
 		}
 	}
 
 	protected void removeOneLeaf(BSTNode<T> node) {
 		if (node.equals(root)) {
 			if (!root.getLeft().isEmpty()) {
 				root = (BSTNode<T>) root.getLeft();
 			} else {
 				root = (BSTNode<T>) root.getRight();
 			}
 		} else {
 			if (node.getParent().getLeft().equals(node)) {
 				removeLeft(node);
 			} else {
 				removeRight(node);
 			}
 		}
 	}
 
 	protected void removeTwoLeaves(BSTNode<T> node) {
 		BSTNode<T> sucessor = sucessor(node.getData());
 		T data = sucessor.getData();
 		remove(data);
 		node.setData(data);
 	}
 
 	protected void removeLeft(BSTNode<T> node) {
 		if (!node.getLeft().isEmpty()) {
 			node.getParent().setLeft(node.getLeft());
 			node.getLeft().setParent(node.getParent());
 		} else {
 			node.getParent().setLeft(node.getRight());
 			node.getRight().setParent(node.getParent());
 		}
 	}
 
 	protected void removeRight(BSTNode<T> node) {
 		if (!node.getLeft().isEmpty()) {
 			node.getParent().setRight(node.getLeft());
 			node.getLeft().setParent(node.getParent());
 		} else {
 			node.getParent().setRight(node.getRight());
 			node.getRight().setParent(node.getParent());
 		}
 	}
 
 	@Override
 	public T[] preOrder() {
 		T[] array = (T[]) new Comparable[size()];
 		this.preOrder(array, root);
 		return array;
 	}
 
 	private void preOrder(T[] array, BSTNode<T> node) {
 
 		if (!node.isEmpty()) {
 			array[getNextPos(array)] = node.getData();
 			preOrder(array, (BSTNode<T>) node.getLeft());
 			preOrder(array, (BSTNode<T>) node.getRight());
 		}
 	}
 
 	@Override
 	public T[] order() {
 		T[] array = (T[]) new Comparable[size()];
 		this.order(array, root);
 		return array;
 	}
 
 	private void order(T[] array, BSTNode<T> node) {
 
 		if (!node.isEmpty()) {
 			order(array, (BSTNode<T>) node.getLeft());
 			array[getNextPos(array)] = node.getData();
 			order(array, (BSTNode<T>) node.getRight());
 		}
 	}
 
 	@Override
 	public T[] postOrder() {
 		T[] array = (T[]) new Comparable[size()];
 		this.postOrder(array, root);
 		return array;
 	}
 
 	private void postOrder(T[] array, BSTNode<T> node) {
 
 		if (!node.isEmpty()) {
 			postOrder(array, (BSTNode<T>) node.getLeft());
 			postOrder(array, (BSTNode<T>) node.getRight());
 			array[getNextPos(array)] = node.getData();
 		}
 	}
 
 	protected int getNextPos(Comparable[] array) {
 		int pos = 0;
 		while (array[pos] != null)
 			pos++;
 		return pos;
 	}
 
 	/**
 	 * This method is already implemented using recursion. You must understand how
 	 * it work and use similar idea with the other methods.
 	 */
 	@Override
 	public int size() {
 		return size(root);
 	}
 
 	private int size(BSTNode<T> node) {
 		int result = 0;
 		// base case means doing nothing (return 0)
 		if (!node.isEmpty()) { // indusctive case
 			result = 1 + size((BSTNode<T>) node.getLeft()) + size((BSTNode<T>) node.getRight());
 		}
 		return result;
 	}
 }
