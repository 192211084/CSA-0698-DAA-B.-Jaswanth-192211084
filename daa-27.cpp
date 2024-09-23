#include <stdio.h>

int main() {
    int n, capacity, totalWeight = 0;

    // Input number of containers
    printf("Enter the number of containers: ");
    scanf("%d", &n);

    int weights[n];

    // Input the weight of each container
    printf("Enter the weights of the containers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    // Input the capacity of the container ship
    printf("Enter the capacity of the ship: ");
    scanf("%d", &capacity);

    printf("Loading containers:\n");

    // Greedily load the containers as long as totalWeight <= capacity
    for (int i = 0; i < n; i++) {
        if (totalWeight + weights[i] <= capacity) {
            totalWeight += weights[i];
            printf("Loaded container %d (weight: %d)\n", i + 1, weights[i]);
        } else {
            printf("Cannot load container %d (weight: %d), exceeding capacity!\n", i + 1, weights[i]);
            break;
        }
    }

    printf("Total weight loaded: %d\n", totalWeight);
    
    return 0;
}

