/* 147-variable-length-arrays.c - VLA in C99 */
#include <stdio.h>

void print_matrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    
    int vla[n];  /* VLA - size determined at runtime */
    
    for (int i = 0; i < n; i++) {
        vla[i] = i * i;
    }
    
    printf("VLA contents (size %d):\n", n);
    for (int i = 0; i < n; i++) {
        printf("vla[%d] = %d\n", i, vla[i]);
    }
    
    /* 2D VLA */
    int rows = 3, cols = 4;
    int matrix[rows][cols];
    
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = i * cols + j + 1;
    
    printf("\n2D VLA (%dx%d):\n", rows, cols);
    print_matrix(rows, cols, matrix);
    
    return 0;
}
