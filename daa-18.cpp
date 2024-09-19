#include <stdio.h>
#include <stdbool.h>
bool isPrime(int num, int div) {
    if (num <= 1) return false;
    if (div == 1) return true;
    if (num % div == 0) return false; 
    return isPrime(num, div - 1); 
}
void printPrimes(int num, int limit) {
    if (num > limit) return; 
    if (isPrime(num, num / 2)) {
        printf("%d ", num); 
    }
    printPrimes(num + 1, limit); 
}
int main() {
    int limit;
    printf("Enter the limit up to which you want to find prime numbers: ");
    scanf("%d", &limit);
    printf("Prime numbers up to %d are:\n", limit);
    printPrimes(2, limit); 
    printf("\n");
    return 0;
}
