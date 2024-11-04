#import sys
N = 0

def print_board(board):
    for i in range(N):
        for j in range(N):
            if board[i][j] == 1:
                print(" Q ", end="")
            else:
                print(" _ ", end="")
        print()
    print()

def is_safe(board, row, col):
    for i in range(row):
        if board[i][col] == 1:
            return False
    i, j = row, col
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i -= 1
        j -= 1
    i, j = row, col
    while i >= 0 and j < N:
        if board[i][j] == 1:
            return False
        i -= 1
        j += 1
    return True

def solve_n_queens(board, row):
    if row >= N:
        return True
    for col in range(N):
        if is_safe(board, row, col):
            board[row][col] = 1
            if solve_n_queens(board, row + 1):
                return True
            board[row][col] = 0
    return False


N = int(input("Enter the dimensions of the board: "))
# if N < 4:
#     print("Size of the board should be 4X4 or more!!")
#     sys.exit(1)
board = [[0]*N for _ in range(N)]
r = int(input("Enter the row in which you want to place the Queen: "))
# if r < 0:
#     print("Row value must be greater than or equal to 0!!")
#     sys.exit(1)
c = int(input("Enter the column in which you want to place the Queen: "))
# if c < 0:
#     print("Column value must be greater than or equal to 0!!")
#     sys.exit(1)
board[r][c] = 1
if solve_n_queens(board, 1):
    print_board(board)
else:
    print("No solution exists!!!")