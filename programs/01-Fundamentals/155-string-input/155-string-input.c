/* 155-string-input.c - fgets vs scanf %s */
#include <stdio.h>
#include <string.h>

int main(void) {
    char buffer[50];
    
    /* scanf %s - DANGEROUS: stops at whitespace, no bounds checking */
    printf("=== scanf %%s (not recommended) ===\n");
    printf("Enter a word: ");
    scanf("%49s", buffer);  /* %49s limits to 49 chars + null */
    printf("You entered: '%s'\n", buffer);
    
    /* Clear input buffer after scanf */
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    /* fgets - SAFE: reads whole line including spaces */
    printf("\n=== fgets (recommended) ===\n");
    printf("Enter a full line: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        /* fgets keeps the newline - often need to remove it */
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        printf("You entered: '%s'\n", buffer);
    }
    
    /* Demonstrating scanf buffer overflow risk */
    printf("\n=== Why scanf %%s is dangerous ===\n");
    printf("scanf(\"%%s\", buf) with input \"Hello World\":\n");
    printf("  Only reads \"Hello\" (stops at space)\n");
    printf("  Buffer overflow if input > buffer size\n");
    
    /* getchar - single character input */
    printf("\n=== getchar (single char) ===\n");
    printf("Enter a character: ");
    while ((c = getchar()) != '\n' && c != EOF);  /* Clear buffer */
    c = getchar();
    printf("You entered: '%c' (ASCII %d)\n", c, c);
    
    /* Reading multiple strings */
    printf("\n=== Reading with sscanf ===\n");
    char input[] = "Alice 25 Engineer";
    char name[20];
    int age;
    char job[20];
    sscanf(input, "%s %d %s", name, &age, job);
    printf("Parsed: name=%s, age=%d, job=%s\n", name, age, job);
    
    return 0;
}
