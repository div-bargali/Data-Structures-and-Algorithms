/*
Problem Statement - Given a sequence, find the length of the longest palindromic subsequence in it.

Input - string s = "BBABCBCAB"
Output - BABCBAB

Explanation - BABCBAB” is the longest palindromic subsequence in it. 
“BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence, but not the longest ones.

Pre-requisite - Longest Common Subsequence 
Observation - the  string and it's reverse pattern will have the Longest Common Subsequence as BABCBAB with length 7.
*/

#include<bits/stdc++.h> 
using namespace std; 

//Longest Common Subsequence 
string lcs(string &X, string &Y) 
{ 
	int m = X.length(); 
	int n = Y.length(); 

	int L[m+1][n+1]; //dp  matrix

	for (int i=0; i<=m; i++) 
	{ 
		for (int j=0; j<=n; j++) 
		{ 
			if (i == 0 || j == 0) 
				L[i][j] = 0; 
			else if (X[i-1] == Y[j-1]) 
				L[i][j] = L[i-1][j-1] + 1; 
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]); 
		} 
	} 

	// Following code is used to print LCS 
	int index = L[m][n]; 

	string lcs(index+1, '\0'); 

	// Start from the right-most-bottom-most 
	// corner and one by one store characters 
	// in lcs[] 
	int i = m, j = n; 
	while (i > 0 && j > 0) 
	{ 
		// If current character in X[] and Y 
		// are same, then current character 
		// is part of LCS 
		if (X[i-1] == Y[j-1]) 
		{ 
			// Put current character in result 
			lcs[index-1] = X[i-1]; 
			i--; 
			j--; 

			// reduce values of i, j and index 
			index--; 
		} 

		// If not same, then find the larger of 
		// two and go in the direction of larger 
		// value 
		else if (L[i-1][j] > L[i][j-1]) 
			i--; 
		else
			j--; 
	} 

	return lcs; 
} 

//Longest Palindrome Subsequence
string longestPalSubseq(string &str) 
{ 
	// Find reverse of str 
	string rev = str; 
	reverse(rev.begin(), rev.end()); 

	// Return LCS of str and its reverse 
	return lcs(str, rev); 
} 

/* Driver program to test above function */
int main() 
{ 
	string str ;
  cin>>str;
	cout << longestPalSubseq(str); 
	return 0; 
} 
