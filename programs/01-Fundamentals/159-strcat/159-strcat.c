/* 159-strcat.c - Concatenate strings */
#include <stdio.h>
#include <string.h>

/* Custom strcat implementation */
char *my_strcat(char *dest, const char *src) {
    char *p = dest;
    /* Find end of dest */
    while (*p) p++;
    /* Copy src to end */
    while ((*p++ = *src++) != '\0');
    return dest;
}

int main(void) {
    char buffer[50] = "Hello";
    
    /* Basic strcat usage */
    printf("Before: \"%s\"\n", buffer);
    strcat(buffer, ", ");
    printf("After strcat(\", \"): \"%s\"\n", buffer);
    strcat(buffer, "World!");
    printf("After strcat(\"World!\"): \"%s\"\n\n", buffer);
    
    /* Chaining strcat (returns dest) */
    char chain[50] = "";
    strcat(strcat(strcat(chain, "A"), "B"), "C");
    printf("Chained: \"%s\"\n\n", chain);
    
    /* Custom implementation */
    char custom[50] = "Custom";
    my_strcat(custom, " concatenation");
    printf("my_strcat: \"%s\"\n\n", custom);
    
    /* DANGER: Buffer overflow */
    printf("=== DANGER ===\n");
    char small[10] = "Hello";
    printf("small[10] = \"Hello\" (5 chars + null, 4 bytes free)\n");
    printf("strcat(small, \"World!\") would overflow!\n");
    /* strcat(small, "World!"); // BUFFER OVERFLOW! */
    printf("\"World!\" needs 7 bytes - CRASH or corruption!\n\n");
    
    /* How strcat works internally */
    printf("=== How strcat works ===\n");
    char demo[20] = "ABC";
    printf("Initial: \"%s\" (null at index 3)\n", demo);
    printf("Bytes: ");
    for (int i = 0; i < 7; i++) {
        printf("[%c]", demo[i] ? demo[i] : '0');
    }
    printf("\n");
    
    strcat(demo, "XYZ");
    printf("After strcat(\"XYZ\"): \"%s\"\n", demo);
    printf("Bytes: ");
    for (int i = 0; i < 7; i++) {
        printf("[%c]", demo[i] ? demo[i] : '0');
    }
    printf("\n");
    
    /* Building strings safely */
    printf("\n=== Safe alternative: snprintf ===\n");
    char safe[20];
    snprintf(safe, sizeof(safe), "%s%s%s", "One", "Two", "Three");
    printf("snprintf result: \"%s\"\n", safe);
    
    return 0;
}
