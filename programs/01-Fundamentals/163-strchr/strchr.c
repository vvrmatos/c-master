/*
 * strchr - find character in string
 * Returns pointer to first occurrence of character
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *str = "Hello, World!";
    char *result;

    // Find first 'o'
    result = strchr(str, 'o');
    if (result) {
        printf("First 'o' found at position %ld: \"%s\"\n", 
               result - str, result);
    }

    // Find comma
    result = strchr(str, ',');
    if (result) {
        printf("Comma found at position %ld\n", result - str);
    }

    // Find character not in string
    result = strchr(str, 'z');
    if (result == NULL) {
        printf("'z' not found in string\n");
    }

    // Find null terminator (always succeeds)
    result = strchr(str, '\0');
    printf("Null terminator at position %ld\n", result - str);

    // Count occurrences of 'l'
    int count = 0;
    const char *p = str;
    while ((p = strchr(p, 'l')) != NULL) {
        count++;
        p++;  // Move past found character
    }
    printf("Character 'l' appears %d times\n", count);

    return 0;
}
