#include <stdio.h>
int main() {
    int n = 4, W = 7; 
    int wt[] = {1, 3, 4, 5}; 
    int val[] = {1, 4, 5, 7};
    int K[5][8]; 
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = (val[i - 1] + K[i - 1][w - wt[i - 1]] > K[i - 1][w]) ? val[i - 1] + K[i - 1][w - wt[i - 1]] : K[i - 1][w];
            else
                K[i][w] = K[i - 1][w];
        }
    }
    printf("Maximum value: %d\n", K[n][W]);
    return 0;
}

