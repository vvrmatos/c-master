/* 151-strings-in-c.c - Character arrays with null terminator */
#include <stdio.h>

int main(void) {
    /* String is a char array ending with '\0' */
    char str1[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char str2[] = "World";  /* Compiler adds '\0' automatically */
    
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    
    /* Difference between char array and string */
    char not_a_string[] = {'N', 'o', 'p', 'e'};  /* No '\0'! */
    char is_a_string[] = {'Y', 'e', 's', '\0'};
    
    printf("\nArray with null terminator:\n");
    printf("is_a_string: %s\n", is_a_string);
    
    /* Examining the null terminator */
    printf("\nExamining 'Hello':\n");
    for (int i = 0; i <= 5; i++) {
        printf("str1[%d] = '%c' (ASCII %d)\n", 
               i, str1[i] ? str1[i] : '?', str1[i]);
    }
    
    /* String length vs array size */
    char greeting[] = "Hi";
    printf("\nsizeof(\"Hi\") = %zu (includes '\\0')\n", sizeof(greeting));
    printf("String length = 2 (excludes '\\0')\n");
    
    /* Strings are mutable when declared as arrays */
    char mutable[] = "abc";
    mutable[0] = 'X';
    printf("\nModified string: %s\n", mutable);
    
    return 0;
}
