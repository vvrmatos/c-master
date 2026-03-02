#include <stdio.h>

int main(void) {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printf("2D array in memory (row-major order):\n\n");
    printf("Logical view:\n");
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 4; c++) {
            printf("%3d ", matrix[r][c]);
        }
        printf("\n");
    }
    
    printf("\nMemory layout (contiguous):\n");
    int *ptr = &matrix[0][0];
    for (int i = 0; i < 12; i++) {
        printf("Address %p: matrix[%d][%d] = %d\n", 
               (void *)(ptr + i), i / 4, i % 4, ptr[i]);
    }
    
    printf("\nFormula: matrix[r][c] is at offset (r * COLS + c)\n");
    printf("Example: matrix[2][1] = offset %d * 4 + %d = %d\n", 
           2, 1, 2 * 4 + 1);
    printf("Value at offset 9: %d\n", ptr[9]);
    
    return 0;
}
