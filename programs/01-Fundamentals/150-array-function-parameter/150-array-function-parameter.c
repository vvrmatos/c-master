/* 150-array-function-parameter.c - Arrays decay to pointers */
#include <stdio.h>

/* All three declarations are equivalent for 1D arrays */
void print_array1(int arr[], int size) {
    printf("arr[] syntax - sizeof(arr) = %zu (pointer size)\n", sizeof(arr));
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_array2(int *arr, int size) {
    printf("*arr syntax - same as arr[]\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* For 2D arrays, must specify column size */
void print_matrix(int rows, int cols, int matrix[][4]) {
    printf("\n2D array parameter (columns must be specified):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Using pointer to array */
void print_matrix_ptr(int rows, int (*matrix)[4]) {
    printf("\nPointer to array of 4 ints:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("In main: sizeof(arr) = %zu (full array)\n\n", sizeof(arr));
    
    print_array1(arr, size);
    print_array2(arr, size);
    
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    print_matrix(3, 4, matrix);
    print_matrix_ptr(3, matrix);
    
    return 0;
}
