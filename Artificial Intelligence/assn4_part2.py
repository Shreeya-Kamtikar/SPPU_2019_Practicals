def isSafe(row, col, slashCode, backslashCode, rowLookup, slashCodeLookup, backslashCodeLookup):
    if (slashCodeLookup[slashCode[row][col]] or backslashCodeLookup[backslashCode[row][col]] or rowLookup[row]):
        return False
    return True

def solveNQueensUtil(board, col, slashCode, backslashCode, rowLookup, slashCodeLookup, backslashCodeLookup):
    if (col >= len(board)):
        return True
    for i in range(len(board)):
        if (isSafe(i, col, slashCode, backslashCode, rowLookup, slashCodeLookup, backslashCodeLookup)):
            board[i][col] = 1
            rowLookup[i] = True
            slashCodeLookup[slashCode[i][col]] = True
            backslashCodeLookup[backslashCode[i][col]] = True

            if (solveNQueensUtil(board, col + 1, slashCode, backslashCode, rowLookup, slashCodeLookup, backslashCodeLookup)):
                return True

            board[i][col] = 0
            rowLookup[i] = False
            slashCodeLookup[slashCode[i][col]] = False
            backslashCodeLookup[backslashCode[i][col]] = False

    return False

def printSolution(board):
    for i in board:
        print(i)

def solveNQueens():
    num_queens = int(input("Enter the size of the board (N): "))

    board = [[0]*num_queens for _ in range(num_queens)]
    slashCode = [[0]*num_queens for _ in range(num_queens)]
    backslashCode = [[0]*num_queens for _ in range(num_queens)]
    rowLookup = [False] * num_queens

    x = 2 * num_queens - 1
    slashCodeLookup = [False] * x
    backslashCodeLookup = [False] * x

    for rr in range(num_queens):
        for cc in range(num_queens):
            slashCode[rr][cc] = rr + cc
            backslashCode[rr][cc] = rr - cc + num_queens - 1

    if (solveNQueensUtil(board, 0, slashCode, backslashCode, rowLookup, slashCodeLookup, backslashCodeLookup)):
        printSolution(board)
    else:
        print("Solution does not exist")

solveNQueens()
