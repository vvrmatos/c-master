/*
 * String Literals vs Character Arrays
 * Understanding read-only vs modifiable strings
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    // String literal (READ-ONLY, stored in read-only memory)
    const char *literal = "Hello";
    
    // Character array (MODIFIABLE, stored on stack)
    char array[] = "Hello";
    
    // Another array form
    char array2[10] = "Hello";

    printf("String literal: \"%s\" at %p\n", literal, (void*)literal);
    printf("Array: \"%s\" at %p\n", array, (void*)array);

    // Size differences
    printf("\nSize comparison:\n");
    printf("  sizeof(literal) = %zu (pointer size)\n", sizeof(literal));
    printf("  sizeof(array) = %zu (includes null terminator)\n", sizeof(array));
    printf("  sizeof(array2) = %zu (declared size)\n", sizeof(array2));
    printf("  strlen(array) = %zu (string length)\n", strlen(array));

    // Modification
    printf("\nModification:\n");
    array[0] = 'J';
    printf("  Modified array: \"%s\"\n", array);
    
    // literal[0] = 'J';  // CRASH! Undefined behavior - don't do this!
    printf("  Cannot modify literal (would crash)\n");

    // Assignment behavior
    printf("\nAssignment:\n");
    const char *p1 = "Test";
    const char *p2 = "Test";
    printf("  p1 == p2: %s (may share same memory)\n", 
           p1 == p2 ? "true" : "false");
    
    char arr1[] = "Test";
    char arr2[] = "Test";
    printf("  arr1 == arr2: %s (always different memory)\n",
           arr1 == arr2 ? "true" : "false");

    // Reassignment
    literal = "World";  // OK - changing pointer
    printf("\nReassigned pointer: \"%s\"\n", literal);
    
    // array = "World";  // ERROR! Arrays can't be reassigned
    strcpy(array, "World");  // Must use strcpy
    printf("Copied to array: \"%s\"\n", array);

    return 0;
}
