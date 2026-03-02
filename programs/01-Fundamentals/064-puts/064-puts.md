---
id: "064"
title: "puts() - Simple String Output"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - output
  - puts
  - strings
  - stdio
difficulty: beginner
source: "C11 Standard 7.21.7.9"
---

# 064 — puts() - Simple String Output

## Concept

`puts()` writes a string to stdout and appends a newline. It's simpler than printf for basic string output.

**Syntax:**
```c
int puts(const char *str);
```

**Key characteristics:**
- Writes string to stdout
- Automatically adds newline at end
- Returns non-negative on success, EOF on error
- Cannot do formatting (no %d, %s, etc.)

**puts() vs printf():**
| Feature | puts() | printf() |
|---------|--------|----------|
| Auto newline | Yes | No |
| Format specifiers | No | Yes |
| Simplicity | Simpler | More complex |
| Flexibility | Limited | Full |

**puts() vs fputs():**
```c
puts("Hello");           // Writes "Hello\n" to stdout
fputs("Hello", stdout);  // Writes "Hello" to stdout (no newline)
fputs("Hello\n", file);  // Writes to any stream
```

**When to use puts():**
- Simple messages without variables
- When you want automatic newline
- Quick debug output

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== puts() - Simple String Output ===\n\n");
    
    puts("Basic puts() usage - automatic newline!");
    puts("Each puts() call ends with a newline.");
    puts("No need to add \\n at the end.");
    
    printf("\nComparing puts() and printf():\n");
    puts("  This is puts()");
    printf("  This is printf()\n");
    
    printf("\nputs() is simpler but less flexible:\n");
    puts("  puts(): auto newline, no formatting");
    puts("  printf(): manual newline, full formatting");
    
    char message[] = "Hello from a variable!";
    printf("\nOutputting strings:\n");
    puts(message);
    
    char lines[][30] = {
        "First line",
        "Second line",
        "Third line"
    };
    
    printf("\nOutputting multiple lines:\n");
    for (int i = 0; i < 3; i++) {
        puts(lines[i]);
    }
    
    printf("\nputs() return value:\n");
    int result = puts("Testing return value");
    printf("  puts() returned: %d (non-negative = success)\n", result);
    printf("  On error, returns EOF (%d)\n\n", EOF);
    
    printf("puts() vs fputs():\n");
    puts("  puts(): writes to stdout, adds newline");
    puts("  fputs(): writes to any stream, NO auto newline");
    
    printf("\nExample of fputs():\n");
    fputs("  fputs() ", stdout);
    fputs("does not ", stdout);
    fputs("add newlines\n", stdout);
    
    printf("\nWhen to use puts():\n");
    puts("  - Simple messages without formatting");
    puts("  - Output where you want auto-newline");
    puts("  - Slightly simpler than printf for plain strings");
    
    printf("\nWhen to use printf() instead:\n");
    puts("  - Need format specifiers (%d, %s, etc.)");
    puts("  - Don't want automatic newline");
    puts("  - Need precise control over output");
    
    printf("\nMultiple strings on same line:\n");
    printf("Use printf: ");
    printf("%s ", "word1");
    printf("%s ", "word2");
    printf("%s\n", "word3");
    
    printf("Can't do this with puts() easily.\n");
    
    printf("\nEmpty string with puts():\n");
    puts("");
    printf("  (printed empty line above)\n");
    
    return 0;
}
```

## Output

```
=== puts() - Simple String Output ===

Basic puts() usage - automatic newline!
Each puts() call ends with a newline.
No need to add \n at the end.

Comparing puts() and printf():
  This is puts()
  This is printf()

puts() is simpler but less flexible:
  puts(): auto newline, no formatting
  printf(): manual newline, full formatting

Outputting strings:
Hello from a variable!

Outputting multiple lines:
First line
Second line
Third line

puts() return value:
Testing return value
  puts() returned: 21 (non-negative = success)
  On error, returns EOF (-1)

puts() vs fputs():
  puts(): writes to stdout, adds newline
  fputs(): writes to any stream, NO auto newline

Example of fputs():
  fputs() does not add newlines

When to use puts():
  - Simple messages without formatting
  - Output where you want auto-newline
  - Slightly simpler than printf for plain strings

When to use printf() instead:
  - Need format specifiers (%d, %s, etc.)
  - Don't want automatic newline
  - Need precise control over output

Multiple strings on same line:
Use printf: word1 word2 word3
Can't do this with puts() easily.

Empty string with puts():

  (printed empty line above)
```

## Compilation

```bash
gcc 064-puts.c -o 064-puts
./064-puts
```

## Key Takeaways

- `puts()` outputs string with automatic newline
- Simpler than printf for plain strings
- No formatting capability (use printf for that)
- Returns non-negative on success, EOF on error
- `fputs()` is similar but without auto-newline
- Use puts() for simple messages, printf() for formatted output

## Challenge

Write a program that mimics `echo` command using puts() for simple strings and printf() for formatted output.

## Related

- [[062-putchar]] — Single character output
- [[063-fgets]] — Line input (companion to puts)
