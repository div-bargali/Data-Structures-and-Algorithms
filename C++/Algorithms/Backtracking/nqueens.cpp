//Problem Statement: To find an arrangement of N queens on a N*N chess board, such that no queen can attack any other queens on the board

//Input: Value of N

//Output: The solutions to the N-Queens problem as a 2D matrix where 'Q' represents position of queen and '.' represents an empty space

//Note: Queen A can attack Queen B if B is in the same row, colomn or diagonal as A.  

//Sample input/output

/* N = 4
    Output:
    [
        [
            ".Q..",
            "...Q",
            "Q...",
            "..Q."
        ],
        [
            "..Q.",
            "Q...",
            "...Q",
            ".Q.."
        ]
    ]
    Reason: There are only 2 possible ways to place the 4 Queens in the chess board so that they do not attck each other
*/

/* SOLUTION APPROACH:

- We start by placing the queens on by one from the first row to the last
- By the definition of the problem, there should not be more than 2 queens in the same row, same column or same diagonal. 
- Since we have N queens and N rows, we place 1 queen per row from the top. This can also be done by placing 1 queen at a time per column
- We start with the first row and place a Queen in the first safe position. Then we move to the next row and place the 2nd queen in that row in a position that cannot be attacked by the 1st queen. Then place the 3rd queen in the 3rd row such that it cannot be attacked by both the first and the second queens. If the chosen position leads to an attack, back track to find a better position
- By following this approach, we should be able to place the N queens
- Once such a solution is obtained, print it/store it

- This translates to the following step:Check every cell(totally N*N cells), every cell we have two choices: either puts a Q or skip it. Before modifying the cell to Q, we need to check whether putting a Q in this cell is a valid operation, if it is, a DFS starts from the next position.
*/

//This code contains the main functions that perform the task. The soltuion is retured by the helper function as a 2D vector of strings

//Function that is called after N is passed by the user
vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> temp(n, string(n, '.'));
        //A call to the utility function that does the work
        
        //0 here refers to the position of placement. We know that there are N*N valid places for the queen to be placed. So if we number those positions starting from 0, they will range from 0 to (n-1)*(n-1)
        //This way, we are converting a 2D chess board that ranges from 0 to N-1 rows and columns, to a 1D board
        solution(result, temp, 0, n);
        return result;
    }

//Returns true if a postion cannot be attacked by the queens that have already been placed in the prevois rows and columns
bool isSafe(vector<string> &temp, int row, int col) {
        // check if this row can be attacked - Since we place 1 queen per row, there should not be a queen in the row we have chosen. 
        for(int i = 0; i < row; ++i) {
            if(temp[i][col] == 'Q') {
                return false;
            }
        }
        // check if this column can be attacked
        for(int i = 0; i < col; ++i) {
            if(temp[row][i] == 'Q') {
                return false;
            }
        }
        // check if this main diagnoal can be attacked
        int r = row-1, c = col-1;
        while(r >= 0 && c >= 0) {
            if(temp[r--][c--] == 'Q') return false;
        }
        // check if this auxiliary diagonal can be attacked
        r = row-1, c = col+1;
        while(r >= 0 && c < temp.size()) {
            if(temp[r--][c++] == 'Q') return false;
        }

        //No queen can attack at this row and column, so it is safe
        return true;
    }

//utility function
void solution(vector<vector<string>> &result, vector<string> &temp, int pos, int left) {
        int n = temp.size();
        // goal : we have no queens left, all queens are put in a proper position
        if(left == 0) {
            result.push_back(temp);
            return;
        }
        // constrain 1, pos can't be greater than the size of the board
        else if(pos >= n*n) return;
        int row = pos/n, col = pos%n;
        // Check if it is safe to place the queen here 
        if(isSafe(temp, row, col)) {
            temp[row][col] = 'Q';
            solution(result, temp, pos+1, left-1);
            temp[row][col] = '.';
        }
        //Move to the next position
        solution(result, temp, pos+1, left);
    }