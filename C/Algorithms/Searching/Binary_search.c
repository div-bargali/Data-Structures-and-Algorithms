#include<stdio.h>

#define N 10 // SIZE OF ARRAY

int low = 0, high = N-1, mid; // LOW, HIGH AND MID INDEX FOR BINARY SEARCH FUNCTION
int Index = -1; //RETURN VALUE

int Binary_search(int A[], int x) // SEARCH FUNCTION
{
	if(high > low)
	{
		mid = (low + high)/2;
		if(A[mid] == x)
			Index = mid;
		else if(A[mid] < x)
		{
			low = mid+1;
			Index = Binary_search( A, x);
		}
		else 
		{
			high = mid-1;
			Index = Binary_search( A, x);
		}
		return Index;

	}
	else
	{
		return Index;
	}
}

int main()
{
	int A[N] = {2, 5, 8 ,9 ,12, 15 ,23, 29, 35, 37}; // SORTED ARRAY
	int x = 12; // 

	int result = Binary_search( A, x);

	if(result == -1) // IF NOT FOUND
	{
		printf("%d not found\n", x);
	}
	else
	{
		printf("%d is present at index : %d\n", x, result);
	}

	return 0;


}

// OUTPUT OF PROGRAM
// 12 is present at index : 4
