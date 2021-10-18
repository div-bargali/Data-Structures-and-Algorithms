//This code sorts the Stack in such a way that greatest element is at the top of the stack

/** Problem : Sort the Stack elements such that the greatest element is at the top of the stack
 * Author : https://github.com/skmodi649
 */



package stack;
import java.util.Scanner;
import java.util.Stack;

class StackSorting{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the Stack size : ");
        Stack<Integer> s=new Stack<>();
        int n=sc.nextInt();
        System.out.println("Enter the elements in the Stack : ");
        while(n-->0)
            s.push(sc.nextInt());
            StackSorting g = new StackSorting();
            System.out.println("Sorted Stack : ");
            Stack<Integer> a = g.sort(s);       //Sorted elements inserted in new Stack
            while (!a.empty()) {
                System.out.print(a.peek() + " ");
                a.pop();                          //Popping top elements of the stack
            }
}

    public void sortedInsert(Stack<Integer> S , int element)  // This method inserts the sorted element
    {
        if((S.empty()) || (S.peek() < element))
            S.push(element);
        else
        {
            int temp = S.pop();
            sortedInsert(S , element);
            S.push(temp);
        }
    }
    public Stack<Integer> sort(Stack<Integer> s)    //Sorts the stack and then returns it
    {
        if(!s.empty())
        {
            int temp = s.pop();
            sort(s);
            sortedInsert(s , temp);
        }
        return s;
    }
}



/** Expected Time Complexity: O(N*N)
 * Expected Auxiliary Space Complexity : O(N)
 * Constraints : 1<=N<=100
 */


/** Test Case 1 :
 * Enter the Stack size : 5
 * Enter the elements in the Stack : 0 1 2 3 9
 * Sorted Stack : 9 3 2 1 0
 *
 * Test Case 2 :
 * Enter the Stack size : 6
 * Enter the elements in the Stack : 3 1 2 9 8 7
 * Sorted Stack : 9 8 7 3 2 1
 */