#include <stdio.h>

int main(void) {
    char letter = 'A';
    char digit = '7';
    char newline = '\n';
    char tab = '\t';
    
    printf("=== Character Type (char) ===\n\n");
    
    printf("char letter = '%c'\n", letter);
    printf("char digit = '%c'\n", digit);
    
    printf("\nCharacters are stored as numbers (ASCII):\n");
    printf("  '%c' = %d\n", letter, letter);
    printf("  '%c' = %d\n", digit, digit);
    printf("  'a' = %d\n", 'a');
    printf("  'z' = %d\n", 'z');
    printf("  '0' = %d\n", '0');
    printf("  '9' = %d\n", '9');
    
    printf("\nSize of char: %zu byte\n", sizeof(char));
    
    printf("\nSpecial characters (escape sequences):\n");
    printf("  \\n = newline%c", newline);
    printf("  \\t = tab%clike this\n", tab);
    printf("  \\\\ = backslash: \\\n");
    printf("  \\' = single quote: \'\n");
    printf("  \\\" = double quote: \"\n");
    
    return 0;
}
