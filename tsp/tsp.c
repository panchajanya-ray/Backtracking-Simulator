#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "tsp.h"

#define MAX 20

static int cost[MAX][MAX];
static int visited[MAX];
static int V;

static int minCost;
static int step;

static void delay() {
#ifdef _WIN32
    Sleep(300);
#else
    usleep(300000);
#endif
}

static void printState(int node, int currentCost) {
    printf("\nStep %d: At node %d Cost = %d\n", ++step, node, currentCost);
    delay();
}

static void solve(int current, int count, int currentCost) {

    printState(current, currentCost);

    if (count == V && cost[current][0]) {
        int total = currentCost + cost[current][0];

        if (total < minCost)
            minCost = total;

        printf("Cycle found with cost %d\n", total);
        return;
    }

    for (int i = 0; i < V; i++) {

        if (!visited[i] && cost[current][i]) {

            visited[i] = 1;

            solve(i, count + 1, currentCost + cost[current][i]);

            visited[i] = 0;
        }
    }
}

void runTSP() {

    printf("\nTravelling Salesman Problem\n");

    printf("Enter number of cities: ");
    scanf("%d", &V);

    printf("Enter cost matrix:\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    minCost = 100000;
    step = 0;

    visited[0] = 1;

    solve(0, 1, 0);

    if (minCost == 100000)
        printf("No solution\n");
    else
        printf("\nMinimum cost: %d\n", minCost);
}