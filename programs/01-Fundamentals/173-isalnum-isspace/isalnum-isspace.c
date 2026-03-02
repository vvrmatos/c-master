/*
 * isalnum and isspace - alphanumeric and whitespace tests
 * Commonly used for parsing and validation
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    printf("=== isalnum - Test for Alphanumeric ===\n\n");
    
    // Test isalnum (letter OR digit)
    printf("isalnum tests:\n");
    printf("  isalnum('A') = %d\n", isalnum('A') ? 1 : 0);
    printf("  isalnum('5') = %d\n", isalnum('5') ? 1 : 0);
    printf("  isalnum('_') = %d\n", isalnum('_') ? 1 : 0);
    printf("  isalnum(' ') = %d\n", isalnum(' ') ? 1 : 0);
    printf("  isalnum('!') = %d\n", isalnum('!') ? 1 : 0);

    printf("\n=== isspace - Test for Whitespace ===\n\n");
    
    // Test isspace
    printf("isspace tests:\n");
    printf("  isspace(' ')  = %d  (space)\n", isspace(' ') ? 1 : 0);
    printf("  isspace('\\t') = %d  (tab)\n", isspace('\t') ? 1 : 0);
    printf("  isspace('\\n') = %d  (newline)\n", isspace('\n') ? 1 : 0);
    printf("  isspace('\\r') = %d  (carriage return)\n", isspace('\r') ? 1 : 0);
    printf("  isspace('\\v') = %d  (vertical tab)\n", isspace('\v') ? 1 : 0);
    printf("  isspace('\\f') = %d  (form feed)\n", isspace('\f') ? 1 : 0);
    printf("  isspace('a')  = %d  (letter)\n", isspace('a') ? 1 : 0);

    // Skip leading whitespace
    const char *padded = "   \t\n  Hello World";
    const char *p = padded;
    while (*p && isspace(*p)) p++;
    printf("\nSkip whitespace: \"%s\" -> \"%s\"\n", padded, p);

    // Trim trailing whitespace
    char str[] = "Hello   \t\n";
    int len = strlen(str);
    while (len > 0 && isspace(str[len - 1])) {
        str[--len] = '\0';
    }
    printf("Trim trailing: becomes \"%s\"\n", str);

    // Word counting using isspace
    const char *text = "The quick brown fox";
    int words = 0;
    int in_word = 0;
    
    for (int i = 0; text[i]; i++) {
        if (isspace(text[i])) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }
    printf("\nWords in \"%s\": %d\n", text, words);

    // Check if valid identifier
    const char *ident = "my_var_123";
    int valid = 1;
    
    // First character must be letter or underscore
    if (!isalpha(ident[0]) && ident[0] != '_') valid = 0;
    
    // Rest must be alphanumeric or underscore
    for (int i = 1; valid && ident[i]; i++) {
        if (!isalnum(ident[i]) && ident[i] != '_') valid = 0;
    }
    printf("\n\"%s\" is %s identifier\n", ident, valid ? "valid" : "invalid");

    return 0;
}
