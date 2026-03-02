/* 160-strncat.c - Bounded concatenation */
#include <stdio.h>
#include <string.h>

/* Custom strncat implementation */
char *my_strncat(char *dest, const char *src, size_t n) {
    char *p = dest;
    /* Find end of dest */
    while (*p) p++;
    /* Copy at most n chars from src */
    while (n-- > 0 && *src != '\0') {
        *p++ = *src++;
    }
    /* Always null-terminate (unlike strncpy!) */
    *p = '\0';
    return dest;
}

void print_buffer(const char *label, const char *buf, size_t size) {
    printf("%s: \"", label);
    for (size_t i = 0; i < size; i++) {
        if (buf[i] == '\0') {
            printf("\\0");
            break;
        }
        printf("%c", buf[i]);
    }
    printf("\" [");
    for (size_t i = 0; i < size; i++) {
        if (buf[i] == '\0') printf("0");
        else printf("%c", buf[i]);
        if (i < size - 1) printf("|");
    }
    printf("]\n");
}

int main(void) {
    char dest[20];
    
    /* Basic strncat usage */
    printf("=== Basic strncat ===\n");
    strcpy(dest, "Hello");
    strncat(dest, " World!", 3);  /* Append at most 3 chars */
    printf("strncat(\"Hello\", \" World!\", 3): \"%s\"\n\n", dest);
    
    /* strncat ALWAYS null-terminates (unlike strncpy!) */
    printf("=== strncat always null-terminates ===\n");
    strcpy(dest, "Hi");
    print_buffer("Before", dest, 10);
    strncat(dest, "ABCDEFGHIJ", 5);
    print_buffer("After strncat(..., 5)", dest, 10);
    printf("\n");
    
    /* The n parameter meaning */
    printf("=== Parameter n explained ===\n");
    printf("n = max chars to append from src (not total buffer size!)\n");
    printf("strncat(dest, src, 5) appends UP TO 5 chars from src\n\n");
    
    /* Safe usage pattern */
    printf("=== Safe usage pattern ===\n");
    char buffer[15] = "Hello";
    size_t remaining = sizeof(buffer) - strlen(buffer) - 1;
    printf("Buffer size: %zu, used: %zu, remaining: %zu\n",
           sizeof(buffer), strlen(buffer), remaining);
    strncat(buffer, " World!", remaining);
    printf("Result: \"%s\" (length: %zu)\n\n", buffer, strlen(buffer));
    
    /* Custom implementation */
    printf("=== Custom my_strncat ===\n");
    strcpy(dest, "Test");
    my_strncat(dest, "12345", 3);
    printf("my_strncat(\"Test\", \"12345\", 3): \"%s\"\n\n", dest);
    
    /* Comparison: strcat vs strncat vs snprintf */
    printf("=== Comparison ===\n");
    char s1[20] = "A";
    char s2[20] = "A";
    char s3[20] = "A";
    
    /* strcat - no bounds checking */
    strcat(s1, "BC");
    printf("strcat(s1, \"BC\"): \"%s\"\n", s1);
    
    /* strncat - bounded append */
    strncat(s2, "BCDEFGH", 2);
    printf("strncat(s2, \"BCDEFGH\", 2): \"%s\"\n", s2);
    
    /* snprintf - safest */
    snprintf(s3 + strlen(s3), sizeof(s3) - strlen(s3), "%s", "BC");
    printf("snprintf append: \"%s\"\n", s3);
    
    return 0;
}
