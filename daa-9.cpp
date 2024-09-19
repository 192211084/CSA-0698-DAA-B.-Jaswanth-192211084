#include <stdio.h>
int main() {
    int firstMatrix[10][10], secondMatrix[10][10], resultMatrix[10][10];
    int row1, col1, row2, col2;
    int i, j, k,count=0;
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &row2, &col2);
    printf("Enter elements of the first matrix:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            scanf("%d", &firstMatrix[i][j]);
        }
    }
    printf("Enter elements of the second matrix:\n");
    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            scanf("%d", &secondMatrix[i][j]);
        }
    }
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            resultMatrix[i][j] = 0;
        }
    }
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            for (k = 0; k < col1; k++) {
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
                count++;
            }
        }
    }
    printf("Resultant Matrix:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\nNumber of operations (multiplications and additions): %d\n", count);
    return 0;
}
