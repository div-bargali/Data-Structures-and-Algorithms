 //Only the DP function
int knapsack(int W, int wt[], int val[], int n)
{
    int i,w;
    int K[n+1][W+1];
    for(i=0; i=n; i++)
    for(w=0; w=W; w++)
    {
        if(i==0w==0)
        K[i][w] = 0;
        else if(wt[i-1]=w)
        k[i][w] = max(val[i-1]+K[i-1][w-wt[i-1]], K[i-1][w]);
        else
        K[i][w] = K[i-1][w];
    }
    return K[i][w];
}

/*
/* A recursive implementation of 0-1 Knapsack problem */

#include <bits/stdc++.h> 
using namespace std; 

// A utility function that returns maximum of two integers 
int max(int a, int b) { return (a > b) ? a : b; } 

// Returns the max value that can be put in a capacity of W 
int knapSack(int W, int wt[], int val[], int n) 
{ 

	// Base Condition
	if (n == 0 || W == 0) 
		return 0; 

	// If weight of the nth item is more 
	// than Knapsack capacity W, then 
	// this item cannot be included 
	// in the optimal solution 
	if (wt[n] > W) 
		return knapSack(W, wt, val, n - 1); 

	else
		return max( 
			val[n] + knapSack(W - wt[n], 
									wt, val, n - 1), 
			knapSack(W, wt, val, n - 1)); 
} 

// Driver code 
int main() 
{ 
	int val[] = { 30, 90, 240 }; 
	int wt[] = { 10, 20, 30 }; 
	int W = 60; 
	int n = sizeof(val) / sizeof(val[0]); 
	cout << knapSack(W, wt, val, n); 
	return 0; 
} 

// This code is contributed by Aman
*/
