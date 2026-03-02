/*
 * ispunct and isgraph - Testing punctuation and graphical characters
 */

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char test_chars[] = "Hello, World! 123 @#$%";
    
    printf("Testing ispunct() and isgraph():\n\n");
    printf("String: \"%s\"\n\n", test_chars);
    
    printf("Punctuation characters: ");
    for (int i = 0; test_chars[i]; i++) {
        if (ispunct(test_chars[i])) {
            printf("%c ", test_chars[i]);
        }
    }
    printf("\n");
    
    printf("Graphical characters: ");
    for (int i = 0; test_chars[i]; i++) {
        if (isgraph(test_chars[i])) {
            printf("%c ", test_chars[i]);
        }
    }
    printf("\n\n");
    
    printf("All punctuation marks (ASCII 33-126):\n");
    for (int c = 33; c <= 126; c++) {
        if (ispunct(c)) {
            printf("%c ", c);
        }
    }
    printf("\n");
    
    return 0;
}
