### Searching-Algorithms
- [Binary Search File](BinarySearch)
    - [Aggressive Cows](BinarySearch/AggressiveCows.cpp)

        It is an algorithm that finds the minimum and largest area distance of cows, and was solved using binary search.As an algorithm, if isvalid is 1 (the number of cow is greater than or equal to count), it tries to maximize distance(res). If isvalid is 0 (the number of cow is less than count), it tries to make the distance(res) smaller. 

        Time complexity = O(nlog n)

    - [Binary Search](BinarySearch/BinarySearch.cpp)

        Binary search is an algorithm that finds a specific value in an array in which data is arranged. Select a random value in the middle of the array and compare it with the value X you want to find. If X is less than the middle value, the data on the left side is searched based on the middle value, and if X is larger than the middle value, the right side of the array is searched again. In the same way, the middle value is randomly selected and compared again. Repeat this process until you find the appropriate value. 
        
        Time complexiy = O(log n)

    - [Binary Search On Rotated Array](BinarySearch/BinarySearch_on_Rotated_Array.cpp)

        There is a list of inverted left and right relative to one pivot in the array. At this time, it is a problem to find out which index the target exists. 
        
        Time complexity = O(log n)

- [Bellman Ford Algorithm](bellman_ford.cpp)

    The Bellman-Ford algorithm is an algorithm that solves the shortest path problem in a weighted directed graph.In this case, the weight of the side may be negative. The Daykstra algorithm performs the same task as the Bellman-Ford algorithm and runs faster. However, since the Dijkstra algorithm cannot handle negative weights, the Bellman-Ford algorithm is used in this case. 
    
    Time complexity = O(VE)

- [Find Kth Element](Find_kth_element.cpp)

    Algorithm that outputs the kth number of the remaining numbers excluding the elements of the array from the number increasing by 1 from 1. 
    
    Time complexity = O(nlog n)

- [Interpolation Search](InterpolationSearch.cpp)

    The interpolation search algorithm is an algorithm that improves the inefficiency of the binary search algorithm. (Binary search starts from the center regardless of the position of the target, x.) Interpolation search proceeds from the front when it is determined that the target is relatively in front.Therefore, since it is close to the data to be searched, the speed of reducing the search target is superior to that of binary search. It can be expressed as target = low + [(x-arr[low])*(high-low) / (arr[high]-arr[low])].
    
    Time complexity = O(log2(log2 n))(average case), O(n)(worst case)

- [Jump Search](JumpSearch.cpp)

    In the case of linear search, the value is searched from the first digit in the array. However, if the value you are looking for is in the back, it is not efficient, so we will grab a certain block and jump to find it instead of going up one by one. Int step = sqrt(n) was used as the formula to calculate the block to jump to. 
    
    Time complexity = O(√n)

- [Kth Smallest Search](KthSmallestSearch.cpp)

    Kth Smallest Search is an algorithm that uses a binary search algorithm to find the number of smallest numbers. It receives how many elements to enter, adds values ​​to those elements, and builds a binary search tree with them.Receives k from the user, searches for the kth smallest number from leaf, and outputs the kth smallest number. 
    
    Time complexity = O(n + klogn)

- [Linear Search](LinearSearch.cpp)

    It is one of the algorithms to find specific data that meets the conditions in the list. Unlike binary search algorithms that require sorting, linear search algorithms have the advantage of being able to find values ​​regardless of sorting, and their implementation is relatively simple. 
    
    Time complexity = O(n)

- [Ternary Search](TernarySearch.cpp)

    It is an algorithm that can be used to find the extreme value or the maximum/minimum value of a convex function. It is used to find the minimum value of a function that is convex downward and the maximum value of a function that is convex upward. 
    
    Time complexity = O(log3 n)