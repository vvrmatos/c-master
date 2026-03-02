/*
 * Pointer Concept - Understanding what pointers are
 */

#include <stdio.h>

int main(void) {
    int value = 42;
    int *ptr = &value;  // ptr stores the ADDRESS of value
    
    printf("Understanding Pointers:\n\n");
    
    printf("Variable 'value':\n");
    printf("  Value: %d\n", value);
    printf("  Address: %p\n", (void*)&value);
    
    printf("\nPointer 'ptr':\n");
    printf("  Contains (address): %p\n", (void*)ptr);
    printf("  Points to value: %d\n", *ptr);
    printf("  Own address: %p\n", (void*)&ptr);
    
    printf("\nKey insight:\n");
    printf("  ptr == &value : %s\n", ptr == &value ? "true" : "false");
    printf("  *ptr == value : %s\n", *ptr == value ? "true" : "false");
    
    // Modifying through pointer
    *ptr = 100;
    printf("\nAfter *ptr = 100:\n");
    printf("  value = %d\n", value);
    
    return 0;
}
