#include <stdio.h>

int factorial(int value)
{
    if (value == 0) return 1;
    if (value == 1) return 1;
    else return value*factorial(value - 1);
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
