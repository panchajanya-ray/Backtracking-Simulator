#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "nqueens.h"

#define MAX 20

static int board[MAX][MAX];
static int N;
static int solutionFound = 0;
static int step = 0;

// Delay function
static void delay() {
#ifdef _WIN32
    Sleep(400);
#else
    usleep(400000);
#endif
}

// Print board
static void printBoard() {
    printf("\nStep: %d\n\n", ++step);

    for (int i = 0; i < N; i++) {

        for (int k = 0; k < N; k++)
            printf("+---");
        printf("+\n");

        for (int j = 0; j < N; j++) {

            printf("|");

            if (board[i][j] == 1)
                printf(" Q ");
            else if ((i + j) % 2 == 0)
                printf("   ");
            else
                printf(" . ");
        }

        printf("|\n");
    }

    for (int k = 0; k < N; k++)
        printf("+---");
    printf("+\n");

    delay();
}

// Safety check
static int isSafe(int row, int col) {

    for (int i = 0; i < row; i++)
        if (board[i][col]) return 0;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return 0;

    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return 0;

    return 1;
}

// Backtracking
static void solve(int row) {

    if (row == N) {
        solutionFound = 1;
        printf("\nSolution Found!\n");
        printBoard();
        return;
    }

    for (int col = 0; col < N; col++) {

        if (isSafe(row, col)) {

            board[row][col] = 1;
            printBoard();

            solve(row + 1);

            if (solutionFound) return;

            board[row][col] = 0; // backtrack
            printBoard();
        }
    }
}

// Entry function
void runNQueens() {

    printf("\n--- N-Queen Problem ---\n");

    printf("Enter value of N (<=20): ");
    scanf("%d", &N);

    if (N < 1 || N > 20) {
        printf("Invalid N\n");
        return;
    }

    // Reset board
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    solutionFound = 0;
    step = 0;

    solve(0);

    if (!solutionFound)
        printf("No solution exists\n");
}