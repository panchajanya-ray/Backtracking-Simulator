#include <stdio.h>

// Include all module headers
#include "coin_min/coin_min.h"
#include "coin_ways/coin_ways.h"
#include "graph_coloring/graph_coloring.h"
#include "hamiltonian/hamiltonian.h"
#include "knapsack/knapsack.h"
#include "nqueens/nqueens.h"
#include "tsp/tsp.h"

int main() {

    int choice;

    while (1) {

        printf("\n===== BACKTRACKING SIMULATOR =====\n");
        printf("1. N-Queen\n");
        printf("2. Graph Coloring\n");
        printf("3. Hamiltonian Cycle\n");
        printf("4. 0/1 Knapsack\n");
        printf("5. Coin Change (Min Coins)\n");
        printf("6. Coin Change (Total Ways)\n");
        printf("7. Travelling Salesman (TSP)\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                runNQueens();
                break;

            case 2:
                runGraphColoring();
                break;

            case 3:
                runHamiltonian();
                break;

            case 4:
                runKnapsack();
                break;

            case 5:
                runCoinMin();
                break;

            case 6:
                runCoinWays();
                break;

            case 7:
                runTSP();
                break;

            case 0:
                printf("Exiting program\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}