def is_safe(board, row, col):
    for i in range(col):
        if board[row][i] == 1:
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    for i, j in zip(range(row, num_queens, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    return True

def solve_n_queens_util(board, col):
    if col >= num_queens:
        return True
    for i in range(num_queens):                       
        if is_safe(board, i, col):
            board[i][col] = 1
            if solve_n_queens_util(board, col + 1):
                return True
        board[i][col] = 0
    return False

def print_board(board):
    for row in board:
        print(row)

num_queens = int(input("Enter the number of queens: "))
board = [[0] * num_queens for _ in range(num_queens)]
if solve_n_queens_util(board, 0):
    print_board(board)
else:
    print("No solution found.")
