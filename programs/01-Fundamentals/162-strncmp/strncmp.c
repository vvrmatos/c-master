/*
 * strncmp - bounded string comparison
 * Compares at most n characters of two strings
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *s1 = "Hello, World!";
    const char *s2 = "Hello, Everyone!";
    const char *s3 = "Hello";

    // Compare first 5 characters
    printf("strncmp(\"%s\", \"%s\", 5) = %d\n", s1, s2, strncmp(s1, s2, 5));
    
    // Compare first 7 characters (includes comma and space)
    printf("strncmp(\"%s\", \"%s\", 7) = %d\n", s1, s2, strncmp(s1, s2, 7));
    
    // Compare first 8 characters (difference appears)
    printf("strncmp(\"%s\", \"%s\", 8) = %d\n", s1, s2, strncmp(s1, s2, 8));

    // Prefix checking
    const char *prefix = "Hello";
    if (strncmp(s1, prefix, strlen(prefix)) == 0) {
        printf("\n\"%s\" starts with \"%s\"\n", s1, prefix);
    }

    // Safe comparison with potentially unterminated data
    char buffer[5] = {'H', 'e', 'l', 'l', 'o'};  // No null terminator
    printf("\nstrncmp with fixed buffer: %d\n", strncmp(buffer, s3, 5));

    return 0;
}
