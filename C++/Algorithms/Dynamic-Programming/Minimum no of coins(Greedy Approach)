/*
Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 
*/


// A Naive recursive C++ program to find minimum of coins 
// to make a given change V 
#include<bits/stdc++.h> 
using namespace std; 

// m is size of coins array (number of different coins) 
int minCoins(int coins[], int m, int V) 
{ 
// base case 
if (V == 0) return 0; 

// Initialize result 
int res = INT_MAX; 

// Try every coin that has smaller value than V 
for (int i=0; i<m; i++) 
{ 
	if (coins[i] <= V) 
	{ 
		int sub_res = minCoins(coins, m, V-coins[i]); 

		// Check for INT_MAX to avoid overflow and see if 
		// result can minimized 
		if (sub_res != INT_MAX && sub_res + 1 < res) 
			res = sub_res + 1; 
	} 
} 
return res; 
} 

// Driver program 
int main() 
{ 
	int coins[] = {9, 6, 5, 1}; 
	int m = sizeof(coins)/sizeof(coins[0]); 
	int V = 11; 
	cout << "Minimum coins required is "
		<< minCoins(coins, m, V); 
	return 0; 
} 
