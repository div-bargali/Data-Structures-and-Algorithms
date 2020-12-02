### Two-Pointer-Algorithms
- [3 Sum](3Sum.cpp)

    Problem of taking an array of n integers and returning a subset where the sum of three elements is 0. 
    
    Time complexity = O(n^3)

- [Floyd's Cycle Finding Algorithms](Floyd's-Cycle-Finding-Algorithms.cpp)

    It is a simple algorithm that if two pointers of different speeds enter the loop and proceed, in the case of a cycle, they eventually point to the same node. Slowptr advances one space at a time and fastptr advances two spaces at a time. This means that if it is not recursive, it eventually encounters the null and terminates the program. If it is cyclic, it means that slowptr and fastptr meet, and it becomes a loop. If the loop is found by the Floyd loop finding algorithm, when the node where slowptr and fastptr meet in the loop starts again from the head, the distance from the node where the loop starts is the same. 
    
    Time complexity = O(n)