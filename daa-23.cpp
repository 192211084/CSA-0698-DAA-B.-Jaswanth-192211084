#include <stdio.h>
#define N 4  // Define the size of the board (4x4)

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

int solveNQUtil(int board[N][N], int col) {
    if (col >= N)  // If all queens are placed
        return 1;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;  // Place queen

            if (solveNQUtil(board, col + 1))  // Recur to place rest of the queens
                return 1;

            board[i][col] = 0;  // Backtrack and remove queen
        }
    }
    return 0;  // No solution found
}

void solveNQ() {
    int board[N][N] = {0};

    if (solveNQUtil(board, 0) == 0) {
        printf("Solution does not exist.\n");
        return;
    }

    printSolution(board);
}

int main() {
    solveNQ();
    return 0;
}

