### Queue
- [Queue Using Stacks](Queue%20using%20stacks.cpp)

    Queue using stacks, when there are given a stack data structure with push and pop operations, we have to implement a queue using instances of stack data structure and operations on them. There are 2 ways to implement using stacks, but in this code, we are going to look at one specific method. Which is making enQueue operation costly. This method makes sure that oldest entered element is always at the top of stack1, so that deQueue operation just pops from stack1. 
    
    Time complexity = Push operation : O(n), Pop operation : O(1)

- [Queue Using Array](Queue_using_Array.cpp)

    Queue_using_Array, for implementing queue, we need to keep track of two indices, front and rear. We enqueue an item at the rear and dequeue an item from the front. Advantage of using array is easy to implement, the disadvantage of using array is that 1. Static Data Structure, fixed size 2. If the queue has a large number of enqueue and dequeue operations, at some point we may not able to insert elements in the queue even if the queue is empty. 
    
    Time complexity = Enque(insertion) : O(1), Deque(deletion) : O(1), Front(Get front) : O(1), Rear(Get Rear) : O(1)

- [Queue Using LinkedList](Queue_using_LinkedList.cpp)

    Queue_using_LinkedList, we have to maintain two pointers, front and rear. The front points the first item of queue and rear points to last item. enQueue() => Operation which adds a new node after rear and moves rear to the next node deQueue() => This operation removes the front node and moves front to the next node. 
    
    Time complexity = enqueue : O(1), dequeue : O(1)

- [Queue](Queue.cpp)

    Queue, is a linear structure which follows a particular order in which the operations are performed. The order is FIFO(First In First Out). Difference between stacks and queues is in removing. In a stack we remove the item the most recently added where in a queue, we remove the item the least recently added. 
    
    Time complexity = O(n) 