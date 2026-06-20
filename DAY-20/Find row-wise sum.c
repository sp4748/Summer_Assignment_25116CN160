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

    printf("\nRow-wise Sum:\n");
    for(i = 0; i < rows; i++) {
        sum = 0;
        for(j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        printf("Sum of Row %d = %d\n", i + 1, sum);
    }

    return 0;
}