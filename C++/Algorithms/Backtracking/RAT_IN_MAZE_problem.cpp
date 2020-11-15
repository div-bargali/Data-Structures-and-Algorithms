#include<bits/stdc++.h>
using namespace std;

void printSolution(int** solution, int n) {       //if we find out solution then print out full path 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << solution[i][j] << " ";
        }
    }
    cout << endl;
}
void mazeHelp(int maze[][20], int n, int** solution, int x, int y) {       //


    if (x == n - 1 && y == n - 1) {        //when x,y reaches the end of point
        solution[x][y] = 1;
        printSolution(solution, n);
        return;
    }
    if (x >= n || x < 0 || y >= n || y < 0 || maze[x][y] == 0 || solution[x][y] == 1) {    //whether x,y is out of map or coordinate which can be used as a path 
        return;
    }
    solution[x][y] = 1;         //it has been used to solution path
    mazeHelp(maze, n, solution, x - 1, y);
    mazeHelp(maze, n, solution, x + 1, y);
    mazeHelp(maze, n, solution, x, y - 1);
    mazeHelp(maze, n, solution, x, y + 1);
    solution[x][y] = 0;     //backtracking
}


void ratInAMaze(int maze[][20], int n) {
    int** solution = new int* [n];
    for (int i = 0; i < n; i++) {
        solution[i] = new int[n];
    }
    mazeHelp(maze, n, solution, 0, 0);
}



int main() {

    int n;
    cin >> n;       //n representing dimension of the maze
    int maze[20][20];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];        //n space-separated integers representing the type of the cell
        }
    }
    ratInAMaze(maze, n);
}
