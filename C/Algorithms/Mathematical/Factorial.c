/**
 * Factorial Algorithm
 *
 * Mathematical explanation:
 *	The factorial function has the following format:
 *		factorial(n) = !n = n.!(n-1) = n.(n-1).(n-2). ... !0
 *	Where,
 * 		factorial(0) = !0 = 1
 * 		factorial(1) = !1 = 1.!0 = 1
 *		factorial(2) = !2 = 2.!1 = 2
 *		...
 *		factorial(n) = !n = n.!(n-1) = n.(n-1).(n-2). ... !0
 *
 * Code explanation:
 *	factorial(n) - calculates the factorial to the index `n`
 * 	example()	 - example of how factorial function works
 */
#include <stdio.h>

int factorial(int index)
{
    if (index == 0) return 1;	///< zero case
    else return index*factorial(index - 1);	///< general case
}

void example()
{
    for(int i = 0; i < 10; i++)
        printf("\n%d", factorial(i));
}

int main()
{
    example();
    return 0;
}
