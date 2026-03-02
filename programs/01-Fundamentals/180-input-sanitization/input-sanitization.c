/*
 * Input Sanitization - Cleaning user input
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void sanitize_alpha_only(const char *input, char *output) {
    int j = 0;
    for (int i = 0; input[i]; i++) {
        if (isalpha(input[i])) {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
}

void sanitize_alnum(const char *input, char *output) {
    int j = 0;
    for (int i = 0; input[i]; i++) {
        if (isalnum(input[i]) || input[i] == ' ') {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
}

void sanitize_trim(char *str) {
    int start = 0, end = strlen(str) - 1;
    
    while (isspace(str[start])) start++;
    while (end > start && isspace(str[end])) end--;
    
    int i;
    for (i = 0; start <= end; i++, start++) {
        str[i] = str[start];
    }
    str[i] = '\0';
}

int main(void) {
    char input[] = "  Hello123!@# World456  ";
    char output[100];
    
    printf("Original: \"%s\"\n\n", input);
    
    sanitize_alpha_only(input, output);
    printf("Alpha only: \"%s\"\n", output);
    
    sanitize_alnum(input, output);
    printf("Alphanumeric + space: \"%s\"\n", output);
    
    char trimmed[] = "  Hello123!@# World456  ";
    sanitize_trim(trimmed);
    printf("Trimmed: \"%s\"\n", trimmed);
    
    return 0;
}
