/* 146-arrays-of-arrays.c - Understanding 2D arrays as 1D */
#include <stdio.h>

int main(void) {
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int *ptr = &matrix[0][0];
    
    printf("2D array as contiguous 1D memory:\n");
    for (int i = 0; i < 6; i++) {
        printf("ptr[%d] = %d (address: %p)\n", i, ptr[i], (void*)&ptr[i]);
    }
    
    printf("\nAccessing matrix[1][2] via pointer: %d\n", ptr[1 * 3 + 2]);
    printf("Direct access matrix[1][2]: %d\n", matrix[1][2]);
    
    return 0;
}
