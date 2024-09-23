#include <stdio.h>
#define MAX 10
int main() {
    int n = 4; 
    int keys[] = {10, 12, 20, 35}; 
    int freq[] = {34, 8, 50, 3};    
    int cost[MAX][MAX] = {0}; 
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            cost[i][j] = 9999;
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += freq[k]; 
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) + ((r < j) ? cost[r + 1][j] : 0) + sum;
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    printf("Cost of Optimal BST: %d\n", cost[0][n - 1]);
    return 0;
}

