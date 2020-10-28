import java.util.Stack;

// Queue implemented in Java
// Uses Two Stacks and a costly dequeue method
public class Queue_TwoStacks<T> {
    private Stack<T> s1;
    private Stack<T> s2;

    //Create Two Stacks
    public Queue_TwoStacks() {
        s1 = new Stack<T>();
        s2 = new Stack<T>();
    }

    public void enqueue(T data) {
        //s1 will serve to hold the back of the queue.
        s1.push(data);
    }

    public T dequeue() {
        if (s2.isEmpty()) {
            //s2 is empty, meaning we need s1 in reverse order
            while (!s1.isEmpty()) {
                //Pop items from s2 to s1, reversing the order of data
                s2.push(s1.pop());
            }
            //The top of Stack 2 is now the front of the Queue
            return s2.pop();
        }
        else {
            //The top of Stack 2 is the front of the queue
            return s2.pop();
        }
    }

    public boolean isEmpty() {
        //Both stacks must be empty
        return s1.isEmpty() && s2.isEmpty();
    }

    public int getSize() {
        //Add both stacks' size for the queue's size
        return s1.size() + s2.size();
    }
public static void main(String a[]) {
    //Testing Implementation
    Queue_TwoStacks<Integer> queue = new Queue_TwoStacks<Integer>();
    System.out.println("Queueing Integers 1-5");
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    System.out.println("Dequeueing Integers 1-5");
    //Should dequeue numbers in the order they were queued.
    while (!queue.isEmpty()) {
        System.out.println(queue.dequeue() + " dequeued.");
    }
}
}
