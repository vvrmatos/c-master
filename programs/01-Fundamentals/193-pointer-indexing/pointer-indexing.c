/*
 * Pointer Indexing
 * Using [] operator with pointers
 */

#include <stdio.h>

int main(void) {
    int arr[] = {100, 200, 300, 400, 500};
    int *ptr = arr;
    
    // Indexing with pointer - same as array
    printf("ptr[0] = %d\n", ptr[0]);
    printf("ptr[2] = %d\n", ptr[2]);
    printf("ptr[4] = %d\n", ptr[4]);
    
    // ptr[i] is exactly *(ptr + i)
    printf("\n*(ptr + 1) = %d\n", *(ptr + 1));
    printf("ptr[1] = %d\n", ptr[1]);
    
    // Moving the pointer, then indexing
    ptr = &arr[2];  // ptr now points to 300
    printf("\nAfter ptr = &arr[2]:\n");
    printf("ptr[0] = %d\n", ptr[0]);   // 300
    printf("ptr[-1] = %d\n", ptr[-1]); // 200 (negative index!)
    printf("ptr[2] = %d\n", ptr[2]);   // 500
    
    // Commutative property: a[b] == b[a]
    printf("\n2[arr] = %d (same as arr[2])\n", 2[arr]);
    
    return 0;
}
