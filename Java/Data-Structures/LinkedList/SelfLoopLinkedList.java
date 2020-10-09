class LinkedList { 
  
    static Node head; 
  
    static class Node { 
  
        int data; 
        Node next; 
  
        Node(int d) 
        { 
            data = d; 
            next = null; 
        } 
    } 
    int detectAndRemoveLoop(Node node) 
    { 
        Node slow = node, fast = node; 
        while (slow != null && fast != null && fast.next != null) { 
            slow = slow.next; 
            fast = fast.next.next; 
            if (slow == fast) { 
                removeLoop(slow, node); 
                return 1; 
            } 
        } 
        return 0; 
    } 
    void removeLoop(Node loop, Node curr) 
    { 
        Node ptr1 = null, ptr2 = null; 
  
        /* Set a pointer to the beginning of the Linked List and 
         move it one by one to find the first node which is 
         part of the Linked List */
        ptr1 = curr; 
        while (1 == 1) { 
  
            /* Now start a pointer from loop_node and check if it ever 
             reaches ptr2 */
            ptr2 = loop; 
            while (ptr2.next != loop && ptr2.next != ptr1) { 
                ptr2 = ptr2.next; 
            } 
  
            /* If ptr2 reahced ptr1 then there is a loop. So break the 
             loop */
            if (ptr2.next == ptr1) { 
                break; 
            } 
  
            /* If ptr2 did't reach ptr1 then try the next node after ptr1 */
            ptr1 = ptr1.next; 
        } 
  
        /* After the end of loop ptr2 is the last node of the loop. So 
         make next of ptr2 as NULL */
        ptr2.next = null; 
    } 
  
    // Function to print the linked list 
    void printList(Node node) 
    { 
        while (node != null) { 
            System.out.print(node.data + " "); 
            node = node.next; 
        } 
    } 
  
    // Driver program to test above functions 
    public static void main(String[] args) 
    { 
        LinkedList list = new LinkedList(); 
        int a=50;
        list.head = new Node(a); a=20;
        list.head.next = new Node(a); a=15
        list.head.next.next = new Node(a); a=4;
        list.head.next.next.next = new Node(a); a=10;
        list.head.next.next.next.next = new Node(a); 
  
        // Creating a loop for testing 
        head.next.next.next.next.next = head.next.next; 
        list.detectAndRemoveLoop(head); 
        System.out.println("Linked List after removing loop : "); 
        list.printList(head); 
    } 
} 
