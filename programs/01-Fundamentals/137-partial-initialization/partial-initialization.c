#include <stdio.h>

int main(void) {
    int arr[5] = {1, 2};
    
    printf("int arr[5] = {1, 2};\n\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    printf("\nZero-initialize all elements:\n");
    int zeros[5] = {0};
    for (int i = 0; i < 5; i++) {
        printf("zeros[%d] = %d\n", i, zeros[i]);
    }
    
    printf("\nPartial char array:\n");
    char chars[4] = {'A', 'B'};
    for (int i = 0; i < 4; i++) {
        printf("chars[%d] = '%c' (%d)\n", i, chars[i], chars[i]);
    }
    
    return 0;
}
