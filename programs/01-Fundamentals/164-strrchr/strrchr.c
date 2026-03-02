/*
 * strrchr - find last character in string
 * Returns pointer to last occurrence of character
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *str = "Hello, World!";
    const char *path = "/home/user/documents/file.txt";
    char *result;

    // Find last 'o'
    result = strrchr(str, 'o');
    if (result) {
        printf("Last 'o' found at position %ld: \"%s\"\n", 
               result - str, result);
    }

    // Compare with strchr
    printf("\nstrchr finds first 'o' at position %ld\n", 
           strchr(str, 'o') - str);
    printf("strrchr finds last 'o' at position %ld\n", 
           strrchr(str, 'o') - str);

    // Extract filename from path
    result = strrchr(path, '/');
    if (result) {
        printf("\nPath: %s\n", path);
        printf("Filename: %s\n", result + 1);
    }

    // Extract file extension
    result = strrchr(path, '.');
    if (result) {
        printf("Extension: %s\n", result + 1);
    }

    // Handle path without extension
    const char *noext = "/home/user/README";
    result = strrchr(noext, '.');
    if (result == NULL) {
        printf("\n%s has no extension\n", noext);
    }

    return 0;
}
