/*
 * isalpha and isdigit - letter and digit tests
 * Basic character classification functions
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    printf("=== isalpha - Test for Letters ===\n\n");
    
    // Test isalpha
    printf("isalpha tests:\n");
    printf("  isalpha('A') = %d\n", isalpha('A') ? 1 : 0);
    printf("  isalpha('z') = %d\n", isalpha('z') ? 1 : 0);
    printf("  isalpha('5') = %d\n", isalpha('5') ? 1 : 0);
    printf("  isalpha(' ') = %d\n", isalpha(' ') ? 1 : 0);
    printf("  isalpha('!') = %d\n", isalpha('!') ? 1 : 0);

    printf("\n=== isdigit - Test for Digits ===\n\n");
    
    // Test isdigit
    printf("isdigit tests:\n");
    printf("  isdigit('0') = %d\n", isdigit('0') ? 1 : 0);
    printf("  isdigit('9') = %d\n", isdigit('9') ? 1 : 0);
    printf("  isdigit('a') = %d\n", isdigit('a') ? 1 : 0);
    printf("  isdigit('.') = %d\n", isdigit('.') ? 1 : 0);

    // Practical: Extract only letters from a string
    const char *mixed = "H3ll0 W0r1d!";
    char letters[100] = "";
    int j = 0;
    
    printf("\nExtract letters from \"%s\":\n", mixed);
    for (int i = 0; mixed[i]; i++) {
        if (isalpha(mixed[i])) {
            letters[j++] = mixed[i];
        }
    }
    letters[j] = '\0';
    printf("  Letters only: \"%s\"\n", letters);

    // Practical: Extract only digits
    const char *text = "Order #12345 costs $99.99";
    char digits[100] = "";
    j = 0;
    
    printf("\nExtract digits from \"%s\":\n", text);
    for (int i = 0; text[i]; i++) {
        if (isdigit(text[i])) {
            digits[j++] = text[i];
        }
    }
    digits[j] = '\0';
    printf("  Digits only: \"%s\"\n", digits);

    // Count letters and digits
    const char *sample = "User123 has 42 items.";
    int letter_count = 0, digit_count = 0;
    
    for (int i = 0; sample[i]; i++) {
        if (isalpha(sample[i])) letter_count++;
        if (isdigit(sample[i])) digit_count++;
    }
    printf("\nIn \"%s\":\n", sample);
    printf("  Letters: %d, Digits: %d\n", letter_count, digit_count);

    return 0;
}
