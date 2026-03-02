/*
 * toupper and tolower - case conversion
 * Convert characters between uppercase and lowercase
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    printf("=== toupper - Convert to Uppercase ===\n\n");
    
    printf("toupper examples:\n");
    printf("  toupper('a') = '%c'\n", toupper('a'));
    printf("  toupper('z') = '%c'\n", toupper('z'));
    printf("  toupper('A') = '%c' (already upper)\n", toupper('A'));
    printf("  toupper('5') = '%c' (unchanged)\n", toupper('5'));
    printf("  toupper(' ') = '%c' (unchanged)\n", toupper(' '));

    printf("\n=== tolower - Convert to Lowercase ===\n\n");
    
    printf("tolower examples:\n");
    printf("  tolower('A') = '%c'\n", tolower('A'));
    printf("  tolower('Z') = '%c'\n", tolower('Z'));
    printf("  tolower('a') = '%c' (already lower)\n", tolower('a'));
    printf("  tolower('5') = '%c' (unchanged)\n", tolower('5'));

    // Convert string to uppercase
    char str1[] = "Hello, World!";
    printf("\nConvert to uppercase:\n");
    printf("  Original: \"%s\"\n", str1);
    for (int i = 0; str1[i]; i++) {
        str1[i] = toupper(str1[i]);
    }
    printf("  Uppercase: \"%s\"\n", str1);

    // Convert string to lowercase
    char str2[] = "HELLO, WORLD!";
    printf("\nConvert to lowercase:\n");
    printf("  Original: \"%s\"\n", str2);
    for (int i = 0; str2[i]; i++) {
        str2[i] = tolower(str2[i]);
    }
    printf("  Lowercase: \"%s\"\n", str2);

    // Case-insensitive comparison
    const char *s1 = "Hello";
    const char *s2 = "HELLO";
    int equal = 1;
    
    for (int i = 0; s1[i] && s2[i]; i++) {
        if (tolower(s1[i]) != tolower(s2[i])) {
            equal = 0;
            break;
        }
    }
    // Check same length
    if (strlen(s1) != strlen(s2)) equal = 0;
    
    printf("\nCase-insensitive: \"%s\" %s \"%s\"\n", 
           s1, equal ? "==" : "!=", s2);

    // Toggle case
    char str3[] = "Hello World";
    printf("\nToggle case:\n");
    printf("  Original: \"%s\"\n", str3);
    for (int i = 0; str3[i]; i++) {
        if (isupper(str3[i])) {
            str3[i] = tolower(str3[i]);
        } else if (islower(str3[i])) {
            str3[i] = toupper(str3[i]);
        }
    }
    printf("  Toggled: \"%s\"\n", str3);

    return 0;
}
