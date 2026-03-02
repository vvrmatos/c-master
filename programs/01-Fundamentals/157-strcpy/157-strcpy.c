/* 157-strcpy.c - Copy strings */
#include <stdio.h>
#include <string.h>

/* Custom strcpy implementation */
char *my_strcpy(char *dest, const char *src) {
    char *original_dest = dest;
    while ((*dest++ = *src++) != '\0');
    return original_dest;
}

int main(void) {
    char source[] = "Hello, World!";
    char dest[50];
    
    /* Basic strcpy usage */
    strcpy(dest, source);
    printf("Source: \"%s\"\n", source);
    printf("After strcpy: \"%s\"\n\n", dest);
    
    /* strcpy returns destination pointer */
    char buffer[100];
    printf("Chained: \"%s\"\n", strcpy(buffer, "Copied!"));
    
    /* Copying string literals */
    char greeting[20];
    strcpy(greeting, "Hi there!");
    printf("From literal: \"%s\"\n\n", greeting);
    
    /* Custom implementation */
    char custom_dest[50];
    my_strcpy(custom_dest, "Custom copy works!");
    printf("my_strcpy result: \"%s\"\n\n", custom_dest);
    
    /* DANGER: Buffer overflow */
    printf("=== DANGER ZONE ===\n");
    char small[5];
    /* strcpy(small, "This is way too long!"); // BUFFER OVERFLOW! */
    printf("strcpy has NO bounds checking!\n");
    printf("If dest is too small, memory corruption occurs.\n");
    printf("Use strncpy or snprintf instead.\n\n");
    
    /* What strcpy actually does */
    printf("=== How strcpy works ===\n");
    char demo_src[] = "ABC";
    char demo_dest[10] = "XXXXXXXXX";
    printf("Before: dest = \"%s\"\n", demo_dest);
    strcpy(demo_dest, demo_src);
    printf("After:  dest = \"%s\"\n", demo_dest);
    printf("Bytes:  ");
    for (int i = 0; i < 10; i++) {
        printf("%c(%d) ", demo_dest[i] ? demo_dest[i] : '?', demo_dest[i]);
    }
    printf("\n");
    
    return 0;
}
