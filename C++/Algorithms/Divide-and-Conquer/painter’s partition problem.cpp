// A DP based CPP program for painter's partition problem 
#include <climits> 
#include <iostream> 
using namespace std; 

// function to calculate sum between two indices 
// in array 
int sum(int arr[], int from, int to) 
{ 
	int total = 0; 
	for (int i = from; i <= to; i++) 
		total += arr[i]; 
	return total; 
} 

// bottom up tabular dp 
int findMax(int arr[], int n, int k) 
{ 
	// initialize table 
	int dp[k + 1][n + 1] = { 0 }; 

	// base cases 
	// k=1 
	for (int i = 1; i <= n; i++) 
		dp[1][i] = sum(arr, 0, i - 1); 

	// n=1 
	for (int i = 1; i <= k; i++) 
		dp[i][1] = arr[0]; 

	// 2 to k partitions 
	for (int i = 2; i <= k; i++) { // 2 to n boards 
		for (int j = 2; j <= n; j++) { 

			// track minimum 
			int best = INT_MAX; 

			// i-1 th separator before position arr[p=1..j] 
			for (int p = 1; p <= j; p++) 
				best = min(best, max(dp[i - 1][p], 
							sum(arr, p, j - 1)));	 

			dp[i][j] = best; 
		} 
	} 

	// required 
	return dp[k][n]; 
} 

// driver function 
int main() 
{ 
	int arr[] = { 10, 20, 60, 50, 30, 40 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 3; 
	cout << findMax(arr, n, k) << endl; 
	return 0; 
} 
