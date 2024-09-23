#include <stdio.h>
#include <limits.h>
int matrixChainOrder(int p[], int n) {
    int m[n][n];  
    for (int i = 1; i < n; i++)
        m[i][i] = 0;  
    for (int L = 2; L < n; L++) {  
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }
    return m[1][n - 1];  
}
int main() {
    int arr[] = {40, 20, 30, 10, 30}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int optimalCost = matrixChainOrder(arr, n);
    printf("Minimum number of multiplications is: %d\n", optimalCost);
    return 0;
}

