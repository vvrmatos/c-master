---
id: "036"
title: "String Literals"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - strings
  - literals
  - arrays
difficulty: beginner
source: "C11 Standard Section 6.4.5"
---

# 036 — String Literals

## Concept

String literals are sequences of characters enclosed in double quotes (`"Hello"`). They are stored as arrays of `char` terminated by a null character (`\0`). The null terminator is added automatically by the compiler.

Key characteristics:
- **Double quotes** — `"string"` (single quotes `'c'` are for characters)
- **Null terminated** — `"Hello"` is actually 6 bytes: H, e, l, l, o, \0
- **Type** — array of `char`, decays to `const char*` in most contexts
- **Read-only** — string literals are in read-only memory (undefined behavior if modified)
- **Concatenation** — adjacent literals are joined: `"Hello, " "World!"` → `"Hello, World!"`

Storage options:
```c
char array[] = "Hello";      // Creates modifiable copy on stack
const char *ptr = "Hello";   // Points to read-only literal
```

> **Security Note**: Attempting to modify a string literal causes undefined behavior (often a segfault). Always use `const char*` for string literal pointers. Buffer overflow vulnerabilities often involve misunderstanding string length vs array size.

## Code

```c
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
```

## Output

```
=== String Literals ===

Basic string literals:
  "Hello, World!"
  "" (empty string)
  " " (single space)

String concatenation (adjacent literals):
  "Hello, " "World!" = Hello, World!
  "Line 1\n"
  "Line 2\n" = 
  Line 1
  Line 2

Long string via concatenation:
  This is a very long string that spans multiple lines in the source code but is actually one continuous string.

String storage and null terminator:
  char hello[] = "Hello";
  strlen(hello) = 5
  sizeof(hello) = 6 (includes \0)
  Bytes: 72 101 108 108 111 0 (last is \0)

String pointer vs array:
  char array[] = "Array";     // modifiable copy
  char *pointer = "Pointer";  // points to read-only memory
  sizeof(array) = 6
  sizeof(pointer) = 8 (pointer size, not string)

Raw string content:
  "Tab:\t Newline:\n Quote:\""
  Length: 24

Wide string literals (wchar_t):
  L"Wide string" - for Unicode support

C11 UTF string literals:
  u8"UTF-8 string" - UTF-8 encoded
  u"UTF-16 string" - char16_t
  U"UTF-32 string" - char32_t

String literal memory:
  const char *s1 = "Same";
  const char *s2 = "Same";
  s1 == s2: true (compiler may merge identical strings)
```

## Key Takeaways

- String literals use double quotes and include automatic `\0`
- `strlen()` returns character count (without `\0`)
- `sizeof()` returns total bytes (with `\0`)
- Adjacent string literals are concatenated at compile time
- Use `char[]` for modifiable copy, `const char*` for literal pointer
- String literals are stored in read-only memory

## Challenge

Create a program that demonstrates the difference between `strlen()` and `sizeof()` for various strings. What happens with embedded null characters like `"Hello\0World"`?

## Related

- [[035-escape-sequences]] — Special characters in strings
- [[048-format-specifier-s]] — Printing strings with printf
- [[059-scanf-char-string]] — Reading strings
