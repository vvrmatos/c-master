#include <stdio.h>

int main(void) {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int rows = 3, cols = 4;
    
    printf("Row-by-row iteration:\n");
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            printf("%3d ", matrix[r][c]);
        }
        printf("\n");
    }
    
    printf("\nColumn-by-column iteration:\n");
    for (int c = 0; c < cols; c++) {
        printf("Column %d: ", c);
        for (int r = 0; r < rows; r++) {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }
    
    printf("\nSum all elements:\n");
    int sum = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            sum += matrix[r][c];
        }
    }
    printf("Total: %d\n", sum);
    
    return 0;
}
