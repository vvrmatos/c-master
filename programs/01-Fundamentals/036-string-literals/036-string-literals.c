#include <stdio.h>
#include <string.h>

int main(void) {
    printf("=== String Literals ===\n\n");
    
    printf("Basic string literals:\n");
    printf("  \"Hello, World!\"\n");
    printf("  \"\" (empty string)\n");
    printf("  \" \" (single space)\n");
    
    printf("\nString concatenation (adjacent literals):\n");
    printf("  \"Hello, \" \"World!\" = %s\n", "Hello, " "World!");
    printf("  \"Line 1\\n\"\n"
           "  \"Line 2\\n\" = \n"
           "  Line 1\n"
           "  Line 2\n");
    
    char long_string[] = "This is a very long string that "
                         "spans multiple lines in the source code "
                         "but is actually one continuous string.";
    printf("\nLong string via concatenation:\n  %s\n", long_string);
    
    printf("\nString storage and null terminator:\n");
    char hello[] = "Hello";
    printf("  char hello[] = \"Hello\";\n");
    printf("  strlen(hello) = %zu\n", strlen(hello));
    printf("  sizeof(hello) = %zu (includes \\0)\n", sizeof(hello));
    printf("  Bytes: ");
    for (size_t i = 0; i <= strlen(hello); i++) {
        printf("%d ", hello[i]);
    }
    printf("(last is \\0)\n");
    
    printf("\nString pointer vs array:\n");
    char array[] = "Array";
    const char *pointer = "Pointer";
    printf("  char array[] = \"Array\";     // modifiable copy\n");
    printf("  char *pointer = \"Pointer\";  // points to read-only memory\n");
    printf("  sizeof(array) = %zu\n", sizeof(array));
    printf("  sizeof(pointer) = %zu (pointer size, not string)\n", sizeof(pointer));
    
    printf("\nRaw string content:\n");
    char raw[] = "Tab:\t Newline:\n Quote:\"";
    printf("  \"%s\"\n", "Tab:\\t Newline:\\n Quote:\\\"");
    printf("  Length: %zu\n", strlen(raw));
    
    printf("\nWide string literals (wchar_t):\n");
    printf("  L\"Wide string\" - for Unicode support\n");
    
    printf("\nC11 UTF string literals:\n");
    printf("  u8\"UTF-8 string\" - UTF-8 encoded\n");
    printf("  u\"UTF-16 string\" - char16_t\n");
    printf("  U\"UTF-32 string\" - char32_t\n");
    
    printf("\nString literal memory:\n");
    const char *s1 = "Same";
    const char *s2 = "Same";
    printf("  const char *s1 = \"Same\";\n");
    printf("  const char *s2 = \"Same\";\n");
    printf("  s1 == s2: %s (compiler may merge identical strings)\n",
           s1 == s2 ? "true" : "false");
    
    return 0;
}
