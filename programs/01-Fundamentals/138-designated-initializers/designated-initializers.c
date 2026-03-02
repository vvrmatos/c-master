#include <stdio.h>

int main(void) {
    int arr[5] = {[2] = 100, [4] = 200};
    
    printf("int arr[5] = {[2] = 100, [4] = 200};\n\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    printf("\nMixed initialization:\n");
    int mixed[6] = {1, 2, [4] = 99, 100};
    for (int i = 0; i < 6; i++) {
        printf("mixed[%d] = %d\n", i, mixed[i]);
    }
    
    printf("\nSkipping elements:\n");
    int sparse[10] = {[0] = 1, [5] = 5, [9] = 9};
    for (int i = 0; i < 10; i++) {
        printf("sparse[%d] = %d\n", i, sparse[i]);
    }
    
    return 0;
}
