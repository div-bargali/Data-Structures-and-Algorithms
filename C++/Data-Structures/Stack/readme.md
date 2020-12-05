### Stack
- [Balanced Brackets](balanced_brackets.cpp)

    balanced_bracket, with a given string, we have to write a program to examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in the given string.  
    
    Time complexity = O(n)

- [Infix to Postfix Notation](infix_to_postfix_notation.cpp)

    infix_to_postfix_notation, Infix expression => The expression of the form a op b. When an operator is in-between every pair of operands. Postfix expression =>  The expression of the form a b op. When an operator is followed for every pair of operands.  The compiler scans the expression either from left to right or from right to left. Think of below expression : a op1 b op2 c op3 d, if op1 => +, op2 => *, op3 = +, then the compiler first scans the expression to evaluate the expression b * c, then again scan the expression to add a to it. Then the result will be added to d after another scan.  
    
    Time complexity = O(n)

- [Reverse a Stack Using Recursiom](reverse%20a%20stack%20using%20recursion.cpp)

    reverse a stack using recursion, in order to solve this problem, we have to hold all values in Function Call Stack until the stack becomes empty. When the sack becomes empty, insert all held items one by one at the bottom of the stack. 
    
    Time complexity = O(n^2)

- [Reverse Stack without Using Extra Space](Reverse_stack_without_using_extra_space.cpp)

    Reverse_stack_without_using_extra_space, initially, reverse the individual words of the given string one by one and reverse the whole string from start to end to get the output we are targeting. For example, if the inputs are “i love programming very much”, output will be “much very programming love i”  
    
    Time complexity = O(n)

- [Reverse Words of String Using Stack](Reverse_Words_of_String_using_Stack.cpp)

    Reverse_Words_of_String_using_Stack, given string str which consists of multiple words, our goal is to reverse the entire string word by word. Following is the step for this problem, 1. Create an empty stack 2. Traverse the entire string, while traversing add the characters of the string into a temporary variable until you get a space (‘’) and push that temporary variable into the stack. 3. Repeat the above step until the end of the string. 4. Pop the words from the stack until the stack is not empty which will be in reverse order. 
    
    Time complexity = O(n)

- [Sort Stack Using Temp Stack](sort_stack_using_temp_stack.cpp)

    sort_stack_using_temp_stack, with a given stack of integers, sort it in descending order using another temporary stack. We can think of examples if there are inputs 34, 3, 31, 98, 92, 23, then output will be 3, 23, 31, 34, 92, 98. To briefly explain the algorithm, 1. Create a temporary stack say tmpStack. 2. While input stack is not empty do this: Pop an element from input stack call it temp, while temporary stack is not empty and top of temporary stack is greater than temp, pop from temporary stack and push it to the input stack. 3. The sorted numbers are in tmpStack. 

    Time complexity = O(n^2)

- [Stack Using Array](stack_using_Array.cpp)
    
    stack_using_Array, for a stack implemented with Array, has 2 options to push items. We append them (add item at the next to the last index) or prepend item(which is insert item at the first index). 
    
    Time complexity = O(n)

- [Stack Using Linked_List1](Stack_Using_Linked_List.cpp), [Stack Using Linked List Template](stack_using_Linked_List_Template.cpp)

    Stack_using_Linked_List, to implement a  stack using a linked list, we need to set the following things before implementing actual operations. STEP 1, include all the header files which are used in the program, and declare all the user defined functions. STEP 2, define a ‘Node’ structure with two members data and text. STEP 3, define a Node pointer ‘top’ and set it to NULL. STEP 4, implement the main method by displaying Menu with list of operations and make suitable function calls in the main method. 
    
    Time complexity = O(1)

- [Stack Using Two Queues](stack_using_two_queues.cpp)

    stack_using_two_queues, a queue can be implemented with two stacks, a stack can also be implemented using two queues. The basic idea is to perform stack ADT operations using the two queues. We need to implement push(), pop() by using DeQueue(), EnQueue() operations available for the queues. 
    
    Time complexity = Push : O(1), Pop : O(n)

- [Stack](Stack.cpp)

    Stack is an ordered collection of items for which we can only add or remove items from one end(= the top of the stack). The stack is another container class, much like a list, but with a much more limited set of operations. For example, push - add a new item on top of the stack, pop - remove the top item from the stack, isEmpty - check if the stack is empty, size - count the number of items on the stack. We are interested in designing a stack class template so that we may place all sorts of things on our stacks. 

    Time complexity = Push : O(1) Pop : O(1) Top : O(1) Search : O(n) 

- [Tower of Hanoi](TowerOfHanoi.cpp)
TowerOfHanoi  is a mathematical puzzle which consists of three towers and more than one rings. There are three rules in this algorithm in moving all the disks to some another tower without violating the sequence of arrangement. 1. Only one disk can be moved among the towers at any given time 2. Only the top disk can be removed 3. No large disk can sit over a small disk. 

Time complexity => O(n)