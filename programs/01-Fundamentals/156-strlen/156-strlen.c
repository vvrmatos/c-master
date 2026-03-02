/* 156-strlen.c - String length function */
#include <stdio.h>
#include <string.h>

/* Custom strlen implementation */
size_t my_strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

/* Pointer-based implementation */
size_t my_strlen_ptr(const char *s) {
    const char *p = s;
    while (*p) p++;
    return p - s;
}

int main(void) {
    char str[] = "Hello, World!";
    char empty[] = "";
    char with_null[] = "Hello\0Hidden";
    
    /* Basic strlen usage */
    printf("String: \"%s\"\n", str);
    printf("strlen: %zu\n", strlen(str));
    printf("sizeof: %zu (includes '\\0')\n\n", sizeof(str));
    
    /* Empty string */
    printf("Empty string \"\":\n");
    printf("strlen: %zu\n", strlen(empty));
    printf("sizeof: %zu\n\n", sizeof(empty));
    
    /* String with embedded null */
    printf("String with embedded null \"Hello\\0Hidden\":\n");
    printf("strlen: %zu (stops at first '\\0')\n", strlen(with_null));
    printf("sizeof: %zu (full array including both '\\0')\n\n", sizeof(with_null));
    
    /* Custom implementations */
    printf("Custom strlen implementations:\n");
    printf("my_strlen(\"%s\"): %zu\n", str, my_strlen(str));
    printf("my_strlen_ptr(\"%s\"): %zu\n\n", str, my_strlen_ptr(str));
    
    /* Common pattern: iterate over string */
    printf("Iterating with strlen:\n");
    for (size_t i = 0; i < strlen(str); i++) {  /* Inefficient! */
        printf("%c", str[i]);
    }
    printf("\n");
    
    /* Better pattern: cache length or use pointer */
    printf("Better: cache length or use while(*p++)\n");
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
    
    return 0;
}
