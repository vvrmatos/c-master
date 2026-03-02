#include <stdio.h>

int main(void) {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printf("Initialized with nested braces:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            printf("%3d ", matrix[row][col]);
        }
        printf("\n");
    }
    
    int flat[2][3] = {1, 2, 3, 4, 5, 6};
    printf("\nFlat initialization (fills row by row):\n");
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%3d ", flat[row][col]);
        }
        printf("\n");
    }
    
    int partial[3][3] = {{1}, {4}, {7}};
    printf("\nPartial initialization (rest are 0):\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%3d ", partial[row][col]);
        }
        printf("\n");
    }
    
    return 0;
}
