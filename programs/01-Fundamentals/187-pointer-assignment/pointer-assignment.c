/*
 * Pointer Assignment - Assigning to and through pointers
 */

#include <stdio.h>

int main(void) {
    int x = 10, y = 20, z = 30;
    int *ptr;
    
    printf("Pointer Assignment:\n\n");
    
    // 1. Assign address to pointer
    printf("1. Assigning address to pointer:\n");
    ptr = &x;
    printf("   ptr = &x; *ptr = %d\n", *ptr);
    ptr = &y;
    printf("   ptr = &y; *ptr = %d\n", *ptr);
    ptr = &z;
    printf("   ptr = &z; *ptr = %d\n\n", *ptr);
    
    // 2. Assign value through pointer
    printf("2. Assigning value through pointer:\n");
    ptr = &x;
    printf("   Before: x = %d\n", x);
    *ptr = 100;
    printf("   *ptr = 100; Now x = %d\n\n", x);
    
    // 3. Copy pointer (both point to same place)
    printf("3. Copying pointers:\n");
    int *ptr1 = &x;
    int *ptr2 = ptr1;  // Copy address
    printf("   ptr1 = &x; ptr2 = ptr1;\n");
    printf("   ptr1 = %p\n", (void*)ptr1);
    printf("   ptr2 = %p (same address)\n", (void*)ptr2);
    printf("   *ptr1 = %d, *ptr2 = %d (same value)\n\n", *ptr1, *ptr2);
    
    // 4. Reassigning pointer changes target
    printf("4. Reassigning pointer:\n");
    printf("   ptr1 and ptr2 both point to x (&x = %p)\n", (void*)&x);
    ptr1 = &y;  // ptr1 now points to y
    printf("   ptr1 = &y;\n");
    printf("   ptr1 = %p (now &y)\n", (void*)ptr1);
    printf("   ptr2 = %p (still &x)\n", (void*)ptr2);
    printf("   *ptr1 = %d, *ptr2 = %d\n", *ptr1, *ptr2);
    
    return 0;
}
