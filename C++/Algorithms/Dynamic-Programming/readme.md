### Dynamic-Programming 
- [0-1 Knapsack Problem](0-1%20Knapsack%20Problem/0-1%20Knapsack%20Problem.cpp)
    
    0-1 Knapsack Problem is a problem in combinatiorial optimization: Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible. And for the 0-1 Knapsack problem, you cannot break an item, either pick the complete item or don't pick it(0-1 property)

    Time complexity = O(2^n)

- [Matrix-Chain Multiplication](Matrix-Chain-Multiplication/matrix_chain_multiplication.cpp)

    Matrix-Chain-Multiplication is a algorithm when there is a given sequence of matrices, find the most efficient way to multiply these matrices together. However the problem is not actually to perform the multiplications, but merly to decide in which order to perform the multiplications.

    Time complexity = O(n^3)

- [SubsetSum](SubsetSum/Subset_Sum_dp.cpp)

    SubsetSum is a algorithm with a given set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. For example if set is {3,34,4,12,5,2} and sum is 9 then output will be true  because there is a subset (4,5) with sum 9.

    Time complexity = O(sum*n)

- [Activity Selection](Activity_Selection.cpp)

    Activity Selection is a problem that given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time. 

    Time complexity = O(nlog n)     (since input didn't sorted) 

- [Coin Change Problem](Coin%20Change%20Problem.cpp)

    Coin change problem, with a given value N, if we want to make change for N cents, and we have infinite supply of each of S = {S1, S2,... ,Sm} valued coins

    Time complexity = O(mn)

- [Egg Droping Problem](egg_dropping_problem.cpp)

    Egg dropping problem, suppose that we wish to know which stories in a 36-story building are safe to drop eggs from, and which will cause the eggs to break on landing. There are few assumptions which is an egg that survives a fall can be used again, a broken egg must be discarded, the effect of a fall is the same for all eggs, if an egg breaks when dropped, then it would break if dropped from a higher floor, if an egg survives a fall then it would break if dropped from a higher floor, if an egg survives a fall then it would survive a shorter fall, and it is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor do not cause an egg to break.

    Time complexity = O(n*k^2)

- [Josephus Problem](Josephus%20problem.cpp)

    Josephus problem is a theoretical problem. There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. Goal is to choose the pace in the initial circle so that you are the last one remaining and so survive. 

    Time complexity = O(n) 

- [Kadene Algorithm](Kadane-Algorithm.cpp)
    
    kadane's algorithm is a algorithm with an given array of n integers, we have to look for all positive continuous segments of the array, and keep track of maximum sum contiguous segment among all positive segments.       

    Time complexity = O(n) 

- [Longest Palindromic Sequence](Longest%20%20Palindromic%20Sequence.cpp)

    Longest Palindromic Sequence which is Longest palindromic Subsequence. With a given sequence, find the length of the longest palindromic subsequence in it. For example, if the given sequence is BBABCBCAB then output will be 7 which is BABCBAB(which is the longest).

    Time complexity = O(n^2)

- [Longest Common Subsequence](Longest%20Common%20Subsequence.cpp)

    Longest Common Subsequence with given two sequences, find the length of longest subsequence present in both of them.

    Time complexity = O(2^n)

- [Longest Bitonic Subsequence](longest_bitonic_subsequence.cpp)

    Longest Bitonic Subsequence, with an given array arr[0....n-1] containing n positive integers, a subsequence of arr[] is called Bitonic if it is first increasing, then decreasing. Our goal is to write a function that takes an array as an argument and returns the length of the longest bitonic subsequence. A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. Similarly, decreasing order sequence is considered Bitonic with the increasing part as empty.

    Time complexity = O(n^2)

- [Longest Palindromic SubString](LongestPalindromicSubstring.cpp)
    
    Longest Palindromic Substring, given a string, find the longest substring which is palindrome. For example if  input is given as "forgeeksskeegfor" output will be "geeksskeeg"
    
    Time complexity = O(n^3)

- [Max Profit With K Transactions](Max%20Profit%20with%20K%20transactions.cpp)
    
    Max Profit with K transaction which is Maximum profit by buying and selling a share at most k times. In share trading, a buyer buys shares and sells on a future date. Given the stock price of n days, the trader is allowed to make at most k transactions, where a new transaction can only start after the previous transaction is complete, find out the maximum profit that a share trader could have made.
    
    Time complexity = O(k*n^2)

- [Minimum No of Coins(Greedy Approach)](Minimum%20no%20of%20coins(Greedy%20Approach).cpp)
    
    Minimum no of coins(Greedy Approach) is to find minimum number of coins that make a given value. Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = {C1,C2,..,Cm} valued coins, we have to find the minimum number of coins to make the change. 		
    
    Time complexity = O(mv)

- [Minimum Number of Jumps](Minimum%20Number%20of%20Jumps.cpp)

    Minimum Number of Jumps, given an array of integers where each element represents the max number of steps that can be made forward from that element. Write a function to return the minimum number of jumps to reach the end of the array(starting from the first element). If an element is 0, they cannot move through that element.
    
    Time complexity = O(n^n)

- [Unique_Paths](Unique_Paths.cpp)
    
    Unique Paths, to count all the possible paths from top left to bottom right of a m x n matrix with the constrains that from each cell you can either move only to right or down.

    Time complexity = O(mn) 

- [WildCard_Matching](Wildcard_matching.cpp)

    Wildcard matching, with a given text and a wildcard pattern, implement wildcard pattern matching algorithm that finds if wildcard pattern is matched with text. The matching should cover the entire text(not partial text).
    
    Time complexity = O(mn)

- [WordBreak](wordbreak.cpp)
    
    wordbreak is a problem with a given input string and a dictonary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words.

    Time complexity = O(n*s) 