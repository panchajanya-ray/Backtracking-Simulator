#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "coin_ways.h"

#define MAX 20

static int coins[MAX];
static int n, target;

static int totalWays;
static int step;

static void delay() {
#ifdef _WIN32
    Sleep(300);
#else
    usleep(300000);
#endif
}

static void printState(int sum) {
    printf("\nStep %d: Current Sum = %d\n", ++step, sum);
    delay();
}

static void solve(int index, int sum) {

    printState(sum);

    if (sum == target) {
        totalWays++;
        printf("One way found\n");
        return;
    }

    if (sum > target || index == n)
        return;

    solve(index, sum + coins[index]);

    solve(index + 1, sum);
}

void runCoinWays() {

    printf("\nCoin Change Total Ways\n");

    printf("Enter number of coin types: ");
    scanf("%d", &n);

    printf("Enter coin values:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    totalWays = 0;
    step = 0;

    solve(0, 0);

    printf("\nTotal number of ways: %d\n", totalWays);
}