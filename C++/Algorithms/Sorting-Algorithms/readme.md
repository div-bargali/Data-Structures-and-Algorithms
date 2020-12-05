### Sorting-Algorithms
- [3-Way Quick Sort](3-Way%20Quick%20Sort/3_Way_Quick_Sort.cpp)

    The difference from normal Quick Sort is that it moves the pivot value steadily. Assuming that the position of the pivot value is lt, while searching for a larger value from the left, if there is a value smaller than the pivot, change the pivot and its number, increase lt by one, and point to the leftmost one of the pivots again. 
    
    Time complexity = Not stable! (for quick sort =>O(nlog n)

- [Bin or Bucket Sort](bin%20or%bucket/bin.cpp)

    Bucket sorting is a good algorithm to apply, assuming that data is distributed probabilistically and evenly within a certain range. Given n pieces of data, the range of data is divided by n, and n buckets are created. Distribution: Each piece of data is put into a corresponding bucket. Arrange each bucket with its contents. Collect: It visits the buckets in sequence and puts all the data back into the original array. 
    
    Time complexity = O(n+n^2/k+k)

- [Bitonic Sort](Bitonic%20Sort/Bitonic_Sort.cpp)

    Bitonic sorting algorithm is an algorithm that can recursively exchange sequentially increasing items and sequentially decreasing items, resulting in a form that increases sequentially. It does not matter if merge and sort are performed in parallel in multiple threads, so if there are many processors, sorting is possible faster than other sorts. If we take 8 terms as the example given, [ 3 7 4 8 6 2 1 5 ] we group two items and then sort them in ascending and descending order. [ 3 7 8 4 2 6 5 1 ] After that, 4 items are grouped, odd-numbered terms are sorted in ascending order, even-numbered terms are sorted in ascending order. On the other side, odd numbers are sorted by odd-numbered terms in descending order, and even numbers are sorted in descending order of even-numbered terms.[ 3 4 7 8 6 5 2 1 ] Then, the left item (large(8) to small term(3)) and the right item (small(1) to large term(6)) are compared and sorted.Then, divide both items into two, and then compare and sort the same as before. Repeat the above process until the item is of size 1. [ 1 2 3 4 5 6 7 8 ] 
    
    Time complexity = O(nlog n)

- [Bubble Sort](BubbleSort/Bubble_Sort.cpp)

    Algorithm that sorts the data by comparing the n-1st data and the nth data like the first data and the second data, the second data and the third data, exchanging the order. 
    
    Time complexity = O(n^2)

- [Cocktail Shaker Sort](Cocktail%20Shaker%20Sort/Cocktail_Shaker_Sort.cpp)

    Cocktail sorting is an algorithm that transforms bubble sorting to reduce the number of extreme comparisons of bubble sorting. When comparing from left to right, in the same way as for bubble sort, exchange while comparing. The last exchange takes place is set as the right point, and this time the exchange is performed by comparing from right to left. The place where the last exchange took place is set as the left point. Repeat the alignment until the left and right points intersect. In the worst case, bubble sorting and processing speed are similar, but average case is less than bubble sorting. 
    
    Time complexity = O(n) (for best case time), O(n^n) (for worst and average case)

- [Cycle Sort](CycleSort/Cycle_Sort.cpp)

    Cycle sort is an algorithm that minimizes write operations. It's slower than O(n^2) sorting on most computers, but it's a good idea to use if you need to use only O(1) for extra memory and the write operation is extremely expensive. (Like EEPROM, if a write operation shortens the life of the memory) 
    
    Time complexity = O(n^2)

- [Heap Sort](Heapsort/Heapsort.cpp)

    When organizing data, it does not process all data at the same time, but finds and prints the largest data among all data.Algorithm that repeats the previous process among the remaining data to find the largest data (actually the second largest data) and print it out. 
    
    Time complexity = O(nlog n)

- [Insertion Sort](InsertionSort/InsertionSort.cpp)

    It is an algorithm that starts from the second data, compares it with the previous data, designates the insertion position, moves the data back, and inserts the data in the designated position. That is, the second data is compared with the first data, the third data with the second and first data, and the fourth data with the third, second, and first data, and then the location where the data is to be inserted is found. Once you find the location where the data will be inserted, move the data back one space to insert the data at that location. The first key value starts from the second data. 
    
    Time complexity = O(n^2)    

- [Inversion Count](InversionCount/InversionsCount.cpp)

    It is an algorithm that finds how many pairs of numbers in a random order are inverted, In the process of dividing and sorting using merge sort, while comparing the sizes, the number of inverted sizes is counted. 
    
    Time complexity = O(n^2) 

- [Merge Sort](MergeSort/Merge_Sort.cpp)

    It is an algorithm that can be expressed as a divide and conquer algorithm. The list is divided into lists until the length is 0 or 1, then the partial lists are recursively sorted using merge sort, merged again, and repeated until the initial list length is reached. 
    
    Time complexity = O(nlog n)

- [Pigeon Hole Sort](Pigeonhole%20Sort/Pigeonhole_Sort.cpp)

    A method of creating an arbitrary space (pigeon hole) that is larger than the original arrangement space, inserting elements (pigeons) in sequence, and then aligning them to their original position. Find the minimum and maximum values ​​of a given array, and the range is set to maximum-minimum-1. Then set the size of the empty, pigeon hole array as the range.Put the elements from the given array into the pigeon hole array. (In the case of the given array arr[i], it enters arr[i]-min among the indexes of the pigeon hole array.)When all the pigeon holes are entered, execute a loop statement on the pigeon hole array, and put non-empty values ​​(filled values) into the original array (given array). 
    
    Time complexity = O(n + range)

- [Quick Sort](QuickSort/Quick_Sort.cpp)
    
    Among all sorting methods, the average execution time is the fastest. The element is divided into two parts based on the pivot key p, which is currently being processed in the alignment process. By recursively recursively recursing the two divided parts back into quicksort, it executes until all elements are sorted in order. 
    
    Time complexity = O(nlog n)

- [Radix Sort](RadixSort/radixSort.cpp)
    
    Radix Sort is a sorting algorithm based on the concept of comparing and sorting from the lowest digit. Radix sort has a queue from 0 to 9, compares the one digit of each term with 0 to 9, and puts the correct term in the corresponding queue. Then, the terms are retrieved from the queue in order from 0, and the previous process is repeated until sorting is finished by increasing the number of digits based on the highest digit. 
    Time complexity = O(d*(n+b)) (d=> number of digits in the given list, n => number of elements in the list, b is the base or bucket size used)

- [Selection Sort](SelectionSort/selection_sort.cpp)

    Compare the first data and the second data to the last data in order, put the smallest value in the first digit, then compare the second data and the third data to the last data, and the smallest value among them in the second digit. It is an algorithm that repeats the putting process until the seats are filled. 
    
    Time complexity = O(n^2)

- [Shell Sort](shell/shell.cpp)

    It is an algorithm proposed by Donald Shell and compensated for the disadvantage of sorting the entire list of insertion sorting by dividing it into partial lists and sorting them. Sort the list to be sorted by creating several partial lists according to criteria. Sort them using insertion sort. Then, make the whole list into fewer sublists than before and repeat until sorted (i.e., the sublist is 1). 
    
    Time complexity = O(n log n)

- [Spiral Matrix Sort](SpiralMatrixSort.cpp) 

- [Topological Sort](Topological%20Sorting.cpp)

    Topological_sort is sorting algorithm for directed acyclic graph, which is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering. But if graph is not a DAG, topological sorting is not possible.
    
    Time complexity = O(V+E) 
