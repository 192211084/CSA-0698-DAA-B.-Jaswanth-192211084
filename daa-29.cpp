#include <stdio.h>
#include <limits.h>

#define N 4  // Number of workers/jobs

int costMatrix[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

// Function to calculate the minimum cost
int calculateCost(int assigned[N], int level) {
    int totalCost = 0;
    for (int i = 0; i < level; i++) {
        totalCost += costMatrix[i][assigned[i]];
    }
    return totalCost;
}

// Branch and Bound function to find the minimum assignment cost
void branchAndBound(int assigned[N], int level, int *minCost, int visited[N]) {
    if (level == N) {
        int currentCost = calculateCost(assigned, level);
        if (currentCost < *minCost) {
            *minCost = currentCost;
        }
        return;
    }

    for (int j = 0; j < N; j++) {
        if (!visited[j]) {
            assigned[level] = j;  // Assign job j to worker at level
            visited[j] = 1;       // Mark job j as visited

            int currentCost = calculateCost(assigned, level + 1);
            if (currentCost < *minCost) {
                branchAndBound(assigned, level + 1, minCost, visited);  // Recur
            }

            visited[j] = 0;  // Backtrack: Unmark job j
        }
    }
}

int main() {
    int assigned[N] = {0};   // To store assigned jobs for each worker
    int visited[N] = {0};    // To mark jobs as assigned
    int minCost = INT_MAX;   // Initialize minimum cost as maximum

    branchAndBound(assigned, 0, &minCost, visited);  // Call branch and bound
    printf("The minimum cost is: %d\n", minCost);

    return 0;
}

