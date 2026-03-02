/* 153-null-terminator.c - The '\0' character */
#include <stdio.h>
#include <string.h>

/* Custom strlen to show how '\0' works */
size_t my_strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int main(void) {
    /* The null terminator character */
    printf("Null terminator facts:\n");
    printf("  '\\0' as int: %d\n", '\0');
    printf("  '\\0' == 0: %s\n", '\0' == 0 ? "true" : "false");
    printf("  sizeof('\\0'): %zu\n", sizeof('\0'));
    
    /* String ends at null terminator */
    char str[] = "Hello\0World";
    printf("\nString \"Hello\\0World\":\n");
    printf("  printf %%s: %s\n", str);
    printf("  strlen: %zu\n", strlen(str));
    printf("  sizeof: %zu\n", sizeof(str));
    
    /* Examining bytes after '\0' */
    printf("\nActual bytes in memory:\n");
    for (size_t i = 0; i < sizeof(str); i++) {
        if (str[i] == '\0')
            printf("  [%zu] '\\0' (0)\n", i);
        else
            printf("  [%zu] '%c' (%d)\n", i, str[i], str[i]);
    }
    
    /* What happens without null terminator */
    printf("\nDanger: array without null terminator:\n");
    char no_null[5] = {'H', 'e', 'l', 'l', 'o'};
    printf("  my_strlen on no_null: ");
    /* This would read past array bounds! */
    /* Demonstrating with safe bounded search */
    int found = 0;
    for (int i = 0; i < 10; i++) {
        if (no_null[i] == '\0') {
            printf("%d (found at index %d)\n", i, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No '\\0' found in first 10 bytes - DANGER!\n");
    }
    
    /* Truncating a string by inserting '\0' */
    char truncate[] = "Hello World";
    printf("\nTruncating string:\n");
    printf("  Before: '%s'\n", truncate);
    truncate[5] = '\0';
    printf("  After truncate[5] = '\\0': '%s'\n", truncate);
    
    return 0;
}
