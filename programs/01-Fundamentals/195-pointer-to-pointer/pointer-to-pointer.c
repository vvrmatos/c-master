/*
 * Pointer to Pointer (Double Pointer)
 * A pointer that stores the address of another pointer
 */

#include <stdio.h>

int main(void) {
    int value = 42;
    int *ptr = &value;      // Pointer to int
    int **pptr = &ptr;      // Pointer to pointer to int
    
    printf("value = %d\n", value);
    printf("*ptr = %d\n", *ptr);
    printf("**pptr = %d\n", **pptr);
    
    printf("\nAddresses:\n");
    printf("&value = %p\n", (void *)&value);
    printf("ptr = %p\n", (void *)ptr);
    printf("*pptr = %p\n", (void *)*pptr);
    printf("&ptr = %p\n", (void *)&ptr);
    printf("pptr = %p\n", (void *)pptr);
    
    // Modifying through double pointer
    **pptr = 100;
    printf("\nAfter **pptr = 100:\n");
    printf("value = %d\n", value);
    
    // Changing what ptr points to via pptr
    int other = 999;
    *pptr = &other;
    printf("\nAfter *pptr = &other:\n");
    printf("*ptr = %d\n", *ptr);
    
    return 0;
}
