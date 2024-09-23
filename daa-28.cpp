#include <stdio.h>

void printFactors(int n, int i) {
    if (i > n)  // Base case: stop when i exceeds n
        return;

    if (n % i == 0)  // If i is a factor of n
        printf("%d ", i);

    printFactors(n, i + 1);  // Recur for the next number
}

int main() {
    int n;
    
    // Input the number
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Factors of %d are: ", n);
    printFactors(n, 1);  // Call the recursive function starting with 1
    printf("\n");

    return 0;
}

