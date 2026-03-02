/*
 * strtok - string tokenization
 * Splits string into tokens based on delimiters
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    // strtok modifies the original string, so use a copy
    char str[] = "Hello,World,How,Are,You";
    char *token;

    printf("Original string: %s\n", str);
    printf("Tokens (delimiter ','):\n");

    // First call: pass the string
    token = strtok(str, ",");
    while (token != NULL) {
        printf("  [%s]\n", token);
        // Subsequent calls: pass NULL
        token = strtok(NULL, ",");
    }

    // Multiple delimiters
    char str2[] = "one two;three,four:five";
    printf("\nMultiple delimiters (, ; : space):\n");
    
    token = strtok(str2, " ;,:");
    while (token != NULL) {
        printf("  [%s]\n", token);
        token = strtok(NULL, " ;,:");
    }

    // Parse CSV-like data
    char csv[] = "name,age,city\nJohn,25,NYC\nJane,30,LA";
    printf("\nCSV parsing:\n");
    
    token = strtok(csv, "\n");
    while (token != NULL) {
        printf("Row: %s\n", token);
        token = strtok(NULL, "\n");
    }

    return 0;
}
