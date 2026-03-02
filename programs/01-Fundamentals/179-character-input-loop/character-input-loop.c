/*
 * Character Input Loop - Processing characters in a loop
 */

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch;
    int letter_count = 0;
    int digit_count = 0;
    int other_count = 0;
    
    printf("Enter text (Ctrl+D to end on Unix, Ctrl+Z on Windows):\n");
    
    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            letter_count++;
        } else if (isdigit(ch)) {
            digit_count++;
        } else if (!isspace(ch)) {
            other_count++;
        }
    }
    
    printf("\nResults:\n");
    printf("Letters: %d\n", letter_count);
    printf("Digits: %d\n", digit_count);
    printf("Other (non-space): %d\n", other_count);
    
    return 0;
}
