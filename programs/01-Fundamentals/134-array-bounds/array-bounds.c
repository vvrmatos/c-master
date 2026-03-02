#include <stdio.h>

int main(void) {
    int arr[3] = {10, 20, 30};
    
    printf("Valid indices:\n");
    printf("arr[0] = %d\n", arr[0]);
    printf("arr[1] = %d\n", arr[1]);
    printf("arr[2] = %d\n", arr[2]);
    
    printf("\n--- WARNING: Out of bounds access ---\n");
    printf("arr[-1] = %d (undefined behavior!)\n", arr[-1]);
    printf("arr[3]  = %d (undefined behavior!)\n", arr[3]);
    printf("arr[10] = %d (undefined behavior!)\n", arr[10]);
    
    printf("\nC does NOT check array bounds!\n");
    printf("Always ensure: 0 <= index < array_size\n");
    
    return 0;
}
