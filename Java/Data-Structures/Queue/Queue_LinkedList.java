// Implementing queue using linkedlist.

public class QueueUsingLinkedListMain
{
 private Node front, rear; 
 private int currentSize; // number of items
 
 //class to define linked node
 private class Node
 { 
 int data;
 Node next;
 }
 
 //No argument constructor
 public QueueUsingLinkedListMain()
 {
 front = null;
 rear = null;
 currentSize = 0;
 }
 
 public boolean isEmpty()
 {
 return (currentSize == 0);
 }
 
 //Remove item from the beginning of the list.
 public int dequeue()
 {
 int data = front.data;
 front = front.next;
 if (isEmpty()) 
 {
 rear = null;
 }
 currentSize--;
 System.out.println(data+ " removed from the queue");
 return data;
 }
 
 //Add data to the end of the list.
 public void enqueue(int data)
 {
 Node oldRear = rear;
 rear = new Node();
 rear.data = data;
 rear.next = null;
 if (isEmpty()) 
 {
 front = rear;
 }
 else 
 {
 oldRear.next = rear;
 }
 currentSize++;
 System.out.println(data+ " added to the queue");
 }
 public static void main(String a[]){
 
 QueueUsingLinkedListMain queue = new QueueUsingLinkedListMain();
 // Checking with the following inputs.
 queue.enqueue(6);
 queue.dequeue();
 queue.enqueue(3);
 queue.enqueue(99);
 queue.enqueue(56);
 queue.dequeue();
 queue.enqueue(43);
 queue.dequeue();
 queue.enqueue(89);
 queue.enqueue(77);
 queue.dequeue();
 queue.enqueue(32);
 queue.enqueue(232);
 }
}
 
