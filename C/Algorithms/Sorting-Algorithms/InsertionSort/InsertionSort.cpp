#include<stdio.h>

int main(void)

{
    int array[25], n, temp, j;
    
    printf("Enter the number of entries: ");
    scanf("%d", &n);
    printf("Enter the %d elements: ", n);
    //user-input
    for(int i = 0; i < n; i++)
    {
       scanf("%d", &array[i]);
    }
    //The main algo of insertion-sort
    //it considers first to be smallest then compares, if other number is found smaller then the choosen one then that number is taken out
    //now shift the sorted elemnt according to how smaaler the number is taken out and so on...
    for(int i = 1; i < n; i++)
    {
      temp = array[i];
      j = i - 1;
      while((temp < array[j]) && (j >= 0))
      {
         array[j + 1] = array[j];
         j = j - 1;
      }
      array[j + 1] = temp;
    }
    //printing the sorted array
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}