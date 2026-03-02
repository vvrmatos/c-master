#include <stdio.h>

int main(void) {
    char c = 'A';
    
    printf("=== Character as Integer ===\n\n");
    
    printf("char c = 'A'\n");
    printf("As character: %c\n", c);
    printf("As integer:   %d\n\n", c);
    
    printf("Character arithmetic:\n");
    printf("  'A' + 1 = %d = '%c'\n", 'A' + 1, 'A' + 1);
    printf("  'A' + 25 = %d = '%c'\n", 'A' + 25, 'A' + 25);
    printf("  'a' - 'A' = %d (difference between cases)\n", 'a' - 'A');
    
    printf("\nConvert lowercase to uppercase:\n");
    char lower = 'h';
    char upper = lower - 32;
    printf("  '%c' - 32 = '%c'\n", lower, upper);
    
    printf("\nConvert digit char to actual number:\n");
    char digit = '7';
    int value = digit - '0';
    printf("  '%c' - '0' = %d\n", digit, value);
    
    printf("\nLoop through alphabet:\n");
    printf("  ");
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        printf("%c ", ch);
    }
    printf("\n");
    
    return 0;
}
