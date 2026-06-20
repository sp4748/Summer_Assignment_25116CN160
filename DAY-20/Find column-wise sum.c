#include <stdio.h>

int main() {
    int rows, cols, i, j;
    int matrix[10][10];
    int sum;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nColumn-wise Sum:\n");

    for(j = 0; j < cols; j++) {
        sum = 0;
        for(i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }
        printf("Sum of Column %d = %d\n", j + 1, sum);
    }

    return 0;
}