#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "graph_coloring.h"

#define MAX 20

static int graph[MAX][MAX];
static int color[MAX];
static int V, M;
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

// Print current coloring
static void printColors() {
    printf("\nStep %d: ", ++step);

    for (int i = 0; i < V; i++) {
        printf("V%d=%d ", i, color[i]);
    }
    printf("\n");

    delay();
}

// Check if safe to assign color
static int isSafe(int node, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[node][i] && color[i] == c)
            return 0;
    }
    return 1;
}

// Backtracking
static void solve(int node) {

    if (node == V) {
        solutionFound = 1;

        printf("\nColoring Found:\n");
        printColors();
        return;
    }

    for (int c = 1; c <= M; c++) {

        if (isSafe(node, c)) {

            color[node] = c;
            printColors();

            solve(node + 1);

            if (solutionFound) return;

            // Backtrack
            color[node] = 0;
            printColors();
        }
    }
}

// Entry function
void runGraphColoring() {

    printf("\n--- Graph Coloring ---\n");

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of colors: ");
    scanf("%d", &M);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Reset
    for (int i = 0; i < V; i++)
        color[i] = 0;

    solutionFound = 0;
    step = 0;

    solve(0);

    if (!solutionFound)
        printf("No solution exists\n");
}