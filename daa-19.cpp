#include <stdio.h>
int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    int value[n], weight[n];
    float ratio[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &value[i], &weight[i]);
        ratio[i] = (float)value[i] / weight[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                int tempValue = value[j];
                value[j] = value[j + 1];
                value[j + 1] = tempValue;
                int tempWeight = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tempWeight;
                float tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;
            }
        }
    }
    float totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + weight[i] <= capacity) {
            currentWeight += weight[i];
            totalValue += value[i];
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += value[i] * ((float)remainingWeight / weight[i]);
            break;
        }
    }
    printf("Maximum value in the knapsack = %.2f\n", totalValue);
    return 0;
}
