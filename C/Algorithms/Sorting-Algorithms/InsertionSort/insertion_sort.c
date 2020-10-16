#include <stdio.h>
#include <stdlib.h>

/* insertion sort function: sorts the given array
   parameters:
      vector: array to be sorted
      n: size of the array to be sorted
*/

int insertion(int vector[], int n) {

  for (size_t i = 1; i < n; i++) {

    int num = vector[i]; // holds the value to be sorted
    int aux = i;         // holds the index

    /* This part does the right shift of the array until num is smaller then the
       last checked value in the array.
    */

    while (aux > 0 && vector[aux - 1] > num) {
      vector[aux] = vector[aux - 1];
      aux = aux - 1;
    }
    /* Insert num in the sorted place after we found it */
    vector[aux] = num;
  }
}

int main() {

  int n; // number of elements needed to be sort.

  // get the size of the array (n).
  printf("Type the number of elements thet you want to sort: ");
  scanf("%d", &n);

  int *vector = malloc(n * sizeof(int)); // allocted the memory necessary to
                                         // hold the max value of the array (n).

  // get the elements from the user
  for (size_t i = 0; i < n; i++) {

    printf("Type the %d element: ", i);
    scanf("%d", &vector[i]);
  }

  printf("The vector you want to sort is:\n");
  for (size_t i = 0; i < n; i++) {

    printf("%d ", vector[i]);
  }
  printf("\n");

  insertion(vector, n);

  printf("The sorted vector is:\n");
  for (size_t i = 0; i < n; i++) {

    printf("%d ", vector[i]);
  }

  printf("\n");
}