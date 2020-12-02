### Greedy-Algorithms
- [Fractional Knapsack](Fractional%20Knapsack.cpp)

    Fractional Knapsack is a problem with given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Unlike 0-1 knapsack problem, we can break items for maximizing the total value of knapsack.
    
    Time complexity = O(nlog n)

- [Huffman Code](Huffman.cpp)
    
    Huffman Coding is a loss-less compression technique. It assigns variable-length bit codes to different chararcters. The Greedy Choice is to assign least bit length code to the most frequent character.
    
    Time complexity = O(nlog n)

- [Interval Queries](interval%20queries.cpp)

    Interval queries, consider a situation where we have a set of intervals and we need following operations to be implemented efficiently. 1. Add an interval 2. Remove an interval 3. Given an interval x, find if x overlaps with any of the existing intervals.	
    
    Time complexity = O(log n)

- [Is Subsequence](Is_Subsequence.cpp)
    
    Is_Subsequence with given two strings, we have to find if first string is a subsequence of second string. A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.	

    Time complexity = O(n) (n represent length of str2)

- [Weighted Job Scheduling](WeightedJobScheduling.cpp)

    Weighted JobS cheduling with Given N jobs where every job is represented by following three elements of it. 1. Start time 2. First time 3. Profit or Value Associated (>=0). And our goal is to find the maximum profit subset of jobs such that no two jobs in the subset overlap. The idea is to find the latest job before the current job (in sorted array) that doesn't conflict with current job 'arr[n-1]'. Once we find such a job, we recur for all jobs till that job and add profit of current job to result. In the above example, "job 1" is the latest non-conflicting for "job 4" and "job 2" is the latest non-conflicting for "job 3".	

    Time complexity = O(nlog n) (since we use  Binary search instead of linear search) 