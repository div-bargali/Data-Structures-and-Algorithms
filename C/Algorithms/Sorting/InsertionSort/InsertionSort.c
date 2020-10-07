/* C Program for Insertion Sort */
#include <stdio.h>
int main()
{
    int a[100], number, i, j, temp;
    
    printf("\n Please Enter the total Number of Elements  :  ");
    scanf("%d", &number);
    
    printf("\n Please Enter the Array Elements  :  ");
    for(i = 0; i < number; i++)
        scanf("%d", &a[i]);
    
    for(i = 1; i <= number - 1; i++)
    {
        for(j = i; j > 0 && a[j - 1] > a[j]; j--)
        {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
        }
    }
    printf("\n Insertion Sort Result : ");
    for(i = 0; i < number; i++)
    {
        printf(" %d \t", a[i]);
    }
    printf("\n");
    return 0;
}