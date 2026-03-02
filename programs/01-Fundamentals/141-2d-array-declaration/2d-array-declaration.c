#include <stdio.h>

int main(void) {
    int matrix[3][4];
    
    printf("int matrix[3][4]; declares:\n");
    printf("  - 3 rows\n");
    printf("  - 4 columns\n");
    printf("  - 12 total elements\n\n");
    
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            matrix[row][col] = row * 10 + col;
        }
    }
    
    printf("Matrix contents:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            printf("%3d ", matrix[row][col]);
        }
        printf("\n");
    }
    
    printf("\nTotal size: %zu bytes\n", sizeof(matrix));
    printf("Row size:   %zu bytes\n", sizeof(matrix[0]));
    
    return 0;
}
