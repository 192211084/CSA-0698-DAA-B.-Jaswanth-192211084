#include <stdio.h>
int main() {
    int n, i, num, min, max;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("The list is empty.\n");
        return 0;
    }
    printf("Enter number 1: ");
    scanf("%d", &num);
    min = max = num;
    for (i = 2; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &num);
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
    }
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
    return 0;
}
