/*
 * Dereference Operator - Using the * operator
 */

#include <stdio.h>

int main(void) {
    int value = 42;
    int *ptr = &value;
    
    printf("The Dereference Operator (*)\n\n");
    
    printf("Setup:\n");
    printf("  int value = 42;\n");
    printf("  int *ptr = &value;\n\n");
    
    printf("Reading through pointer:\n");
    printf("  ptr  = %p (the address)\n", (void*)ptr);
    printf("  *ptr = %d (value at address)\n", *ptr);
    
    printf("\nModifying through pointer:\n");
    printf("  *ptr = 100;\n");
    *ptr = 100;
    printf("  Now value = %d\n", value);
    
    printf("\nDereference chain:\n");
    int **pptr = &ptr;  // Pointer to pointer
    printf("  int **pptr = &ptr;\n");
    printf("  pptr  = %p (address of ptr)\n", (void*)pptr);
    printf("  *pptr = %p (value of ptr, address of value)\n", (void*)*pptr);
    printf("  **pptr = %d (value at address in ptr)\n", **pptr);
    
    // Increment through pointer
    printf("\nIncrementing through pointer:\n");
    printf("  (*ptr)++ changes value from %d to ", value);
    (*ptr)++;
    printf("%d\n", value);
    
    return 0;
}
