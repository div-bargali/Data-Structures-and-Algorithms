//wave sort in c
#include<stdio.h>
#include<stdlib.h>

//C function to SWAP two reference pointers/values
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//C function to implement WAVE SORT
void sortInWave(int arr[], int n)
{

	//elements are arranged in the order
	//sequence a1 >= a2 <= a3 >= a4 <= a5 >= a6 and so on.
	for (int i = 0; i < n; i += 2)
	{
		if (i > 0 && arr[i - 1] > arr[i] )
			swap(&arr[i], &arr[i - 1]);

		if (i < n - 1 && arr[i] < arr[i + 1] )
			swap(&arr[i], &arr[i + 1]);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	int ar[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &ar[i]);

	sortInWave(ar, n);
	//Time complexity of this algorithm :
	// O(n) time by doing a "single traversal".

	for (int i = 0; i < n; i++)
		printf("%d ", ar[i]);
	printf("\n");

	return 0;
}

/*

Input :

7
10 90 49 2 1 5 23

Output :

90 10 49 1 5 2 23


*/