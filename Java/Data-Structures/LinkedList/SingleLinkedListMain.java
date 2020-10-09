package linkedList;

public class SingleLinkedListMain {

	public static void main(String[] args) {
		
		SingleLinkedList list = new SingleLinkedList();
		list.createSingleLinkedList(5);
		list.traverseLinkedList();
		
		list.insertInLinkedList(10, 1);
		list.traverseLinkedList();
		
		list.insertInLinkedList(20, 2);
		list.traverseLinkedList();
		
		list.insertInLinkedList(30, 2);
		list.traverseLinkedList();
		
		list.insertInLinkedList(40, 1);
		list.traverseLinkedList();
	
		list.traverseLinkedList();
		System.out.println();
			
		
		System.out.println("\nSearching the node having value 40...");
		list.searchNode(40);

		System.out.println("\nSearching the node having value 500...");
		list.searchNode(500);
		
		
		System.out.println("\n\nDeleting the node having location = 0: ");
		System.out.println("Before Deletion:");
		list.traverseLinkedList();
		list.deletionOfNode(0);
		System.out.println("After Deletion:");
		list.traverseLinkedList();
		System.out.println();
		
		System.out.println("\n\nDeleting the node having location = 2: ");
		System.out.println("Before Deletion:");
		list.traverseLinkedList();
		list.deletionOfNode(2);
		System.out.println("After Deletion:");
		list.traverseLinkedList();
		System.out.println();
		
	
		System.out.println("\n\nDeleting the node having location = 100: ");
		System.out.println("Before Deletion:");
		list.traverseLinkedList();
		list.deletionOfNode(100);
		System.out.println("After Deletion:");
		list.traverseLinkedList();
		System.out.println();
		
		
		list.deleteLinkedList();
		list.traverseLinkedList();
		
	
	}

}
