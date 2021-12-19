: import java.util.*;
class LinkedList {
    Node head;
    static class Node {
        int data;
        Node next;
        Node(int d) {
            data = d;
            next = null;
        }    }
    public static LinkedList insert(LinkedList list, int data) {
        Node new_node = new Node(data);
        new_node.next = null;
        if (list.head == null) {
            list.head = new_node;
        } else       {
            Node last = list.head;
            while (last.next != null) {
                last = last.next;
            }
            last.next = new_node;        }
        return list;    }
    public static void printlist(LinkedList list) {
        Node temp = list.head;
        System.out.println("Linked list:");
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
    public static void count1(LinkedList list) {
        Node temp = list.head;
        int c = 0;
        while (temp != null) {
            c++;
            temp = temp.next;
        }
        System.out.println("No.of nodes are: " + c);
    }
    public static int count2(Node node) {
        if (node == null)
            return 0;
        else
            return 1 + count2(node.next);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList ll = new LinkedList();
        ll = insert(ll, 2);
        ll = insert(ll, 5);
        ll = insert(ll, 6);
        ll = insert(ll, 8);
        ll = insert(ll, 1);
        ll = insert(ll, 3);
        printlist(ll);
        System.out.println("Counting through iteration:");
        count1(ll);
        System.out.println();
        System.out.println("Counting through recursion:");
        int a = count2(ll.head);
        if (a == 0)
            System.out.println("Length of linked list= " + a);
        else
            System.out.println("Length of linked list= " + a);
    }
}
