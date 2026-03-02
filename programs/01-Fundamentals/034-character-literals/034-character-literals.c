#include <stdio.h>

int main(void) {
    char letter = 'A';
    char lowercase = 'a';
    char digit = '7';
    char space = ' ';
    char newline = '\n';
    
    printf("=== Character Literals ===\n\n");
    
    printf("Basic character literals:\n");
    printf("  'A' = %c (ASCII %d)\n", letter, letter);
    printf("  'a' = %c (ASCII %d)\n", lowercase, lowercase);
    printf("  '7' = %c (ASCII %d)\n", digit, digit);
    printf("  ' ' = '%c' (ASCII %d)\n", space, space);
    
    printf("\nCharacter arithmetic:\n");
    printf("  'A' + 1 = '%c'\n", 'A' + 1);
    printf("  'a' - 'A' = %d (case difference)\n", 'a' - 'A');
    printf("  '7' - '0' = %d (digit value)\n", '7' - '0');
    printf("  'Z' - 'A' + 1 = %d letters in alphabet\n", 'Z' - 'A' + 1);
    
    printf("\nASCII ranges:\n");
    printf("  '0'-'9' = %d-%d\n", '0', '9');
    printf("  'A'-'Z' = %d-%d\n", 'A', 'Z');
    printf("  'a'-'z' = %d-%d\n", 'a', 'z');
    
    printf("\nSpecial ASCII values:\n");
    printf("  '\\0' (null) = %d\n", '\0');
    printf("  ' ' (space) = %d\n", ' ');
    printf("  '\\n' (newline) = %d\n", '\n');
    printf("  '\\t' (tab) = %d\n", '\t');
    
    printf("\nCharacter vs integer:\n");
    int as_int = 'A';
    char as_char = 65;
    printf("  int x = 'A'; x = %d\n", as_int);
    printf("  char c = 65; c = '%c'\n", as_char);
    
    printf("\nPrintable range:\n");
    printf("  ");
    for (char c = '!'; c <= '~'; c++) {
        printf("%c", c);
    }
    printf("\n");
    
    return 0;
}
