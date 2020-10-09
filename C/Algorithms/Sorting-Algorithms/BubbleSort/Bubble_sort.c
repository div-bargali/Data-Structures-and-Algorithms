//Implementation of Bubble sort in C
#include <stdio.h>
#include <stdlib.h>
#define swap(t, x, y) t z = x; x = y; y = z;
typedef int TYPE;
void bubble_sort(TYPE [], int);
void print_array(TYPE [], int);

int main(){
	TYPE A[] = {4, 5, 3, 2, 11};
	int n = sizeof(A) / sizeof(TYPE);
	
	printf("Unsorted: ");
	print_array(A, n);
	
	printf("Sorted: ");
	bubble_sort(A, n);
	print_array(A, n);
	
	return EXIT_SUCCESS;
}

void bubble_sort(TYPE A[], int n) {
	int i, j, sorted;
	
	for(i = 0; i < n; i++) {
		sorted = 1; 
		
		for(j = 0; j < n - 1; j++) {
			if(A[j] > A[j + 1]) {
				swap(TYPE, A[j], A[j+1]);
				sorted = 0;
			}
		}
		
		if(sorted) break; 
		/*if array is sorted break. 
		This way we have O(n) in best case, instead of always O(n^2)*/
	}
}
void print_array(TYPE A[], int n) {
	int i = 0;
	putchar('[');
	while(i < n) {
		if(i > 0) printf(", ");
		printf("%d", A[i++]); //first A[i] is done then i = i + 1
	}
	puts("]");
}