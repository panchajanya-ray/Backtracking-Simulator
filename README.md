# Backtracking Simulator

## Overview

Backtracking Simulator is a menu-driven C project designed to demonstrate classical backtracking algorithms in a structured and interactive way. It allows users to explore how recursive algorithms build solutions step by step and backtrack when constraints are violated.

This project is developed as part of Design and Analysis of Algorithms (DAA) coursework to provide a practical understanding of backtracking techniques.

---

## Features

* Menu-driven interface for easy navigation
* Step-by-step execution of algorithms
* Modular code structure using multiple files
* Covers multiple classical backtracking problems
* Human-readable output with execution delay

---

## Algorithms Covered

The simulator includes the following problems:

1. N-Queen Problem
2. Graph Coloring
3. Hamiltonian Cycle
4. 0/1 Knapsack (Backtracking approach)
5. Coin Change (Minimum Coins)
6. Coin Change (Total Ways)
7. Travelling Salesman Problem (TSP)

---

## Project Structure
~~~
Backtracking-Simulator/
│
├── coin_min/
│   ├── coin_min.c
│   └── coin_min.h
│
├── coin_ways/
│   ├── coin_ways.c
│   └── coin_ways.h
│
├── graph_coloring/
│   ├── graph_coloring.c
│   └── graph_coloring.h
│
├── hamiltonian/
│   ├── hamiltonian.c
│   └── hamiltonian.h
│
├── knapsack/
│   ├── knapsack.c
│   └── knapsack.h
│
├── nqueens/
│   ├── nqueens.c
│   └── nqueens.h
│
├── tsp/
│   ├── tsp.c
│   └── tsp.h
│
├── .gitignore
├── README.md
└── main.c
~~~
---

## Requirements

* GCC Compiler
* C Programming Environment
* Windows / Linux / Mac

---

## How to Compile
~~~
gcc main.c coin_min/coin_min.c coin_ways/coin_ways.c graph_coloring/graph_coloring.c hamiltonian/hamiltonian.c knapsack/knapsack.c nqueens/nqueens.c tsp/tsp.c -o sim
~~~
---

## How to Run

Windows:
sim

Linux/Mac:
./sim

---

## Sample Workflow

1. Run the program
2. Select a problem from the menu
3. Provide required inputs
4. Observe step-by-step execution
5. View final result

---

## Learning Outcomes

* Understanding of backtracking technique
* Visualization of recursion and decision trees
* Knowledge of constraint satisfaction problems
* Practical implementation of DAA concepts

---

## Limitations

* High time complexity for large inputs
* Console-based visualization only
* Not optimized for performance

---

## Future Improvements

* Add graphical user interface
* Include performance comparison
* Add more algorithms
* Optimize using pruning techniques

---

## Author

PANCHAJANYA RAY<br/>
MCA Student | Backend Developer | DSA Learner

---

## License

This project is developed for educational purposes.
