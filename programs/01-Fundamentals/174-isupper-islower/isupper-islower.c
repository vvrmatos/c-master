/*
 * isupper and islower - case tests
 * Test for uppercase and lowercase letters
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    printf("=== isupper - Test for Uppercase ===\n\n");
    
    printf("isupper tests:\n");
    printf("  isupper('A') = %d\n", isupper('A') ? 1 : 0);
    printf("  isupper('Z') = %d\n", isupper('Z') ? 1 : 0);
    printf("  isupper('a') = %d\n", isupper('a') ? 1 : 0);
    printf("  isupper('5') = %d\n", isupper('5') ? 1 : 0);

    printf("\n=== islower - Test for Lowercase ===\n\n");
    
    printf("islower tests:\n");
    printf("  islower('a') = %d\n", islower('a') ? 1 : 0);
    printf("  islower('z') = %d\n", islower('z') ? 1 : 0);
    printf("  islower('A') = %d\n", islower('A') ? 1 : 0);
    printf("  islower('5') = %d\n", islower('5') ? 1 : 0);

    // Count case types
    const char *text = "Hello World! ABC xyz 123";
    int upper = 0, lower = 0, other = 0;
    
    for (int i = 0; text[i]; i++) {
        if (isupper(text[i])) upper++;
        else if (islower(text[i])) lower++;
        else other++;
    }
    printf("\nIn \"%s\":\n", text);
    printf("  Uppercase: %d\n", upper);
    printf("  Lowercase: %d\n", lower);
    printf("  Other: %d\n", other);

    // Check if all uppercase
    const char *allcaps = "HELLO";
    int is_all_upper = 1;
    for (int i = 0; allcaps[i]; i++) {
        if (isalpha(allcaps[i]) && !isupper(allcaps[i])) {
            is_all_upper = 0;
            break;
        }
    }
    printf("\n\"%s\" is all uppercase: %s\n", 
           allcaps, is_all_upper ? "yes" : "no");

    // Check if Title Case
    const char *title = "Hello World";
    int is_title = 1, at_word_start = 1;
    
    for (int i = 0; title[i]; i++) {
        if (isspace(title[i])) {
            at_word_start = 1;
        } else if (isalpha(title[i])) {
            if (at_word_start) {
                if (!isupper(title[i])) is_title = 0;
            } else {
                if (!islower(title[i])) is_title = 0;
            }
            at_word_start = 0;
        }
    }
    printf("\"%s\" is Title Case: %s\n", title, is_title ? "yes" : "no");

    // CamelCase check
    const char *camel = "camelCaseExample";
    int caps_count = 0;
    for (int i = 0; camel[i]; i++) {
        if (isupper(camel[i])) caps_count++;
    }
    printf("\n\"%s\" has %d internal capitals (likely camelCase)\n", 
           camel, caps_count);

    return 0;
}
