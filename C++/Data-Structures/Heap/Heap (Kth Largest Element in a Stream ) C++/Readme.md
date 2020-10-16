A Simple Solution is to keep an array of size k. The idea is to keep the array sorted so that the k’th largest element can be found in O(1) time (we just need to return first element of array if array is sorted in increasing order)
How to process a new element of stream?
For every new element in stream, check if the new element is smaller than current k’th largest element. If yes, then ignore it. If no, then remove the smallest element from array and insert new element in sorted order. Time complexity of processing a new element is O(k).

A Better Solution is to use a Self Balancing Binary Search Tree of size k. The k’th largest element can be found in O(Logk) time.
How to process a new element of stream?
For every new element in stream, check if the new element is smaller than current k’th largest element. If yes, then ignore it. If no, then remove the smallest element from the tree and insert new element. Time complexity of processing a new element is O(Logk).

An Efficient Solution is to use Min Heap of size k to store k largest elements of stream. The k’th largest element is always at root and can be found in O(1) time.
How to process a new element of stream?
Compare the new element with root of heap. If new element is smaller, then ignore it. Otherwise replace root with new element and call heapify for the root of modified heap. Time complexity of finding the k’th largest element is O(Logk).
