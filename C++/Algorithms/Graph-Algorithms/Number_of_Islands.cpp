/*
Problem link - https://www.geeksforgeeks.org/find-number-of-islands/
Problem Statement - Given a boolean 2D matrix of 0s and 1s , find the number of islands linking all 1s. 

Approach Used - DFS

*/
#include <bits/stdc++.h> 
using namespace std; 

#define ROW 5 
#define COL 5 

int isSafe(int M[][COL], int row, int col, bool visited[][COL]) 
{ 
	return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]); 
  // if matrix go out of bound in left subpart, right subpart, and if the matrix contains 0
} 

void DFS(int M[][COL], int row, int col,bool visited[][COL]) 
{ 
	static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };  // possible directions to move in row
	static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };  // possible directions to move in col

	// Mark this cell as visited 
	visited[row][col] = true; 

	// Recur for all connected neighbours 
	for (int k = 0; k < 8; ++k) 
		if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited)) 
			DFS(M, row + rowNbr[k], col + colNbr[k], visited); 
} 


int countIslands(int M[][COL]) 
{ 

	bool visited[ROW][COL]; 
	memset(visited, 0, sizeof(visited));  // mark initially all unvisited as 0

	int count = 0; //number of islands ( 0- water , 1 - land) 
 	for (int i = 0; i < ROW; ++i) 
		for (int j = 0; j < COL; ++j) 

			// If a cell with value 1 is not 
			if (M[i][j] && !visited[i][j]) { 
				// visited yet, then new island found 
				// Visit all cells in this island. 
				DFS(M, i, j, visited); 

				// and increment island count 
				++count; 
			} 

	return count; 
} 

// Driver code 
int main() 
{ 
	int M[][COL] = {  { 1, 1, 0, 0, 0 }, 
				          	{ 0, 1, 0, 0, 1 }, 
					          { 1, 0, 0, 1, 1 }, 
				          	{ 0, 0, 0, 0, 0 }, 
					          { 1, 0, 1, 0, 1 } 
                 }; 

	cout << "Number of islands is: " << countIslands(M); 

	return 0; 
} 


