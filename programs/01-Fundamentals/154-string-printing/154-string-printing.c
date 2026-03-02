/* 154-string-printing.c - printf %s and puts */
#include <stdio.h>

int main(void) {
    char greeting[] = "Hello, World!";
    char name[] = "Alice";
    
    /* printf with %s */
    printf("Using printf %%s:\n");
    printf("  %s\n", greeting);
    printf("  Name: %s\n", name);
    
    /* printf formatting options */
    printf("\nprintf formatting:\n");
    printf("  [%s]\n", name);       /* Normal */
    printf("  [%10s]\n", name);     /* Right-align, width 10 */
    printf("  [%-10s]\n", name);    /* Left-align, width 10 */
    printf("  [%.3s]\n", name);     /* Precision: max 3 chars */
    printf("  [%10.3s]\n", name);   /* Width 10, max 3 chars */
    
    /* puts - simpler, adds newline automatically */
    printf("\nUsing puts:\n");
    puts("  Hello from puts!");
    puts(greeting);
    
    /* fputs - like puts but no automatic newline */
    printf("\nUsing fputs:\n");
    fputs("  Line 1", stdout);
    fputs(" - still line 1\n", stdout);
    fputs("  Line 2\n", stdout);
    
    /* putchar - single character */
    printf("\nUsing putchar:\n  ");
    for (int i = 0; greeting[i] != '\0'; i++) {
        putchar(greeting[i]);
    }
    putchar('\n');
    
    /* Printing special characters */
    printf("\nSpecial characters:\n");
    printf("  Tab:\\tHello\n");
    printf("  Quote: \"Hello\"\n");
    printf("  Backslash: C:\\\\path\n");
    printf("  Percent: 100%%\n");
    
    /* Return values */
    int printf_ret = printf("printf returns: ");
    printf("%d (chars written)\n", printf_ret);
    
    int puts_ret = puts("puts returns 0 on success");
    printf("puts returned: %d\n", puts_ret);
    
    return 0;
}
