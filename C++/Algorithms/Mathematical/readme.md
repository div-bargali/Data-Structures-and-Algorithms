### Mathematical
- [FFT](FFT/FFT(Iterative).cpp)

    It refers to an algorithm that finds the same number as the sum of a given three-digit integer and the number of each of the digits to the power of three. For example, in the case of 153, 1*1*1 + 5*5*5 + 3*3*3 is established, so 153 belongs to Armstrong's number.	

    Time complexity = O(log n)

- [Armstrong Number](Armstrong_number_comment.cpp)

    It refers to an algorithm that finds the same number as the sum of a given three-digit integer and the number of each of the digits to the power of three. For example, in the case of 153, 1*1*1 + 5*5*5 + 3*3*3 is established, so 153 belongs to Armstrong's number.		
    
    Time complexity = O(log n)

- [Euler’s Totient Function](Euler's%20Totient%20Function.cpp)

    Euler's Totient Function is a function that calculates the number of integers from 1 to n that are mutually related to n.

    Time complexity = O(nlog n)

- [Fibonacci Number](Fibonacci_no.cpp)
    
    The Fibonacci number is a sequence where the first and second terms are 1, and all the terms after it are the sum of the two immediately preceding terms. So the first six terms are 1, 1, 2, 3, 5, 8 respectively. Fibonacci number algorithm is when n=0, F(n) = 0, when n=1, F(n) = 1, when n is greater than 1, F(n) = F(n-1) + F means (n-2).

    Time complexity = O(n)

- [Hosoya Triangle](Hosoya.cpp)

    Hosoya's Triangle, like the Fibonacci sequence, means a triangle with the first and second terms equal to 1, and all the diagonal and vertical terms after that are the sum of the two preceding terms.
    Time complexity = O(n^3)

- [Lucky Number](Lucky_number_comment.cpp)

    Algorithm in which if there are duplicate numbers such as 11, 101, and 1100, the flag becomes 1 and becomes a not lucky number. If there are no duplicates, the flag remains at 0 and the lucky number is output.
    Time complexity = O(d) (d represent number of digits in input number)

- [Min Subsequence](Min_subsequence.cpp)

    Sum is the sum of all numbers after sorting from the smallest to the largest among the collections of numbers entered by the user, and p is the sum of the values ​​sequentially added from the largest to the smallest. sum-An algorithm that pushes back the elements of the vector and outputs the element values ​​under conditions less than or equal to p
    
    Time complexity = O(n)

- [Particular Sum](Particular_sum.cpp)

    Algorithm to solve the problem described in https://codeforces.com/problemset/problem/1176/B

    Time complexity = O(n)

- [Power Function](Power_Func.cpp)

    Iteractive method and recursive method, the power of 2 algorithm

    Iteractive
    Like the for statement, use a loop to find the power of 2.

    Recursive
    Using a recursive function, find the power of 2.

    Time complexity = O(n)


- [Program for Nth Catalan Number](Program%20for%20nth%20Catalan%20number.cpp)

    A sequence that appears when counting the number of binary trees, and can be expressed as Cn.
    Catalan number can be recursively defined by recursive equation, 
    
    C0 = 1. In the case of Cn+1, it can be expressed as 2(2n+1)*Cn/(n+2).

    Ignition

    C1 = (2/2) * C0 (So, for C1, it is (2/2)*1, so it becomes 1.)

    C2 = (2(2+1)/(1+2)) * C1 ((2(3)/3)*C1 for C2, so it's 2.)

    C3 = (2(4+1)/(2+2)) * C2 (For C3, it is (2(5)/4)*C2, so it is 5.)

    You can get it recursively, or you can get it through a loop. 
    
    Time complexity = O(n^2)

- [Sieve of Eratosthenes](Sieve%20of%eratosthenes.cpp)

    Algorithm how to find prime numbers,
    
    1. Since 1 is not a prime, list all the numbers you want to find from 2
    
    2. Since 2 is a prime number, remove multiples of 2 except 2.
    
    3. Since 3 is a prime number, remove multiples of 3 except 3.
    
    4. Since 5 is a prime number, remove multiples of 5 except 5.
    
    5. 7 is also a prime number, so the multiples of 7 except 7 are removed.
    
    6. Use the above process to be the closest to the square root of the number
    Repeat until a natural number.
    
    7. The number remaining without being removed represents a prime number. 

    Time complexity = O(n*log(log(n)))

