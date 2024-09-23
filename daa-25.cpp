#include <stdio.h>

int subset[20]; // To store subset elements
int n, target;

void sumOfSubsets(int set[], int sum, int index) {
    if (sum == target) {  // If subset sum equals the target
        printf("Subset: ");
        for (int i = 0; i < index; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    // If sum exceeds target or no more elements to process
    if (sum > target || index >= n) {
        return;
    }

    // Backtracking steps:
    for (int i = index; i < n; i++) {
        subset[index] = set[i];  // Choose element
        sumOfSubsets(set, sum + set[i], index + 1);  // Recur to next element
    }
}

int main() {
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[20];
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("Subsets with sum %d are:\n", target);
    sumOfSubsets(set, 0, 0);

    return 0;
}

