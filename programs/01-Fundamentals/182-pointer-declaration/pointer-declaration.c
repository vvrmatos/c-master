/*
 * Pointer Declaration - Declaring pointers in C
 */

#include <stdio.h>

int main(void) {
    // Different ways to declare pointers
    int *ptr1;      // Preferred style: * with type
    int* ptr2;      // Alternative: * with type name
    int * ptr3;     // Also valid: space on both sides
    
    // Multiple pointer declarations - CAREFUL!
    int *a, *b;     // Both are pointers
    int* c, d;      // TRAP: c is pointer, d is int!
    
    // Initialize with actual variable
    int value = 42;
    int *p = &value;
    
    printf("Pointer Declaration Styles:\n\n");
    printf("int *ptr   - asterisk with variable name (preferred)\n");
    printf("int* ptr   - asterisk with type\n");
    printf("int * ptr  - space on both sides\n");
    
    printf("\nMultiple declaration trap:\n");
    printf("int *a, *b;  - Both pointers\n");
    printf("int* c, d;   - Only c is pointer, d is int!\n");
    
    printf("\nPointer p points to value:\n");
    printf("value = %d\n", value);
    printf("p = %p\n", (void*)p);
    printf("*p = %d\n", *p);
    
    return 0;
}
