/* 152-string-initialization.c - char str[] = "hello"; */
#include <stdio.h>

int main(void) {
    /* Method 1: String literal (most common) */
    char str1[] = "Hello";
    printf("str1[] = \"Hello\": %s (size: %zu)\n", str1, sizeof(str1));
    
    /* Method 2: Character array with explicit chars */
    char str2[] = {'W', 'o', 'r', 'l', 'd', '\0'};
    printf("str2[] = {'W','o','r','l','d','\\0'}: %s\n", str2);
    
    /* Method 3: Fixed size with literal (dangerous if too small!) */
    char str3[10] = "Hi";  /* Remaining chars are '\0' */
    printf("str3[10] = \"Hi\": '%s' (remaining filled with \\0)\n", str3);
    printf("  str3[2] = %d, str3[9] = %d (both zero)\n", str3[2], str3[9]);
    
    /* Method 4: Pointer to string literal (read-only!) */
    const char *str4 = "Constant";
    printf("const char *str4 = \"Constant\": %s\n", str4);
    
    /* Method 5: Empty string */
    char empty[] = "";
    printf("empty[] = \"\": length=%zu, sizeof=%zu\n", 
           (size_t)0, sizeof(empty));  /* sizeof is 1 (just '\0') */
    
    /* Partial initialization */
    char partial[20] = "Part";
    printf("\npartial[20] = \"Part\":\n");
    printf("  Content: '%s'\n", partial);
    printf("  Bytes 0-4: ");
    for (int i = 0; i < 5; i++) printf("%d ", partial[i]);
    printf("\n  Bytes 15-19: ");
    for (int i = 15; i < 20; i++) printf("%d ", partial[i]);
    printf("(all zeros)\n");
    
    /* String array (array of strings) */
    char *words[] = {"one", "two", "three"};
    printf("\nArray of strings:\n");
    for (int i = 0; i < 3; i++) {
        printf("  words[%d] = %s\n", i, words[i]);
    }
    
    return 0;
}
