package adt.rbtree;

import adt.bst.BSTNode;

public class RBNode<T extends Comparable<T>> extends BSTNode<T> {
	enum Colour {
		BLACK, RED
	};

	private Colour colour;

	public RBNode() {
		this.colour = Colour.BLACK;
	}

	public Colour getColour() {
		return colour;
	}

	public void setColour(Colour colour) {
		if (isEmpty() && colour == Colour.RED) {
			throw new UnsupportedOperationException(
					"NIL node colour cannot be RED");
		}
		this.colour = colour;
	}

	@SuppressWarnings("unchecked")
	@Override
	public boolean equals(Object obj) {
		return super.equals(obj)
				&& this.colour == ((RBNode<T>) obj).getColour();
	}

	@Override
	public String toString() {
		String resp = "NIL";
		if (!isEmpty()) {
			resp = "(" + data.toString();
			if (colour == Colour.RED) {
				resp = resp + ",R)";
			} else {
				resp = resp + ",B)";
			}
		}
		return resp;
	}

}
