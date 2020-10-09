package stack;

public class StackByArrayMain {
	public static void main(String[] args) {
		
		
		System.out.println("Creating a stack of size 5...");
		StackByArray stack = new StackByArray(5);
		
		
		System.out.println("Pushing 6 values in the Stack...");
		for(int i=0; i<=5; i++) {
			stack.push(i*10);
		}
		
		
		System.out.println("Peeking value from stack");
		stack.peekOperation();
	
		
		System.out.println("Poping 6 values from the Stack...");
		for(int i=0; i<=5; i++) {
			stack.pop();
		}
		
		
		System.out.println("Deleting the Stack...");
		stack.deleteStack();
						
	}
}
