/* 
	Edit Distance in Go:

	Given two strings str1 and str2 and below operations that can performed on str1.
	Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.
	1. Insert a character at any index
	2. Remove a character from any index
	3. Replace a character at any index

*/

package main

import (
	"fmt"
)

func main() {
	var str1, str2 string

	// taking first string from user
	fmt.Print("Enter first string : ")
	fmt.Scanln(&str1)

	// taking second string from user
	fmt.Print("Enter second string : ")
	fmt.Scanln(&str2)

	// function EditDistance called
	edit_dis := EditDistance(str1, str2, len(str1), len(str2))
	fmt.Println("Edit Distance = ", edit_dis)
}

// function that returns minimum integer out of three integers
func min(x int, y int, z int) int {
	minxyz := x
	if y < minxyz {
		minxyz = y
	}
	if z < minxyz {
		minxyz = z
	}
	return minxyz
}

// function to calculate edit distance of two strings
func EditDistance (str1 string, str2 string, len1 int, len2 int) int {	
	var dp [1000+1][1000+1]int
	var i, j int
	for i = 0 ; i <= len1 ; i++ {
		for j = 0 ; j <= len2 ; j ++ {
			if i == 0 { // if the first string is empty all characters of second string are inserted
				dp[i][j] = j
			} else if j == 0 { // if the second string is empty all characters of first string are removed
				dp[i][j] = i
			} else if str1[i-1] == str2[j-1] { // if str1[i] equals to str2[i], do nothing
				dp[i][j] = dp[i-1][j-1]
			} else {
				dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) // insertion or removal or replacement
			}
		}
	}
	return dp[len1][len2] 
}

/*
	Sample Output:

	Enter first string : horse
	Enter second string : rose
	Edit Distance =  2

*/