/*
 * ctype.h overview - character classification and conversion
 * Functions for testing and converting characters
 */

#include <stdio.h>
#include <ctype.h>

void print_char_info(int c) {
    printf("'%c' (%3d): ", isprint(c) ? c : '?', c);
    
    if (isalpha(c)) printf("alpha ");
    if (isdigit(c)) printf("digit ");
    if (isalnum(c)) printf("alnum ");
    if (isspace(c)) printf("space ");
    if (isupper(c)) printf("upper ");
    if (islower(c)) printf("lower ");
    if (ispunct(c)) printf("punct ");
    if (isprint(c)) printf("print ");
    if (iscntrl(c)) printf("cntrl ");
    if (isxdigit(c)) printf("xdigit ");
    
    printf("\n");
}

int main(void) {
    printf("=== ctype.h Character Classification ===\n\n");

    // Test various characters
    printf("Character analysis:\n");
    print_char_info('A');
    print_char_info('a');
    print_char_info('5');
    print_char_info(' ');
    print_char_info('\t');
    print_char_info('\n');
    print_char_info('!');
    print_char_info('F');   // Hex digit

    // Case conversion
    printf("\nCase conversion:\n");
    printf("  toupper('a') = '%c'\n", toupper('a'));
    printf("  tolower('Z') = '%c'\n", tolower('Z'));
    printf("  toupper('5') = '%c' (unchanged)\n", toupper('5'));

    // Practical example: classify a string
    const char *str = "Hello, World! 123";
    int letters = 0, digits = 0, spaces = 0, punct = 0;
    
    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i])) letters++;
        else if (isdigit(str[i])) digits++;
        else if (isspace(str[i])) spaces++;
        else if (ispunct(str[i])) punct++;
    }
    
    printf("\nString \"%s\":\n", str);
    printf("  Letters: %d\n", letters);
    printf("  Digits: %d\n", digits);
    printf("  Spaces: %d\n", spaces);
    printf("  Punctuation: %d\n", punct);

    return 0;
}
