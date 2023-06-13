// Given an N x N chessboard, place N queens on the board such that no two queens threaten each other.
// A queen can attack horizontally, vertically, or diagonally in any direction. Write a program to find
// one possible arrangement of the queens on the board

#include <stdio.h>

#define N 4

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return 0;
    }

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return 0;
    }

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j])
            return 0;
    }

    return 1;
}

int solveNQueensUtil(int board[N][N], int col) {
    if (col >= N) {
        // All queens have been successfully placed
        printSolution(board);
        return 1;
    }

    // Try placing the queen in each row of the current column
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place the queen

            // Recur to place the remaining queens
            if (solveNQueensUtil(board, col + 1))
                return 1;

            // Backtrack and remove the queen if the current placement is not valid
            board[i][col] = 0;
        }
    }

    return 0; // No valid placement found
}

void solveNQueens() {
    int board[N][N] = {0};

    if (!solveNQueensUtil(board, 0))
        printf("No solution found.\n");
}

int main() {
    solveNQueens();

    return 0;
}
