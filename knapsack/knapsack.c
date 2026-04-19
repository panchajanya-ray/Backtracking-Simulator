#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "knapsack.h"

#define MAX 20

static int weight[MAX], profit[MAX];
static int include[MAX];
static int bestSet[MAX];

static int n, capacity;
static int maxProfit = 0;
static int step = 0;

static void delay() {
#ifdef _WIN32
    Sleep(300);
#else
    usleep(300000);
#endif
}

static void printState(int level, int currentWeight, int currentProfit) {
    printf("\nStep %d: ", ++step);

    printf("Items: ");
    for (int i = 0; i < level; i++) {
        if (include[i])
            printf("%d ", i);
    }

    printf(" Weight=%d Profit=%d", currentWeight, currentProfit);
    printf("\n");

    delay();
}

static void solve(int level, int currentWeight, int currentProfit) {

    if (currentWeight <= capacity && currentProfit > maxProfit) {
        maxProfit = currentProfit;

        for (int i = 0; i < n; i++)
            bestSet[i] = include[i];
    }

    if (level == n)
        return;

    include[level] = 1;
    printState(level + 1, currentWeight + weight[level], currentProfit + profit[level]);

    if (currentWeight + weight[level] <= capacity) {
        solve(level + 1,
              currentWeight + weight[level],
              currentProfit + profit[level]);
    }

    include[level] = 0;
    printState(level + 1, currentWeight, currentProfit);

    solve(level + 1, currentWeight, currentProfit);
}

void runKnapsack() {

    printf("\n0/1 Knapsack using Backtracking\n");

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter profits:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &profit[i]);

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    maxProfit = 0;
    step = 0;

    for (int i = 0; i < n; i++) {
        include[i] = 0;
        bestSet[i] = 0;
    }

    solve(0, 0, 0);

    printf("\nBest Profit: %d\n", maxProfit);

    printf("Selected items: ");
    for (int i = 0; i < n; i++) {
        if (bestSet[i])
            printf("%d ", i);
    }
    printf("\n");
}