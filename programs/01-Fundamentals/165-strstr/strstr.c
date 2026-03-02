/*
 * strstr - find substring in string
 * Returns pointer to first occurrence of substring
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *haystack = "The quick brown fox jumps over the lazy dog";
    char *result;

    // Find substring
    result = strstr(haystack, "brown");
    if (result) {
        printf("Found \"brown\" at position %ld\n", result - haystack);
        printf("Rest of string: \"%s\"\n", result);
    }

    // Find word "the" (case-sensitive)
    result = strstr(haystack, "the");
    if (result) {
        printf("\nFound \"the\" at position %ld\n", result - haystack);
    }

    // Substring not found
    result = strstr(haystack, "cat");
    if (result == NULL) {
        printf("\"cat\" not found\n");
    }

    // Count substring occurrences
    const char *text = "abracadabra";
    const char *pattern = "abra";
    int count = 0;
    const char *p = text;
    
    while ((p = strstr(p, pattern)) != NULL) {
        count++;
        p += strlen(pattern);  // Move past found substring
    }
    printf("\n\"%s\" contains \"%s\" %d times\n", text, pattern, count);

    // Empty substring always found at start
    result = strstr(haystack, "");
    printf("\nEmpty string found at position %ld\n", result - haystack);

    return 0;
}
