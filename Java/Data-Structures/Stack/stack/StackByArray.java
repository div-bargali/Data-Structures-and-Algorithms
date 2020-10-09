package stack;

public class StackByArray {
	
	int[] arr;
	int topOfStack;//keeps track of the cell which is last occupied in Array, this will help in insertion/deletion

	
	public StackByArray(int size) {
		this.arr = new int[size];
		this.topOfStack = -1;
		System.out.println("Successfully created an empty Stack of Size: "+size);
	}//end of method

	
	public void push(int value) {
		//if array is full, show stack overflow error
		if (isFullStack()) {
			System.out.println("Stack overflow error!!");
		} else {
			arr[topOfStack+1] = value;
			topOfStack++;
			System.out.println("Successfully inserted " + value + " in the stack");
		}
	}//end of method
	
	
	public void pop() {
		//if array is empty, show stack underflow error		
		if (isEmptyStack()) {
			System.out.println("Stack underflow error!!");
		} else {
			System.out.println("Poping value from Stack: " + arr[topOfStack] + "...");
			topOfStack--;
		}
	}//end of method

	
	public boolean isEmptyStack() {
		//if top pointer is zero, the stack is empty
		if (topOfStack == -1)
			return true;
		else
			return false;
	}//end of method
	
	
	public boolean isFullStack() {
		if (topOfStack == arr.length-1) {
			System.out.println("Stack is full !");
			return true;
		}else {
			return false;
		}
	}//end of method
		

	public void peekOperation() {
		if (!isEmptyStack())
			System.out.println("Top of Stack: " + arr[topOfStack]);
		else {
			System.out.println("The stack is empty!!");
		}
		System.out.println();System.out.println();
	}//end of method

	
	public void deleteStack() {
		arr = null;
		System.out.println("Stack is successfully deleted");
	}//end of method

}//end of class
