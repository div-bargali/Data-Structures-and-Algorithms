//accessing the array elements

#include <stdio.h>
 
int main () {

   int capacity; //aray size user input
   
   printf("Enter the array Size");
   scanf("%d",&capacity);
   int n[ capacity ]; /* n is an array of 10 integers */
   int i,j;
 
   /* initialize elements of array n to 0 */         
   for ( i = 0; i < capacity; i++ ) {
      n[ i ] = i + 100; /* set element at location i to i + 100 */
   }
   
   /* output each array element's value */
   for (j = 0; j < capacity; j++ ) {
      printf("Element[%d] = %d\n", j, n[j] );
   }
 
   return 0;
}
