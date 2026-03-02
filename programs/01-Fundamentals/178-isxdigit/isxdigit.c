/*
 * isxdigit - Testing hexadecimal digit characters
 */

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char test_chars[] = "0123456789ABCDEFabcdefGHIJxyz";
    
    printf("Testing isxdigit():\n\n");
    
    printf("Testing string: \"%s\"\n\n", test_chars);
    
    printf("Hex digits found: ");
    for (int i = 0; test_chars[i]; i++) {
        if (isxdigit(test_chars[i])) {
            printf("%c ", test_chars[i]);
        }
    }
    printf("\n\n");
    
    // Validate hex string
    char hex_valid[] = "1A3F";
    char hex_invalid[] = "1G3H";
    
    int valid = 1;
    for (int i = 0; hex_valid[i]; i++) {
        if (!isxdigit(hex_valid[i])) {
            valid = 0;
            break;
        }
    }
    printf("\"%s\" is %s hex string\n", hex_valid, valid ? "a valid" : "not a valid");
    
    valid = 1;
    for (int i = 0; hex_invalid[i]; i++) {
        if (!isxdigit(hex_invalid[i])) {
            valid = 0;
            break;
        }
    }
    printf("\"%s\" is %s hex string\n", hex_invalid, valid ? "a valid" : "not a valid");
    
    return 0;
}
