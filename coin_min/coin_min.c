#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "coin_min.h"

#define MAX 20

static int coins[MAX];
static int n, target;

static int minCoins;
static int currentCount;
static int step;

static void delay() {
#ifdef _WIN32
    Sleep(300);
#else
    usleep(300000);
#endif
}

static void printState(int sum) {
    printf("\nStep %d: Sum=%d CoinsUsed=%d\n", ++step, sum, currentCount);
    delay();
}

static void solve(int index, int sum) {

    printState(sum);

    if (sum == target) {
        if (currentCount < minCoins)
            minCoins = currentCount;
        return;
    }

    if (sum > target || index == n)
        return;

    currentCount++;
    solve(index, sum + coins[index]);
    currentCount--;

    solve(index + 1, sum);
}

void runCoinMin() {

    printf("\nCoin Change Minimum Coins\n");

    printf("Enter number of coin types: ");
    scanf("%d", &n);

    printf("Enter coin values:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    minCoins = 100000;
    currentCount = 0;
    step = 0;

    solve(0, 0);

    if (minCoins == 100000)
        printf("No solution\n");
    else
        printf("\nMinimum coins required: %d\n", minCoins);
}