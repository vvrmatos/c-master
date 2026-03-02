---
id: "061"
title: "getchar() - Single Character Input"
category: "01-Fundamentals"
tags:
  - c
  - fundamentals
  - input
  - getchar
  - characters
  - stdio
difficulty: beginner
source: "C11 Standard 7.21.7.6"
---

# 061 — getchar() - Single Character Input

## Concept

`getchar()` reads a single character from stdin. It's the simplest input function and is ideal for character-by-character processing.

**Syntax:**
```c
int ch = getchar();  // Note: returns int, not char!
```

**Why int, not char?**
- Must distinguish valid characters (0-255) from EOF
- EOF is typically -1, outside valid char range
- If char was unsigned, couldn't detect EOF
- Always use `int` for getchar() result

**Key characteristics:**
- Reads one character at a time
- Includes whitespace (space, tab, newline)
- Input is line-buffered (waits for Enter)
- Returns EOF on end-of-file or error

**Common patterns:**
```c
// Read until newline
while ((ch = getchar()) != '\n' && ch != EOF) {
    // process ch
}

// Read until EOF
while ((ch = getchar()) != EOF) {
    // process ch
}
```

**EOF:**
- End Of File marker
- Defined in `<stdio.h>` (usually -1)
- Keyboard: Ctrl+D (Unix) or Ctrl+Z (Windows)

## Code

```c
#include <stdio.h>

int main(void) {
    printf("=== getchar() - Single Character Input ===\n\n");
    
    int ch;
    
    printf("Enter a character: ");
    ch = getchar();
    printf("  You entered: '%c' (ASCII: %d)\n\n", ch, ch);
    
    while (getchar() != '\n');
    
    printf("getchar() returns int, not char!\n");
    printf("  Reason: Must be able to return EOF (-1)\n");
    printf("  EOF constant is typically -1\n\n");
    
    printf("Processing characters until newline:\n");
    printf("  Enter a line: ");
    int count = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        printf("  [%d] '%c' (ASCII %d)\n", count++, ch, ch);
    }
    printf("  Total: %d characters\n\n", count);
    
    printf("Counting character types:\n");
    printf("  Enter text (press Enter when done): ");
    int letters = 0, digits = 0, spaces = 0, other = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            letters++;
        } else if (ch >= '0' && ch <= '9') {
            digits++;
        } else if (ch == ' ' || ch == '\t') {
            spaces++;
        } else {
            other++;
        }
    }
    printf("  Letters: %d\n", letters);
    printf("  Digits: %d\n", digits);
    printf("  Spaces: %d\n", spaces);
    printf("  Other: %d\n\n", other);
    
    printf("Character conversion example:\n");
    printf("  Enter lowercase letters (Enter to stop): ");
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            printf("  '%c' -> '%c'\n", ch, ch - 32);
        } else {
            printf("  '%c' (not lowercase)\n", ch);
        }
    }
    
    printf("\ngetchar() vs scanf(\" %%c\"):\n");
    printf("  getchar(): reads ANY character including whitespace\n");
    printf("  scanf(\" %%c\"): skips leading whitespace\n");
    printf("  getchar(): returns int (can detect EOF)\n");
    printf("  Use getchar() for character-by-character processing\n");
    
    return 0;
}
```

## Output

```
=== getchar() - Single Character Input ===

Enter a character: A
  You entered: 'A' (ASCII: 65)

getchar() returns int, not char!
  Reason: Must be able to return EOF (-1)
  EOF constant is typically -1

Processing characters until newline:
  Enter a line: Hello
  [0] 'H' (ASCII 72)
  [1] 'e' (ASCII 101)
  [2] 'l' (ASCII 108)
  [3] 'l' (ASCII 108)
  [4] 'o' (ASCII 111)
  Total: 5 characters

Counting character types:
  Enter text (press Enter when done): Hello World 2024!
  Letters: 10
  Digits: 4
  Spaces: 2
  Other: 1

Character conversion example:
  Enter lowercase letters (Enter to stop): hello
  'h' -> 'H'
  'e' -> 'E'
  'l' -> 'L'
  'l' -> 'L'
  'o' -> 'O'

getchar() vs scanf(" %c"):
  getchar(): reads ANY character including whitespace
  scanf(" %c"): skips leading whitespace
  getchar(): returns int (can detect EOF)
  Use getchar() for character-by-character processing
```

## Compilation

```bash
gcc 061-getchar.c -o 061-getchar
./061-getchar
```

## Key Takeaways

- `getchar()` reads one character from stdin
- Returns `int`, not `char` (to handle EOF)
- Reads whitespace characters too
- Input is typically line-buffered
- Check for both `'\n'` and `EOF` in loops
- Use for character-by-character text processing

## Challenge

Write a program that counts words, lines, and characters in input (like the `wc` command).

## Related

- [[062-putchar]] — Single character output
- [[065-input-buffer-issues]] — Input buffer problems
