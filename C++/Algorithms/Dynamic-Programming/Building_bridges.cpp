/*
Consider a 2-D map with a horizontal river passing through its center.
There are n cities on the southern bank with x-coordinates a(1) … a(n) and n cities on the northern bank with x-coordinates b(1) … b(n).
You want to connect as many north-south pairs of cities as possible with bridges such that no two bridges cross. When connecting cities, you can only connect city a(i) 
on the northern bank to city b(i) on the southern bank. Maximum number of bridges that can be built to connect north-south pairs with the aforementioned constraints.

The values in the upper bank can be considered as the northern x-coordinates of the cities and the values in the bottom bank can be considered as the corresponding
southern x-coordinates of the cities to which the northern x-coordinate city can be connected.

Approach: It is a variation of LIS problem. The following are the steps to solve the problem.

-> Sort the north-south pairs on the basis of increasing order of south x-coordinates.
-> If two south x-coordinates are same, then sort on the basis of increasing order of north x-coordinates.
-> Now find the Longest Increasing Subsequence of the north x-coordinates.
-> One thing to note that in the increasing subsequence a value can be greater as well as can be equal to its previous value.
*/



#include <bits/stdc++.h> 
using namespace std; 

// north-south coodinates 
// of each City Pair 
struct CityPairs 
{ 
	int north, south; 
}; 

// comparison function to sort 
// the given set of CityPairs 
bool compare(struct CityPairs a, struct CityPairs b) 
{ 
	if (a.south == b.south) 
		return a.north < b.north; 
	return a.south < b.south; 
} 

// function to find the maximum number 
// of bridges that can be built 
int maxBridges(struct CityPairs values[], int n) 
{ 
	int lis[n]; 
	for (int i=0; i<n; i++) 
		lis[i] = 1; 
		
	sort(values, values+n, compare); 
	
	// logic of longest increasing subsequence 
	// applied on the northern coordinates 
	for (int i=1; i<n; i++) 
		for (int j=0; j<i; j++) 
			if (values[i].north >= values[j].north 
				&& lis[i] < 1 + lis[j]) 
				lis[i] = 1 + lis[j]; 
		
		
	int max = lis[0]; 
	for (int i=1; i<n; i++) 
		if (max < lis[i]) 
			max = lis[i]; 
	
	// required number of bridges 
	// that can be built		 
	return max;		 
} 

// Driver program to test above 
int main() 
{ 
	struct CityPairs values[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}}; 
	int n = 4; 
	cout << "Maximum number of bridges = "
			<< maxBridges(values, n);	 
	return 0; 
} 
