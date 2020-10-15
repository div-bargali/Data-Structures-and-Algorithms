#include<bits/stdc++.h> 
using namespace std; 

void printArr(int arr[], int n); 

/* Function to generates and prints all sorted arrays from alternate elements of 
'A[i..m-1]' and 'B[j..n-1]' 
If 'flag' is true, then current element is to be included from A otherwise 
from B. 
'len' is the index in output array C[]. We print output array each time 
before including a character from A only if length of output array is 
greater than 0. We try than all possible combinations */
void generateUtil(int A[], int B[], int C[], int i, int j, int m, int n, 
				int len, bool flag) 
{ 
	if (flag) // Include valid element from A 
	{ 
		// Print output if there is at least one 'B' in output array 'C' 
		if (len) 
			printArr(C, len+1); 

		// Recur for all elements of A after current index 
		for (int k = i; k < m; k++) 
		{ 
			if (!len) 
			{ 
				/* this block works for the very first call to include 
					the first element in the output array */
				C[len] = A[k]; 

				// don't increment lem as B is included yet 
				generateUtil(A, B, C, k+1, j, m, n, len, !flag); 
			} 
			else	 /* include valid element from A and recur */
			{ 
				if (A[k] > C[len]) 
				{ 
					C[len+1] = A[k]; 
					generateUtil(A, B, C, k+1, j, m, n, len+1, !flag); 
				} 
			} 
		} 
	} 
	else /* Include valid element from B and recur */
	{ 
		for (int l = j; l < n; l++) 
		{ 
			if (B[l] > C[len]) 
			{ 
				C[len+1] = B[l]; 
				generateUtil(A, B, C, i, l+1, m, n, len+1, !flag); 
			} 
		} 
	} 
} 

/* Wrapper function */
void generate(int A[], int B[], int m, int n) 
{ 
	int C[m+n]; /* output array */
	generateUtil(A, B, C, 0, 0, m, n, 0, true); 
} 

// A utility function to print an array 
void printArr(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver program 
int main() 
{ 
	int A[] = {10, 15, 25}; 
	int B[] = {5, 20, 30}; 
	int n = sizeof(A)/sizeof(A[0]); 
	int m = sizeof(B)/sizeof(B[0]); 
	generate(A, B, n, m); 
	return 0; 
} 
