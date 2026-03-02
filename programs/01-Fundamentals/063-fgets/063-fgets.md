---
id: "063"
title: "fgets() - Safe Line Input"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - input
  - fgets
  - strings
  - buffer-safety
difficulty: beginner
source: "C11 Standard 7.21.7.2"
---

# 063 — fgets() - Safe Line Input

## Concept

`fgets()` reads a line from a stream into a buffer. It's the **recommended way** to read strings because it's buffer-overflow safe.

**Syntax:**
```c
char *fgets(char *str, int n, FILE *stream);
```

**Parameters:**
- `str` — Buffer to store input
- `n` — Maximum characters to read (including null terminator)
- `stream` — Input stream (`stdin` for keyboard)

**Key characteristics:**
- Reads at most `n-1` characters
- Stops at newline (included in string) or EOF
- Always null-terminates the string
- Returns NULL on error or EOF with no chars read

**fgets() vs scanf():**
| Feature | fgets() | scanf("%s") |
|---------|---------|-------------|
| Buffer safety | Yes (size limited) | No (can overflow) |
| Reads spaces | Yes | No (stops at space) |
| Includes newline | Yes | No |
| Full lines | Yes | No |

**Removing the newline:**
```c
line[strcspn(line, "\n")] = '\0';
```

> **Best Practice:** Use fgets() for reading strings/lines. It's safer than scanf("%s") and more flexible than gets() (which is removed in C11).

## Code

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    printf("=== fgets() - Safe Line Input ===\n\n");
    
    char line[50];
    
    printf("Enter a line of text: ");
    if (fgets(line, sizeof(line), stdin) != NULL) {
        printf("  You entered: %s", line);
        printf("  Length: %zu\n\n", strlen(line));
    }
    
    printf("fgets() vs scanf() for strings:\n");
    printf("  scanf(\"%%s\"): stops at whitespace, can overflow\n");
    printf("  fgets(): reads whole line, buffer-safe\n\n");
    
    printf("fgets() includes the newline character.\n");
    printf("  Your input ends with: ");
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
        printf("'\\n' (newline)\n\n");
    } else {
        printf("no newline (input truncated)\n\n");
    }
    
    char clean[50];
    printf("Removing the trailing newline:\n");
    printf("  Enter text: ");
    if (fgets(clean, sizeof(clean), stdin) != NULL) {
        clean[strcspn(clean, "\n")] = '\0';
        printf("  Without newline: [%s]\n", clean);
        printf("  Length: %zu\n\n", strlen(clean));
    }
    
    printf("Safe buffer handling:\n");
    char small[10];
    printf("  Buffer size: 10 bytes\n");
    printf("  Enter a long string: ");
    if (fgets(small, sizeof(small), stdin) != NULL) {
        printf("  Got: [%s]\n", small);
        printf("  Length: %zu\n", strlen(small));
        if (strchr(small, '\n') == NULL) {
            printf("  Note: Input was truncated (no newline)\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    }
    printf("\n");
    
    printf("Reading multiple lines:\n");
    char lines[3][50];
    printf("  Enter 3 lines:\n");
    for (int i = 0; i < 3; i++) {
        printf("  [%d]: ", i + 1);
        if (fgets(lines[i], sizeof(lines[i]), stdin) != NULL) {
            lines[i][strcspn(lines[i], "\n")] = '\0';
        }
    }
    printf("\n  You entered:\n");
    for (int i = 0; i < 3; i++) {
        printf("    %d: \"%s\"\n", i + 1, lines[i]);
    }
    
    printf("\nfgets() return value:\n");
    printf("  Success: pointer to buffer\n");
    printf("  EOF/Error: NULL\n");
    printf("  Always check return value!\n");
    
    printf("\nSyntax: fgets(buffer, size, stream)\n");
    printf("  buffer - char array to store input\n");
    printf("  size - maximum bytes to read (including null)\n");
    printf("  stream - input stream (stdin for keyboard)\n");
    
    return 0;
}
```

## Output

```
=== fgets() - Safe Line Input ===

Enter a line of text: Hello World!
  You entered: Hello World!
  Length: 13

fgets() vs scanf() for strings:
  scanf("%s"): stops at whitespace, can overflow
  fgets(): reads whole line, buffer-safe

fgets() includes the newline character.
  Your input ends with: '\n' (newline)

Removing the trailing newline:
  Enter text: Test line
  Without newline: [Test line]
  Length: 9

Safe buffer handling:
  Buffer size: 10 bytes
  Enter a long string: This is a very long string
  Got: [This is a]
  Length: 9
  Note: Input was truncated (no newline)

Reading multiple lines:
  Enter 3 lines:
  [1]: First line
  [2]: Second line
  [3]: Third line

  You entered:
    1: "First line"
    2: "Second line"
    3: "Third line"

fgets() return value:
  Success: pointer to buffer
  EOF/Error: NULL
  Always check return value!

Syntax: fgets(buffer, size, stream)
  buffer - char array to store input
  size - maximum bytes to read (including null)
  stream - input stream (stdin for keyboard)
```

## Compilation

```bash
gcc 063-fgets.c -o 063-fgets
./063-fgets
```

## Key Takeaways

- `fgets()` is the safe way to read strings/lines
- Always specify buffer size to prevent overflow
- Includes newline in output — strip with `strcspn`
- Returns NULL on EOF or error
- Use `sizeof(buffer)` for size parameter
- Preferred over scanf("%s") and deprecated gets()

## Challenge

Write a program that reads a file line by line using fgets() and numbers each line.

## Related

- [[064-puts]] — Simple string output
- [[059-scanf-char-string]] — scanf string input
