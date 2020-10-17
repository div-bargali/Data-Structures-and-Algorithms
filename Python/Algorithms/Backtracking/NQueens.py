# Function to check if generated sequence is valid or not
def isValid(board,rn,cn):
    
    #Column
    for i in range(rn):
        if board[i][cn]=='Q':
            return False

    #Diagonal \
    r=rn
    c=cn
    while r>=0 and c>=0:
        if board[r][c]=='Q':
            return False
        r-=1
        c-=1

    #Diagonal /
    r=rn
    c=cn
    while r>=0 and c<N:
        if board[r][c]=='Q':
            return False
        r-=1
        c+=1

    return True

def backtracker(board,rn):
    # If solution is found then print the board(solution)
    # Row number == N therefore all queens are placed o every row in valid position
    if rn==N:
        print("\n\n\n")
        for i in range(N):
            for j in range(N):
                print(board[i][j], end=' ')
            print()
        return

    for i in range(N):
        # if no two queens threaten each other
        if isValid(board,rn,i):
            # place queen on current square
            board[rn][i]='Q'
            backtracker(board,rn+1)
            # backtrack and remove queen from current square
            board[rn][i]='-'

if __name__ == '__main__':
    N = int(input("Enter size: "))
    board = [['-' for x in range(N)] for y in range(N)]
    backtracker(board,0)
