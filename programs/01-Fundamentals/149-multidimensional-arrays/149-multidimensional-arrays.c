/* 149-multidimensional-arrays.c - 3D arrays and beyond */
#include <stdio.h>

int main(void) {
    /* 3D array: 2 matrices of 3 rows x 4 columns */
    int cube[2][3][4] = {
        {   /* First 2D slice */
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        },
        {   /* Second 2D slice */
            {13, 14, 15, 16},
            {17, 18, 19, 20},
            {21, 22, 23, 24}
        }
    };
    
    printf("3D Array [2][3][4]:\n");
    for (int i = 0; i < 2; i++) {
        printf("Slice %d:\n", i);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                printf("%3d ", cube[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    /* Memory layout is still contiguous */
    int *ptr = &cube[0][0][0];
    printf("Linear memory access: ");
    for (int i = 0; i < 24; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    
    /* Index formula: cube[i][j][k] = base + i*3*4 + j*4 + k */
    printf("\ncube[1][2][3] = %d\n", cube[1][2][3]);
    printf("Via formula: ptr[1*12 + 2*4 + 3] = %d\n", ptr[1*12 + 2*4 + 3]);
    
    return 0;
}
