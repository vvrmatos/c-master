/* 158-strncpy.c - Bounded string copy */
#include <stdio.h>
#include <string.h>

/* Custom strncpy implementation */
char *my_strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    /* Pad with nulls if src shorter than n */
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}

void print_buffer(const char *buf, size_t size) {
    printf("  [");
    for (size_t i = 0; i < size; i++) {
        if (buf[i] == '\0') printf("\\0");
        else printf("%c", buf[i]);
        if (i < size - 1) printf("|");
    }
    printf("]\n");
}

int main(void) {
    char dest[10];
    
    /* Case 1: src shorter than n - pads with nulls */
    printf("Case 1: src shorter than n\n");
    memset(dest, 'X', sizeof(dest));
    strncpy(dest, "Hi", sizeof(dest));
    printf("  strncpy(dest, \"Hi\", 10):\n");
    print_buffer(dest, 10);
    
    /* Case 2: src longer than n - NO null terminator! */
    printf("\nCase 2: src longer than n (DANGER!)\n");
    memset(dest, 'X', sizeof(dest));
    strncpy(dest, "Hello World!", sizeof(dest));
    printf("  strncpy(dest, \"Hello World!\", 10):\n");
    print_buffer(dest, 10);
    printf("  WARNING: No null terminator added!\n");
    
    /* Safe pattern: always null-terminate */
    printf("\nSafe pattern:\n");
    memset(dest, 'X', sizeof(dest));
    strncpy(dest, "Hello World!", sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0';
    printf("  strncpy(dest, src, size-1); dest[size-1]='\\0';\n");
    print_buffer(dest, 10);
    printf("  As string: \"%s\"\n", dest);
    
    /* Case 3: src exactly n chars */
    printf("\nCase 3: src exactly n chars\n");
    char dest5[5];
    strncpy(dest5, "Hello", 5);
    printf("  strncpy(dest5, \"Hello\", 5):\n");
    print_buffer(dest5, 5);
    printf("  WARNING: Also no null terminator!\n");
    
    /* Custom implementation test */
    printf("\nCustom my_strncpy:\n");
    memset(dest, 'X', sizeof(dest));
    my_strncpy(dest, "Test", sizeof(dest));
    print_buffer(dest, 10);
    
    return 0;
}
