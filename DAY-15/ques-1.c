#include <stdio.h>

int main() {
    int m, n;
    printf("Enter number of rows and columns (m n): ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int sum = 0;

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        
            if (i == j) {
                sum += matrix[i][j];
            }
        }
    }

  
    printf(" sum = %d\n", sum);

    return 0;
}