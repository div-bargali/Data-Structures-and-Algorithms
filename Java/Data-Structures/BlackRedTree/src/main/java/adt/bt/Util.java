package adt.bt;
   
import adt.bst.BSTNode;
   
public class Util {
   
   
   	/**
   	 * A rotacao a esquerda em node deve subir e retornar seu filho a direita
  	 * @param node
  	 * @return
  	 */
   	
  	public static <T extends Comparable<T>> BSTNode<T> leftRotation(BSTNode<T> node) {
  		BSTNode<T> child = (BSTNode<T>) node.getRight();
  		child.setParent(node.getParent());
  		
  		if (node.getParent() != null) {
  			if (node.getParent().getLeft().equals(node)) {
  				node.getParent().setLeft(child);
  			} else {
  				node.getParent().setRight(child);
  			}
  		}
  		
  		node.setParent(child);
  		node.setRight(child.getLeft());
  		
  		if (child.getLeft() != null) {
  			child.getLeft().setParent(node);
  		}
  		
  		child.setLeft(node);
  		
  		return child;
  	}
  
  	/**
  	 * A rotacao a direita em node deve subir e retornar seu filho a esquerda
  	 * @param node
  	 * @return
  	 */

  	public static <T extends Comparable<T>> BSTNode<T> rightRotation(BSTNode<T> node) {
  		BSTNode<T> child = (BSTNode<T>) node.getLeft();
  		child.setParent(node.getParent());
  		
  		if (node.getParent() != null) {
  			if (node.getParent().getLeft().equals(node)) {
  				node.getParent().setLeft(child);
  			} else {
  				node.getParent().setRight(child);
  			}
  		}
  		
  		node.setParent(child);
  		node.setLeft(child.getRight());
  		
  		if (child.getRight() != null) {
  			child.getRight().setParent(node);
  		}
  		
  		child.setRight(node);
  		
  		return child;
  	}
  
  	public static <T extends Comparable<T>> T[] makeArrayOfComparable(int size) {
  		@SuppressWarnings("unchecked")
  		T[] array = (T[]) new Comparable[size];
  		return array;
  	}

  }