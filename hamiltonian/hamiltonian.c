#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "hamiltonian.h"

#define MAX 20

static int graph[MAX][MAX];
static int path[MAX];
static int V;
static int solutionFound = 0;
static int step = 0;

static void delay() {
#ifdef _WIN32
    Sleep(400);
#else
    usleep(400000);
#endif
}

static void printPath(int pos) {
    printf("\nStep %d: ", ++step);
    for (int i = 0; i < pos; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
    delay();
}

static int isSafe(int v, int pos) {

    if (!graph[path[pos - 1]][v])
        return 0;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;
}

static void solve(int pos) {

    if (pos == V) {
        if (graph[path[pos - 1]][path[0]]) {
            solutionFound = 1;

            printf("\nHamiltonian Cycle Found:\n");
            for (int i = 0; i < V; i++)
                printf("%d ", path[i]);
            printf("%d\n", path[0]);

            return;
        } else {
            return;
        }
    }

    for (int v = 1; v < V; v++) {

        if (isSafe(v, pos)) {

            path[pos] = v;
            printPath(pos + 1);

            solve(pos + 1);

            if (solutionFound)
                return;

            path[pos] = -1;
            printPath(pos);
        }
    }
}

void runHamiltonian() {

    printf("\nHamiltonian Cycle\n");

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < V; i++)
        path[i] = -1;

    solutionFound = 0;
    step = 0;

    path[0] = 0;

    solve(1);

    if (!solutionFound)
        printf("No Hamiltonian Cycle exists\n");
}