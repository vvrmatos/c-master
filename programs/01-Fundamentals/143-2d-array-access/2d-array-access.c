#include <stdio.h>

int main(void) {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printf("Accessing elements with matrix[row][col]:\n\n");
    printf("matrix[0][0] = %d (top-left)\n", matrix[0][0]);
    printf("matrix[0][3] = %d (top-right)\n", matrix[0][3]);
    printf("matrix[2][0] = %d (bottom-left)\n", matrix[2][0]);
    printf("matrix[2][3] = %d (bottom-right)\n", matrix[2][3]);
    printf("matrix[1][2] = %d (middle area)\n", matrix[1][2]);
    
    printf("\nModifying matrix[1][1] from %d to 99\n", matrix[1][1]);
    matrix[1][1] = 99;
    
    printf("\nUpdated matrix:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            printf("%3d ", matrix[row][col]);
        }
        printf("\n");
    }
    
    return 0;
}
