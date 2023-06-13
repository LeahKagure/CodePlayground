# Given an N x N chessboard, place N queens on the board such that no two queens threaten each other.
# A queen can attack horizontally, vertically, or diagonally in any direction. Write a program to find
# one possible arrangement of the queens on the board

N = 4

def printSolution(board):
    for i in range(N):
        for j in range(N):
            print(board[i][j], end=" ")
        print()

def isSafe(board, row, col):
    # Check this row on the left side
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check upper diagonal on the left side
    i, j = row, col
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i -= 1
        j -= 1

    # Check lower diagonal on the left side
    i, j = row, col
    while j >= 0 and i < N:
        if board[i][j] == 1:
            return False
        i += 1
        j -= 1

    return True

def solveNQueensUtil(board, col):
    if col >= N:
        # All queens have been successfully placed
        printSolution(board)
        return True

    # Try placing the queen in each row of the current column
    for i in range(N):
        if isSafe(board, i, col):
            board[i][col] = 1  # Place the queen

            # Recur to place the remaining queens
            if solveNQueensUtil(board, col + 1):
                return True

            # Backtrack and remove the queen if the current placement is not valid
            board[i][col] = 0

    return False  # No valid placement found

def solveNQueens():
    board = [[0] * N for _ in range(N)]

    if not solveNQueensUtil(board, 0):
        print("No solution found.")

solveNQueens()
